t = []
t.append("�ļ�ϵͳ����")
t.append("��ʱ����")
t.append("��ѭ��")
t.append("��ռ����ģ����ѭ��")
t.append("����")
t.append("�˳���ʾ")
t.append("���Ƕ�ʱ�����ȵ���ʾDEMO��")
t.append("��ʾ��ʱ���ĳ���ʹ�÷�����ÿ��100msִ��һ�κ�ʱ200����Ĳ������밴ȷ�ϼ���ʼ��ʾ!")
t.append("��ѭ����һЩ��Ҫѭ��������ɨ���Ӧ��ϣ��ʹ����ѭ�������ǣ���������г�����ѭ�����ֻ����޷���Ӧ�ⲿ�绰���У�������������λ����������Ҫ��ʾô���밴ȷ�ϼ���ʼ��ʾ��ѭ����")
t.append("��ʾ��ʱ����ռ���ȣ���ϣ���õ�ģ����ѭ����Ч���������ֲ������޷���Ӧ�绰�¼�ʱ��ͨ����Ҫʹ�ö�ʱ����ռ���ȡ�����ռ�����У���ʱʱ�䵽����������һ����ʱ���ٴ���ҵ�����������ͨ��ѡ��ǡ���Ķ�ʱʱ������������Ա�ļ�������飩�������ڱ���ҵ������������ǰ����һ����ʱ�����Ѿ���ʱ������Mythroadƽ̨�ǵ��̵߳��Ҳ�֧����ռʽ���ᣬ�����ڴ���ҵ������ڼ䣬��ʹ��һ����ʱ����ʱʱ�䵽�ˣ�Ҳ����ȴ����в�����ϡ�ϵͳ���к�ű�Mythroad���ȡ�����ռ�����ڼ䣬�������������ֻ������ֻ������ܹ��ɹ��Ľ����绰����ȷ�ϼ���ʼ��ʾ��")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u