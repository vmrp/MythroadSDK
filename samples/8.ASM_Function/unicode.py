t = []
t.append("嵌入汇编")
t.append("16bit定点小数乘法")
t.append("编译选项为使用汇编实现。")
t.append("编译选项为使用C实现。")
t.append("结果是")
t.append("这是C中嵌入汇编实现16bit定点小数乘法的DEMO！")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
