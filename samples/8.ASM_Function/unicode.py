t = []
t.append("Ƕ����")
t.append("16bit����С���˷�")
t.append("����ѡ��Ϊʹ�û��ʵ�֡�")
t.append("����ѡ��Ϊʹ��Cʵ�֡�")
t.append("�����")
t.append("����C��Ƕ����ʵ��16bit����С���˷���DEMO��")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
