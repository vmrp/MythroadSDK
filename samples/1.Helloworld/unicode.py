t = []
t.append("Helloworld")
t.append("编译选项为CONFIG_176")
t.append("编译选项为CONFIG_240")
t.append("这是杭州斯凯网络科技有限公司Mythroad平台的Demo！")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
