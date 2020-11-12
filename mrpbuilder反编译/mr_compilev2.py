# uncompyle6 version 3.7.4
# Python bytecode 2.3 (62011)
# Decompiled from: Python 2.7.16 (default, Oct 10 2019, 22:02:15) 
# [GCC 8.3.0]
# Embedded file name: mr_compilev2.pyo
# Compiled at: 2009-12-07 15:15:23
import sys, re, mr, getopt, time, string
re_single_line_long_comment = re.compile('^(.*)/\\*.*\\*/(.*)')
re_single_comment = re.compile('^(.*)//.*')
re_comment_start = re.compile('^(.*)/\\*(.*)')
re_comment_start_without_tailed = re.compile('^(.*)/\\*.*')
re_comment_end = re.compile('^.*\\*\\/(.*)')
re_ifdef = re.compile('^\\s*#ifdef\\s+([a-zA-Z_][a-zA-Z_0-9]*)\\s+(.*)')
re_ifelse = re.compile('^\\s*#else\\s*')
re_ifend = re.compile('^\\s*#endif\\s*')
re_number = re.compile('^\\s*#number\\s+([a-zA-Z_][a-zA-Z_0-9]*)\\s+(.*)')
re_define = re.compile('^\\s*#define\\s+([a-zA-Z_][a-zA-Z_0-9]*)\\s+(.*)')
re_include1 = re.compile("^\\s*#include\\s*['](.*)[']")
re_include2 = re.compile('^\\s*#include\\s*["](.*)["]')

def infoprint(s):
    print s


def set_compile_info(filename, fileline):
    global complie_fileline
    global complie_filename
    complie_filename = filename
    complie_fileline = fileline


def compile_infoprint(s):
    print complie_filename + ' ' + str(complie_fileline) + ':' + s


def debuginfo(s):
    global DEBUG_MOD
    if DEBUG_MOD:
        print s


def extractFilename(filename):
    if string.rfind(filename, '\\') == -1:
        return filename[string.rfind(filename, '/') + 1:]
    else:
        return filename[string.rfind(filename, '\\') + 1:]


def scan_lines(lines, flag):
    global complie_fileline
    global complie_filename
    long_comment_level = 0
    state = ''
    ifdef_level = 0
    ifdef_state = 'true'
    ifdef_true_level = 0
    for n in range(0, len(lines)):
        complie_fileline = flag[n][1]
        complie_filename = flag[n][0]
        line = ''
        for ch in lines[n]:
            if ch == '\n':
                line = line + ch
                continue
            if long_comment_level > 0:
                if state == '':
                    if ch == '*':
                        state = '*'
                    elif ch == '/':
                        state = '/'
                    line = line + ' '
                elif state == '/':
                    if ch == '*':
                        long_comment_level = long_comment_level + 1
                        state = ''
                    else:
                        state = ''
                elif state == '*':
                    if ch == '/':
                        long_comment_level = long_comment_level - 1
                        state = ''
                    elif ch == '*':
                        state = '*'
                    else:
                        state = ''
                    line = line + ' '
            elif state == '':
                if ch == '[':
                    state = '['
                    line = line + ch
                elif ch == '"':
                    state = '"'
                    line = line + ch
                elif ch == "'":
                    state = "'"
                    line = line + ch
                elif ch == '/':
                    state = '/'
                else:
                    line = line + ch
            elif state == '[':
                if ch == '[':
                    state = '[['
                    line = line + ch
                else:
                    state = ''
                    line = line + ch
            elif state == '/':
                if ch == '/':
                    state = '//'
                elif ch == '*':
                    long_comment_level = long_comment_level + 1
                    state = ''
                else:
                    state = ''
                    line = line + '/' + ch
            elif state == '"':
                if ch == '"':
                    state = ''
                    line = line + ch
                else:
                    line = line + ch
            elif state == "'":
                if ch == "'":
                    state = ''
                    line = line + ch
                else:
                    line = line + ch
            elif state == '//':
                pass
            elif state == '[[':
                if ch == ']':
                    state = '[[]'
                    line = line + ch
                else:
                    line = line + ch
            elif state == '[[]':
                if ch == ']':
                    state = ''
                    line = line + ch
                else:
                    state = '[['
                    line = line + ch
            else:
                debuginfo('state err!state = ' + state)
                raise ''

        if long_comment_level > 0:
            state = ''
        elif state == '[[' or state == '[[]':
            state = '[['
        else:
            (line, ifdef_level, ifdef_state, ifdef_true_level) = doifdef(line, ifdef_level, ifdef_state, ifdef_true_level)
            if ifdef_state == 'true':
                line = dopreprocess(line)
                line = dodefine(line)
                line = donumber(line)
            else:
                line = '//' + line
            state = ''
        lines[n] = line
        line = ''


def doifdef(line, ifdef_level, ifdef_state, ifdef_true_level):
    global re_ifdef
    global re_ifelse
    global re_ifend
    if ifdef_state == 'true':
        ifdef = re_ifdef.match(line)
        if ifdef != None:
            line = '//' + line
            k = ifdef.group(1)
            ifdef_level = ifdef_level + 1
            if define_map.has_key(k):
                ifdef_true_level = ifdef_level
            else:
                ifdef_state = 'false'
        sub_def = re_ifelse.match(line)
        if sub_def != None:
            line = '//' + line
            if ifdef_level == 0:
                compile_infoprint('met #else without #ifdef')
                raise ''
            else:
                ifdef_true_level = ifdef_true_level - 1
            ifdef_state = 'false'
        sub_def = re_ifend.match(line)
        if sub_def != None:
            line = '//' + line
            if ifdef_level == 0:
                compile_infoprint('met #endif without #ifdef')
                raise ''
            else:
                ifdef_level = ifdef_level - 1
                ifdef_true_level = ifdef_level
    elif ifdef_state == 'false':
        ifdef = re_ifdef.match(line)
        if ifdef != None:
            line = '//' + line
            k = ifdef.group(1)
            ifdef_level = ifdef_level + 1
            if define_map.has_key(k):
                pass
            else:
                ifdef_state = 'false'
        sub_def = re_ifelse.match(line)
        if sub_def != None:
            line = '//' + line
            if ifdef_level == 0:
                compile_infoprint('met #else without #ifdef')
                raise ''
            elif ifdef_level - 1 == ifdef_true_level:
                ifdef_state = 'true'
                ifdef_true_level = ifdef_level
        sub_def = re_ifend.match(line)
        if sub_def != None:
            line = '//' + line
            if ifdef_level == 0:
                compile_infoprint('met #endif without #ifdef')
                raise ''
            else:
                ifdef_level = ifdef_level - 1
                if ifdef_level == ifdef_true_level:
                    ifdef_state = 'true'
                    ifdef_true_level = ifdef_level
    debuginfo(line + ';ifdef_true_level=' + str(ifdef_true_level) + ';ifdef_state=' + ifdef_state + ';ifdef_level=' + str(ifdef_level))
    return (line, ifdef_level, ifdef_state, ifdef_true_level)
    return


def donumber(line):
    global re_number
    define = re_number.match(line)
    if define != None:
        k = define.group(1)
        v = str(int(eval(define.group(2))))
        if define_map.has_key(k):
            compile_infoprint('warnning:' + k + ' redefine!old define ' + define_map[k] + ';new define ' + v)
        define_map[k] = v
        line = '//' + line
    return line
    return


def dodefine(line):
    global re_define
    define = re_define.match(line)
    if define != None:
        k = define.group(1)
        v = string.strip(define.group(2))
        if define_map.has_key(k):
            compile_infoprint('warnning:' + k + ' redefine!old define ' + define_map[k] + ';new define ' + v)
        define_map[k] = v
        line = '//' + line
    return line
    return


def get_file_lines(filename):
    lines = []
    try:
        f = file(filename, 'r')
        try:
            lines = f.readlines()
        finally:
            f.close()
    except:
        compile_infoprint("no such file or directory: '" + filename + "'")
        raise

    lines[len(lines) - 1] = lines[(len(lines) - 1)] + '\n'
    return lines


def include_insert_file(filename, lines_insert, flag):
    lines = get_file_lines(filename)
    for n in range(0, len(lines)):
        line = lines[n]
        lines_insert.append(line)
        flag.append((filename, n + 1))


def doinclude_insert(lines, filename):
    global complie_fileline
    global complie_filename
    global re_include1
    global re_include2
    (lines_insert, flag) = ([], [])
    for n in range(0, len(lines)):
        line = lines[n]
        flag.append((filename, n + 1))
        complie_fileline = n + 1
        complie_filename = filename
        include = re_include1.match(line)
        if include != None:
            lines_insert.append('//' + line)
            include_insert_file(include.group(1), lines_insert, flag)
            continue
        include = re_include2.match(line)
        if include != None:
            lines_insert.append('//' + line)
            include_insert_file(include.group(1), lines_insert, flag)
            continue
        lines_insert.append(line)

    return (
     lines_insert, flag)
    return


def doinclude_remove(lines_insert, flag, filename):
    lines = []
    for n in range(0, len(flag)):
        if flag[n][0] == filename:
            lines.append(lines_insert[n])

    return lines


def write_file(name, str):
    f = file(name, 'w')
    try:
        f.write(str)
    finally:
        f.close()


def logtime(s):
    debuginfo(s + ' time:' + str(time.time() - init_time))


def clearline():
    global line_str
    line_str = ''


def pushch(ch):
    global line_str
    line_str = line_str + ch


def getline():
    return line_str


def pushidentifier(identifier):
    global line_str
    if identifier in define_map.keys():
        line_str = line_str + define_map[identifier]
    else:
        line_str = line_str + identifier


identifier_begin = string.ascii_lowercase + string.ascii_uppercase + '_'
identifier_next = string.ascii_lowercase + string.ascii_uppercase + '_' + string.digits

def dopreprocess(s):
    global identifier_begin
    global identifier_next
    clearline()
    state = 0
    identifier = ''
    for ch in s:
        if state == 0:
            if ch in identifier_begin:
                identifier = ch
                state = 1
                continue
            else:
                pushch(ch)
                continue
        elif state == 1:
            if ch in identifier_next:
                identifier = identifier + ch
            else:
                pushidentifier(identifier)
                pushch(ch)
                state = 0

    return getline()


def complie(filename, lines, is_string=False):
    global WITHOUT_DEFINE_MOD
    global complie_fileline
    global complie_filename
    global init_time
    complie_filename = filename
    complie_fileline = 0
    if is_string:
        init_time = time.time()
        text = lines
    else:
        init_time = time.time()
        logtime('logtime')
        (lines, flag) = doinclude_insert(lines, extractFilename(filename))
        logtime('doinclude_insert')
        if not WITHOUT_DEFINE_MOD:
            scan_lines(lines, flag)
        if DEBUG_MOD:
            text = ''
            for line in lines:
                text = text + line

            write_file('pre_define_' + extractFilename(filename), text)
        logtime('remove_comment')
        logtime('for')
        lines = doinclude_remove(lines, flag, extractFilename(filename))
        logtime('doinclude_remove')
        text = ''
        for line in lines:
            text = text + line

        if DEBUG_MOD:
            write_file('pre_' + extractFilename(filename), text)
        try:
            data = mr.compile(text, extractFilename(filename))
        except RuntimeError, info:
            infoprint(info)
            sys.exit(1)
        except:
            infoprint('unknow err!')
            sys.exit(1)

    logtime('compile')
    return data


def compilefile(filename, outputfilename):
    set_compile_info(filename, 0)
    lines = get_file_lines(filename)
    data = complie(filename, lines)
    f = file(outputfilename, 'wb')
    f.write(data)
    f.close()


help_info = '\n  MiniJ\xb1\xe0\xd2\xeb\xb9\xa4\xbe\xdfV1.91\n  \xca\xb9\xd3\xc3\xc0\xfd\n  mr_compilev2.exe dsm.mr dsm.mrc -dMTK_MOD -dMAN=LONGCHI\n  \xb2\xce\xca\xfd\xcb\xb5\xc3\xf7\n  -d \xba\xea\xb1\xe4\xc1\xbf[=value]           \xb6\xa8\xd2\xe5\xba\xea\xa3\xbb\n  -h           \xb0\xef\xd6\xfa\xa3\xbb\n  \xb7\xb5\xbb\xd8\xc0\xe0\xd0\xcd\xa3\xba\n  0     \xc9\xfa\xb3\xc9\xb3\xc9\xb9\xa6\xa1\xa3\n  <0    \xca\xa7\xb0\xdc\xa3\xac\xbe\xdf\xcc\xe5\xca\xa7\xb0\xdc\xb1\xe0\xc2\xeb\xb4\xfd\xb6\xa8\xd2\xe5\xa1\xa3\n'

def usage():
    global help_info
    infoprint(help_info)


def main():
    global DEBUG_MOD
    init_compile()
    try:
        (opts, args) = getopt.getopt(sys.argv[2:], 'd:ho:', ['define=', 'mythroadtestmode', 'sdkmode', 'help', 'output'])
    except getopt.GetoptError:
        usage()
        sys.exit(-1)

    debuginfo(opts)
    for (o, a) in opts:
        if o in ('-h', '--help'):
            usage()
            sys.exit(0)
        if o in ('-o', '--output'):
            output = a
        if o in ('', '--mythroadtestmode'):
            DEBUG_MOD = True
        if o in ('-d', '--define'):
            debuginfo(a)
            macro_set = a.split('=', 1)
            if len(macro_set) < 2:
                SetDefine(macro_set[0], '$$MR_COMMAND_LINE_DEFINE$$')
            else:
                SetDefine(macro_set[0], macro_set[1])
            debuginfo('macro_set:')
            debuginfo(str(macro_set))

    compilefile(sys.argv[1], output)


def SetDefine(name, value):
    define_map[name] = value


DEBUG_MOD = False
WITHOUT_DEFINE_MOD = False

def init_compile(define={}):
    global define_map
    define_map = define


if __name__ == '__main__':
    main()