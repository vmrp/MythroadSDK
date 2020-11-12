
import mr,zlib,struct

print mr.mrencode("foo")

print zlib.crc32("hello")


def write_file(name, s, mode='w'):
    try:
        f = file(name, mode)
        try:
            f.write(s)
        finally:
            f.close()
    except:
        print ('Can not open file "' + name + '"!')
        raise


def getstr(s, l):
    s_len = len(s)
    if s_len >= l:
        return s[:l]
    else:
        return s + '\x00' * (l - s_len)

def buildfilehead(visible=1,appid=99, version=0,scr_w=0, scr_h=0,cpu=1,shell=0,head_append=None):
    if visible == 0:
        flag = 0
    else:
        flag = 1
    flag = flag + cpu * 2
    flag = flag + shell * 8
    filehead = 'MRPG' # 0-3
    filehead = filehead + '\x00' * 4
    filehead = filehead + '\x00' * 4
    filehead = filehead + '\x00' * 4
    print len(filehead)

    filehead = filehead + getstr('filename', 12)
    filehead = filehead + getstr('appname', 24)
    # filehead = filehead + g_host_auth_str[2] + g_host_auth_str[4] + g_host_auth_str[8] + g_host_auth_str[9] + g_host_auth_str[11] + g_host_auth_str[12] + g_host_auth_str[1] + g_host_auth_str[7] + g_host_auth_str[6] + '\x00' * 7

    filehead = filehead + '2489bc176'+'\x00' * 7

    filehead = filehead + struct.pack('<i', appid) #int32
    filehead = filehead + struct.pack('<i', version)
    filehead = filehead + struct.pack('<i', flag)
    filehead = filehead + struct.pack('<i', 10002)
    filehead = filehead + '\x00' * 4
    filehead = filehead + getstr('vendor', 40)
    filehead = filehead + getstr('description', 64)
    filehead = filehead + struct.pack('>i', appid)
    filehead = filehead + struct.pack('>i', version)
    filehead = filehead + '\x00' * 4
    filehead = filehead + struct.pack('<H', scr_w) #uint16
    filehead = filehead + struct.pack('<H', scr_h)

    filehead = filehead + struct.pack('<B', 1) #uint8

    # if project['plat'] == 'mtk' or project['plat'] == 'mstar':
    #     filehead = filehead + struct.pack('<B', 1)
    # elif project['plat'] == 'spreadtrum':
    #     filehead = filehead + struct.pack('<B', 2)
    # else:
    #     filehead = filehead + struct.pack('<B', 0)

    filehead = filehead + '\x00' * 31
    if head_append != None:
        filehead = filehead + head_append
    return filehead


# def adjustfilehead():
#     global filehead
#     filehead_len = len(filehead)
#     debuginfo('adjustfilehead:filehead_len:' + str(len(filehead)))

#     indexbuf_len = len(indexbuf)
#     filesbuf_len = len(filesbuf)
#     appinfo_len = filehead_len + indexbuf_len - 8
#     index_pos = filehead_len
#     file_len = filehead_len + indexbuf_len + filesbuf_len

#     filehead = filehead[:4] + struct.pack('<i', appinfo_len)
#  + struct.pack('<i', file_len) 
#  + struct.pack('<i', index_pos) 
#  + filehead[16:]

#     crc = zlib.crc32(filehead + indexbuf + filesbuf)
#     filehead = filehead[:84] + struct.pack('<i', crc) + filehead[88:]


buildfilehead()
# write_file("./ff", buildfilehead())
write_file("./ff", 'asdf'[:2])
print ('done.')