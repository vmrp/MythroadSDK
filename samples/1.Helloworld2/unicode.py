t = []
t.append("Helloworld")
t.append("����ѡ��ΪCONFIG_176")
t.append("����ѡ��ΪCONFIG_240")
t.append("���Ǻ���˹������Ƽ����޹�˾Mythroadƽ̨��Demo��")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
