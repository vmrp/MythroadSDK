斯凯mr使用的是lua 5.0，因此语法也是5.0的

http://www.lua.org/manual/5.0/

## 语法差异
```lua
/* 注释改成了c语言的注释风格 */

// 函数定义关键字由function改成了def
def test(a)
	if a != 1 then   // 原本lua是 ~= 改成了 !=
	elif a = 2 then  // 由原本lua的 elseif 改成了elif
	end
	if a>0 && b<0 then // 原本lua是 and 改成了 &&
	end
	if a>0 || b<0 then // 原本lua是 or 改成了 ||
	end
end

全局变量的变化
_G 改成了 _R
```

## 框架函数
```
// 事件函数
def dealevent(code, p0, p1, p2)
  // 与c语言框架的参数相同，但是在接收短信时会多一个p2参数
  // 因为我们用不上发短信功能，因此是没用的
end

def suspend()
   return 0
end

def resume()
   return 0
end

// 与c语言相比，没有init()函数，实际因为语言特性，放在外面的代码就是初始化
```

## 迭代
获取数组长度用 table.getn(arr)，5.1才有#table这种语法
```
// 数组用table.iforEach()
table.iforEach(tanks, def(i,v)
end)

// 对象用table.forEach()
table.forEach(obj, def(k,v)
end)
```

## 定时器
底层只有一个定时器，因此第一个参数其实是无效的，但是必需有，传任意值都可以

```c
// 启动一个定时器，1000毫秒，时间到了之后调用全局的timecb函数（注意传的是个字符串，而不是函数指针）
_timerStart(0, 1000, "timecb")

// 立即停止定时器
_timerStop(0)
```

## 协程库(功能应该和原版lua相同，暂未测试)
在 src/src/lib/mr_baselib.c 中实现
- _co.create()
- _co.wrap()
- _co.resume()
- _co.yield()
- _co.status()

## 全局函数
在 src/src/lib/mr_baselib.c 中实现
- _error() 功能应该与原lua中的 error() 相同
- _getTab() 功能应该与原lua中的 getmetatable() 相同
- _setTab() 功能应该与原lua中的 setmetatable() 相同
- _getEnv() 功能应该与原lua中的 getfenv() 相同
- _setEnv() 功能应该与原lua中的 setfenv() 相同
- _iPairs() 功能应该与原lua中的 ipairs() 相同
- print() 功能应该与原lua中的 print() 相同，但最多只能打印190个字符，超过会报错
- _num() 功能应该与原lua中的 tonumber() 相同
- _str() 功能应该与原lua中的 tostring() 相同
- _next() 功能应该与原lua中的 next() 相同

- tonumber() 是 _num() 的别名，属于兼容性部分，不清楚会不会有问题
- tostring() 是 _str() 的别名，属于兼容性部分，不清楚会不会有问题
- type() 类似原lua中的type() 但是返回 "nil"/"boolean"/"object"/"number"/"string"/"table"/"function"/"thread"
- next() 是 _next() 的别名，属于兼容性部分，不清楚会不会有问题
- pcall() 是 _pCall() 的别名，属于兼容性部分，不清楚会不会有问题
- loadfile() 是 _loadFile() 的别名，属于兼容性部分，不清楚会不会有问题
- dofile() 是 _execFile() 的别名，属于兼容性部分，不清楚会不会有问题
- _loads() 是 _loadBuf() 的别名，属于兼容性部分，不清楚会不会有问题

- _t() 类似原lua中的type() 但是返回 "nil"/"bool"/"obj"/"num"/"str"/"tab"/"func"/"co"
- _assert() 功能应该与原lua中的 assert() 相同
- _rawEq() 功能应该与原lua中的 rawequal() 相同
- _pCall() 功能应该与原lua中的 pcall() 相同
- _pCallEx() 功能应该与原lua中的 xpcall() 相同
- _gc() 功能应该与原lua中的 collectgarbage() 相同
- _loadFile() 功能应该与原lua中的 loadfile() 相同
- _execFile() 功能应该与原lua中的 dofile() 相同
- _loadBuf() 功能应该与原lua中的 loadstring() 相同

- _initNet() 初始化网络功能，详见网络通信一节
- _closeNet() 关闭网络功能，详见网络通信一节



# 网络通信
在 src/src/lib/mr_socket_target.c 中实现

所有网络功能都需要在调用 _initNet() 之后才能使用

- _initNet(mode) 初始化网络功能，mode可以取值'cmwap'和'cmnet'，通过 socket.state 检查是否初始化成功
- _closeNet()  关闭网络功能(可以被垃圾回收自动关闭)
- socket.state 检查 _initNet() 的结果，取值 {success=2, failed=5, waitting=1, closed=3}
- socket.getHost(name) 通过主机名获得该主机的IP地址值，如果一个主机的IP地址为218.18.95.203，则值为218<<24 + 18<<16 + 95<<8 + 203= 0xda125fcb。在同步模式下会立即返回ip，异步模式下检查socket.ip的值来获取ip，推荐始终检查socket.ip的值来获取执行的结果
- socket.ip    检查 socket.getHost() 的结果，当值为-1时表示socket.getHost()执行失败，当值为2时表示仍在等待结果，其它值则为获取到的ip
- socket.udp() 创建udp对象，成功返回udp对象，失败返回nil
- udp:close()  关闭udp(可以被垃圾回收自动关闭)
- udp:sendto(data,ip,port,start,end) 发送数据，data为string类型，ip/port/start/end都是number类型，start默认为1，end默认为-1，成功时返回已发送字节数，失败返回nil和错误消息
- udp:receivefrom(n) 接收数据，参数n可以指定要接收的长度，但是底层限制最大值为1500，成功时返回接收到的数据、对方IP和对方端口，如果未收到数据则返回'',nil,nil，如果失败则返回nil,'错误消息',nil
- socket.tcp() 创建tcp对象，成功返回tcp对象，失败返回nil
- tcp:connect(ip,port,type) 建立TCP连接，其中type参数值为0时（默认）采用阻塞式连接，设置为1时采用异步连接，成功返回0，失败返回nil，当异步连接时返回2，异步连接需要调用tcp:getstate()来获取最终状态
- tcp:getstate() 获取异步连接状态，返回值opened:0, connecting:1,connected:2,closed:3,timeout:4,err:5
- tcp:send(data,start,end) 发送数据，data为string类型，start默认为1，end默认为-1，成功时返回已发送字节数，失败返回nil和错误消息
- tcp:receive(n) 接收数据，参数n可以指定要接收的长度，但是底层限制最大值为1500，成功时返回接收到的数据，如果未收到数据则返回''，如果失败则返回nil,'错误消息'
- tcp:close()  关闭tcp(可以被垃圾回收自动关闭)
## getHost demo
```lua
local net = _initNet('cmnet')

local ip2str = def(ip)
    local a = _and(ip/16777216,0xff) // v >> 24
    local b = _and(ip/65536,0xff)    // v >> 16
    local c = _and(ip/256,0xff)      // v >> 8
    local d = _and(ip,0xff)
    return string.format("%d.%d.%d.%d", a, b, c, d)
end

def queryGetHost()
    if socket.ip == -1 then
        print('queryGetHost fail')
    elif socket.ip == 2 then // 还是等待状态
        _timerStart(0, 10, 'queryGetHost')
    else
        print('ip:' .. socket.ip)
        print('ip str:' .. ip2str(socket.ip))
    end
end

socket.getHost("qq.com")
queryGetHost()
```

## UDP demo
```lua
_initNet('cmnet')
local udpTest

local def tabToStr(t)
    local tmp = {}
    for index, value in _iPairs(t) do
        tmp[table.getArrSize(tmp) + 1] = string.char(value) 
    end
    return table.concat(tmp)
end

local def strToTab(s)
    local tmp = {}
    for i = 1, string.len(s), 1 do 
        tmp[table.getArrSize(tmp) + 1] = string.byte(s, i) 
    end
    return tmp
end

local def makeIp(a,b,c,d)
    a = _and(a,0xff) * 16777216 // v << 24
    b = _and(b,0xff) * 65536    // v << 16
    c = _and(c,0xff) * 256      // v << 8
    d = _and(d,0xff)
    return a + b + c + d
end

local def hexdump(s)
    local t = strToTab(s)
    local str = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}
    str[0] = '0'
    for i, v in _iPairs(t) do 
        t[i] = str[_and(v/16,0xf)] .. str[_and(v, 0xF)] 
    end
    return table.concat(t, ',')
end

// 检测是否初始化成功
def getNetworkState()
    print('socket.state:' .. socket.state)
    if socket.state == 1 then
        _timerStart(0, 1000, 'getNetworkState')
    elif socket.state == 2 then
        udpTest()
    else
        print('network init fail.')
    end
end

getNetworkState()

def udpTest()
    // send dns query 'www.qq.com'
    local sendData = {168,177,1,0,0,1,0,0,0,0,0,0,3,119,119,119,2,113,113,3,99,111,109,0,0,1,0,1}
    local data = tabToStr(sendData)
    local ip = makeIp(114,114,114,114)

    local udp = socket.udp()

    // data, ip, port, start, end
    // 成功返回发送的字节数，失败返回 nil,'err',mr_sendto的返回值
    local n,err,ret = udp:sendto(data, ip, 53)
    print(n,err,ret)

    print('udp:sendto():' .. hexdump(data))
    // len最大1500 
    // 成功返回data,ip,port，失败返回'',nil,nil 或 nil,'err',nil
    local data,ip,port = udp:receivefrom(1500)
    if data != '' && data != nil then
        print('udp:receivefrom(1500)' .. string.len(data))
        print(string.sub(hexdump(data), 1, 190))
    end
    udp:close()
    print('udpTest end.')
    _closeNet()
end
```
## TCP demo
```lua
local net = _initNet('cmnet')
local tcp = socket.tcp()

local makeIp = def(a,b,c,d)
    a = _and(a,0xff) * 16777216 // v << 24
    b = _and(b,0xff) * 65536    // v << 16
    c = _and(c,0xff) * 256      // v << 8
    d = _and(d,0xff)
    return a + b + c + d
end

def recvData()
    // 参数：len,最大1500
    // 成功返收到的数据,nil 未收到数据返回"",nil 失败返回nil,'err'
    local data, err = tcp:receive(190) // print() 最大只能打印190个字符

    // if (data != "") && (data != nil) then
    if data != "" then
        if data != nil then
            print('recv:', data)
            _timerStart(0, 100, 'recvData')
        end
    else
        print('recv err:', err)
    end
end

def sendData()
    local data = 'GET / HTTP/1.1\r\nHost: 192.168.1.1\r\n\r\n'
    // 参数data,start默认1,end默认-1
    // 成功返回发送的字节数,nil,nil 失败返回nil,'err',mr_send的返回值
    local r = tcp:send(data)
    if r != nil then
        print('tcp:send(data):', r, string.len(data), data)
    end
    recvData()
end


def getstate()
    // 返回值 opened:0, connecting:1,connected:2,closed:3,timeout:4,err:5
    local ret = tcp:getstate()
    print('tcp:getstate():', ret)
    if ret == 2 then // 连接成功
        sendData()
        return
    end
    _timerStart(0, 100, 'getstate')
end

local MR_SOCKET_BLOCK=0    //阻塞方式（同步方式）
local MR_SOCKET_NONBLOCK=1  //非阻塞方式（异步方式）

local ip = makeIp(192,168,1,1)
local ret = tcp:connect(ip, 80, MR_SOCKET_NONBLOCK) // 成功返回0，失败返回nil，等待返回2
print('connect r:', ret)
getstate()
```



















