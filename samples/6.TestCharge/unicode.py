t = []
t.append("计费测试")
t.append("收取费用")
t.append("检查收费情况")
t.append("收费结果")
t.append("发送短信成功")
t.append("发送短信失败")
t.append("尚未付费")
t.append("已付费")
t.append("出错提示")
t.append("计费模块初始化失败！")
t.append("这是杭州斯凯网络科技有限公司Mythroad平台的Demo！")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
