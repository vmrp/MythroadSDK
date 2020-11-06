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
t.append("本地UI收费界面")
t.append("自定义收费界面（图片）")
t.append("自定义收费界面（文字）")
t.append("确定")
t.append("《雷电》大名如雷贯耳，如此佳作不能错过！只需4元，终生享受。本次收费将以多条短信进行确认，无需回复。")

for s in t:
  uni = s.decode("cp936")
  u = ''
  for c in uni:
    c = ord(c)
    u = u + '\\' + hex(c / 256)[1:] + '\\' + hex(c % 256)[1:]
  print s
  print u
