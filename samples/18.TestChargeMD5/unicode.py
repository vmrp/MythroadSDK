t = []
t.append("�ƷѲ���")
t.append("��ȡ����")
t.append("����շ����")
t.append("�շѽ��")
t.append("���Ͷ��ųɹ�")
t.append("���Ͷ���ʧ��")
t.append("��δ����")
t.append("�Ѹ���")
t.append("������ʾ")
t.append("�Ʒ�ģ���ʼ��ʧ�ܣ�")
t.append("���Ǻ���˹������Ƽ����޹�˾Mythroadƽ̨��Demo��")
t.append("����UI�շѽ���")
t.append("�Զ����շѽ��棨ͼƬ��")
t.append("�Զ����շѽ��棨���֣�")
t.append("ȷ��")
t.append("���׵硷�������׹������˼������ܴ����ֻ��4Ԫ���������ܡ������շѽ��Զ������Ž���ȷ�ϣ�����ظ���")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
