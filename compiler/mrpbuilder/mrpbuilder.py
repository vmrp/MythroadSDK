# uncompyle6 version 3.7.4
# Python bytecode 2.3 (62011)
# Decompiled from: Python 2.7.16 (default, Oct 10 2019, 22:02:15) 
# [GCC 8.3.0]
# Embedded file name: mrpbuilder.py
# Compiled at: 2020-11-12 09:06:36
start_file = '\n\n/*************************************************************************************\n\xce\xc4\xbc\xfe\xcb\xb5\xc3\xf7: \xb1\xbe\xce\xc4\xbc\xfe\xca\xb5\xcf\xd6\xc1\xcb\xc8\xe7\xba\xce\xbd\xab\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xbd\xf8\xd0\xd0\xb7\xd6\xc1\xf7\xb3\xc9\xb6\xe0\xb8\xf6\xb6\xa8\xca\xb1\n                        \xc6\xf7\n\xb4\xb4\xbd\xa8\xd5\xdf  : \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060707\xb4\xb4\xbd\xa8\n*************************************************************************************/\n\ntimer = {}\n\ndef debugTrace()\nend\n\n\n/******************************************************************************\ntim_struct =\n{\ntimerId        \xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4id\xba\xc5  \xd5\xe2\xb8\xf6\xb1\xd8\xd0\xeb\xca\xc7\xce\xa8\xd2\xbb\xb5\xc4\xa3\xac\xb2\xa2\xc7\xd2\xc6\xe4\xcb\xfb\xb5\xc4\xc4\xa3\xbf\xe9\n                       \xb1\xd8\xd0\xeb\xcd\xa8\xb9\xfd\xd5\xe2\xb8\xf6id\xb2\xc5\xc4\xdc\xbd\xf8\xd0\xd0\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xcf\xe0\xb9\xd8\xb2\xd9\xd7\xf7\xa1\xa3\ntimTime       \xb5\xb1\xc7\xb0\xb6\xa8\xb6\xa8\xca\xb1\xc6\xf7\xc6\xf4\xb6\xaf\xb5\xc4\xca\xb1\xbc\xe4\xbc\xe4\xb8\xf4\ntimActive     \xb5\xb1\xc7\xb0\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xca\xc7\xb7\xf1\xb1\xbb\xbc\xa4\xbb\xee\ntimRepeat    \xb6\xa8\xca\xb1\xc6\xf7\xca\xc7\xb7\xf1\xca\xc7\xbf\xc9\xd6\xd8\xb8\xb4\xb5\xc4\nautoDelete   \xd0\xe8\xd2\xaa\xc9\xbe\xb3\xfd\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xd3\xc3\xd3\xda\xbf\xd8\xd6\xc6\xd4\xda\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\xd6\xd0\n                      \xd3\xd0\xd0\xe8\xd2\xaa\xc9\xbe\xb3\xfd\xb6\xa8\xca\xb1\xc6\xf7\xc7\xeb\xc7\xf3\xb5\xc4\xa1\xa3\ntimLeft         \xb6\xa8\xca\xb1\xc6\xf7\xca\xa3\xd3\xe0\xb5\xc4\xca\xb1\xbc\xe4\ntimFunc        \xb6\xa8\xca\xb1\xc6\xf7\xb6\xd4\xd3\xa6\xb5\xc4\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\n}\n******************************************************************************/  \n#define  TIME_METHOD_2\n//#define  TIME_METHOD_1\n//\xd3\xc3\xd3\xda\xb7\xbd\xb7\xa82\xa3\xac\xd7\xf7\xce\xaa\xd0\xc4\xcc\xf8\xa1\xa3\xd3\xc3\xd3\xda\xd1\xad\xbb\xb7\xbc\xec\xb2\xe2\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xa1\xa3\n#define  TIME_TICK 200   \nlocal timList = {}\n//timer\xb5\xc4id\xa3\xac\xb4\xd31000\xbf\xaa\xca\xbc\xbc\xc6\xca\xfd\xa3\xac\xc3\xbf\xb4\xce\xd4\xf6\xbc\xd31\xa1\xa3\nlocal timeIdUuid\n//\xd3\xc3\xd3\xda\xb6\xd4\xd3\xda\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\xd6\xd0\xbb\xe1\xb3\xf6\xcf\xd6\xc6\xf4\xb6\xaf\xb6\xa8\xca\xb1\xc6\xf7\xa1\xa2\xcd\xa3\xd6\xb9\xb6\xa8\xca\xb1\xc6\xf7\xba\xcd\xc9\xbe\xb3\xfd\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xc7\xe9\xbf\xf6\xa3\xac\xd3\xc3\xd3\xda\xbb\xa5\xb3\xe2\xa1\xa3\nlocal timeInSystemCycleCb \n//local TIM_timInit, TIM_timCreate, TIM_timStart, TIM_timStop, TIM_timSetTime, TIM_timDelete\nlocal TIM_timInit\nlocal i_timCompare, sortTimerList, i_timGetUuid, i_timAdjust, i_timStart, i_timStop, i_timCycleCb\n/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\xcb\xb5\xc3\xf7:     \xb6\xd4\xcd\xe2\xb5\xc4\xbd\xd3\xbf\xda\n        TIM_timCreate(aTimTime, aTimFunc)  \xb4\xb4\xbd\xa8\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb7\xb5\xbb\xd8\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4timerId\n        TIM_timStart(aTimRepeat, aTimerId)    \xc6\xf4\xb6\xaf\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xacaRimRepeat\xca\xc7\xb7\xf1\xd6\xd8\xb8\xb4\n        TIM_timStop(aTimerId)\xd4\xdd\xcd\xa3\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb5\xab\xca\xc7\xd7\xee\xbd\xfc\xd2\xbb\xb4\xce\xb5\xc4\xbb\xd8\xb5\xf7\xd2\xb2\xd2\xf2\xb4\xcb\n                                          \xbf\xc9\xc4\xdc\xb1\xbb\xd4\xdd\xcd\xa3\xb5\xf4\xa1\xa3\n        TIM_timSetTime(aTimerId, aTimTime)\xd6\xd8\xd0\xc2\xc9\xe8\xd6\xc3\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xca\xb1\xbc\xe4\xbc\xe4\xb8\xf4\xa3\xac\xb5\xab\xca\xc7\n                                          \xc8\xe7\xb9\xfb\xd5\xe2\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xd2\xd1\xbe\xad\xb1\xbb\xc6\xf4\xb6\xaf\xbf\xc9\xc4\xdc\xb2\xbb\xbb\xe1\xb6\xd4\xd7\xee\xbd\xfc\xb5\xc4\n                                          \xd2\xbb\xb4\xce\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xbb\xd8\xb5\xf7\xd3\xd0\xd3\xb0\xcf\xec\xa1\xa3\n        TIM_timDelete(aTimerId) \xc9\xbe\xb3\xfd\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb2\xa2\xc7\xd2\xd7\xee\xbd\xfc\xb5\xc4\xd2\xbb\xb4\xce\xbb\xd8\xb5\xf7\xd2\xb2\xb2\xbb\xbb\xe1\n                                          \xb1\xbb\xd6\xb4\xd0\xd0\n                                          \n        TIM_timInit()               \xb6\xa8\xca\xb1\xc6\xf7\xb9\xa6\xc4\xdc\xb2\xbf\xb7\xd6\xb5\xc4\xb3\xf5\xca\xbc\xbb\xaf\xa1\xa3\xd6\xbb\xd3\xd0\xd4\xda\xb3\xcc\xd0\xf2\xb3\xf5\xca\xbc\xbb\xaf\n                                         \xb5\xc4\xca\xb1\xba\xf2\xb5\xf7\xd3\xc3\xa1\xa3\n       \n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc:  20060710 \xb4\xb4\xbd\xa8\xd5\xe2\xb2\xbf\xb7\xd6\xb4\xfa\xc2\xeb\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timInit()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb6\xa8\xca\xb1\xc6\xf7\xb3\xf5\xca\xbc\xbb\xaf\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef TIM_timInit()\n  debugTrace ("TIM_timInit")\n  timList= {}\n  timeIdUuid = 1000\n  timeInSystemCycleCb = 0\n  #ifdef TIME_METHOD_2\n  i_timStart(TIME_TICK)      \n  #endif\n\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timCreate(aTimTime, aTimFunc)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb4\xb4\xbd\xa8\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xd5\xe2\xc0\xef\xd0\xe8\xd2\xaa\xd7\xa2\xd2\xe2\xb5\xc4\xca\xc7\xb4\xb4\xbd\xa8\xc1\xcb\xb5\xc4\n                         \xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xd0\xe8\xd2\xaa\xd4\xda\xc6\xf4\xb6\xaf\xd2\xd4\xba\xf3\xb2\xc5\xc4\xdc\xbf\xaa\xca\xbc\xa1\xa3\xc1\xed\xcd\xe2\xd2\xaa\xc7\xf3\n                         \xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xd7\xee\xd0\xa1\xca\xb1\xbc\xe4\xbc\xe4\xb8\xf4\xca\xc7100ms\xa1\xa3\xb1\xd8\xd0\xeb\xd2\xaa\xd3\xd0\xbb\xd8\xb5\xf7\n                         \xba\xaf\xca\xfd\n\xba\xaf\xca\xfd\xb7\xb5\xbb\xd8: \xb4\xb4\xbd\xa8\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4id\xa3\xac\xc8\xe7\xb9\xfbid\xce\xaa0\xa3\xac\xc4\xc7\xc3\xb4\xbe\xcd\xb1\xed\xca\xbe\xd3\xd0\xce\xca\xcc\xe2                              \n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef timer.create(aTimTime, aTimFunc)\n  local time = {}\n  \n  if aTimFunc == nil then\n    debugTrace ("TIM_timCreate error aTimFunc if nil")\n    return 0\n  end\n  debugTrace ("TIM_timCreate time.time " .. aTimTime)\n   \n  if aTimTime <100 then \n     aTimTime =100\n  end\n  \n  time.timRepeat = 0\n  time.timActive = 0\n  time.timLeft = 0 \n  time.autoDelete = 0  \n  time.timTime = aTimTime\n  time.timFunc = aTimFunc\n  time.timerId = i_timGetUuid()\n  time.autoDelete = 0\n  \n  table.insert(timList, time)\n  \n  return time.timerId\nend\n\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timStart(aTimRepeat, aTimerId)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xc6\xf4\xb6\xaf\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa1\xa3\xd5\xe2\xc0\xef\xd3\xd0\xd2\xbb\xb5\xe3\xd0\xe8\xd2\xaa\xd7\xa2\xd2\xe2\xb5\xc4\xca\xc7\xc8\xe7\xb9\xfb\n           \xb6\xa8\xca\xb1\xc6\xf7\xd2\xd1\xbe\xad\xc6\xf4\xb6\xaf\xa3\xac\xc4\xc7\xc3\xb4\xbd\xab\xb2\xbb\xbb\xe1\xb6\xd4\xd6\xae\xc7\xb0\xb5\xc4timleft\xc9\xe8\xd6\xc3\n           \xb2\xfa\xc9\xfa\xd3\xb0\xcf\xec\xa1\xa3\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef timer.start(aTimRepeat, aTimerId)\n  local time = {}\n  local timNum = table.getn(timList)\n\n  if aTimRepeat == nil || timNum == 0 then\n     return\n  end\n\n  if(aTimerId ==nil || aTimerId <1000) then\n     debugTrace ("TIM_timStop error id")\n     return\n  end\n  debugTrace ("TIM_timStart aTimerId =" .. aTimerId .. " numoftimetable = ".. timNum)\n  \n  for i = 1,  timNum do\n     time = timList[i] \n     if time.timerId == aTimerId then\n         debugTrace ("TIM_timStart aTimerId is found")\n         if time.timActive == 1 then\n            debugTrace ("TIM_timStart tim is activing")\n         else\n            time.timLeft = time.timTime  + TIME_TICK/2\n         end\n         time.timRepeat = aTimRepeat \n         time.timActive = 1\n         break\n     end   //        if time.timerId == aTimerId then\n  end //    for i = 1,  timNum do\n  /*\n  \xc8\xe7\xb9\xfb\xb5\xb1\xc7\xb0\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4timleft\xb2\xbb\xb4\xf3\xd3\xda\xc1\xd0\xb1\xed\xd6\xd0\xb5\xda\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4timleft\n  \xd4\xf2\xd0\xe8\xd2\xaa\xc6\xf4\xb6\xaf\xd2\xbb\xb4\xce\xcf\xb5\xcd\xb3\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb1\xa3\xd6\xa4\xb6\xa8\xca\xb1\xc6\xf7\xd5\xfd\xb3\xa3\xd4\xcb\xd0\xd0\n  \xc8\xe7\xb9\xfb\xb6\xa8\xca\xb1\xc6\xf7\xb5\xb1\xc7\xb0\xd5\xfd\xd4\xda\xd1\xad\xbb\xb7\xa3\xac\xc4\xc7\xc3\xb4\xbe\xcd\xb2\xbb\xd0\xe8\xd2\xaa\xbd\xf8\xd0\xd0\xc5\xc5\xd0\xf2\xba\xcd\n  \xc6\xf4\xb6\xaf\xa3\xac\xcf\xb5\xcd\xb3\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\xd6\xd0\xa3\xac\xd7\xd4\xbc\xba\xbb\xe1\xcd\xea\xb3\xc9h\n\n  \xd5\xe2\xb8\xf6\xb5\xd8\xb7\xbd\xd4\xad\xcf\xc8\xd3\xd0bug\xa3\xac\xbc\xd9\xc9\xe8\xb5\xb1\xc7\xb0\xc1\xd0\xb1\xed\xd6\xd0\xc3\xbb\xd3\xd0\xbc\xa4\xbb\xee\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xc4\xc7\xc3\xb4\xd6\xbb\xca\xc7\xd6\xd8\xd0\xc2\xc5\xc5\xd0\xf2\n  \xc4\xc7\xc3\xb4\xb1\xd8\xc8\xbb\xbb\xe1\xb3\xf6\xcf\xd6\xb5\xc4\xce\xca\xcc\xe2\xbe\xcd\xca\xc7\xc3\xbb\xd3\xd0\xb6\xa8\xca\xb1\xc6\xf7\xbb\xe1\xd4\xcb\xd0\xd0\xa1\xa3\n*/\n  if timeInSystemCycleCb == 0 then\n    if timList[1].timActive == 0  then\n       sortTimerList()\n       \n       #ifdef TIME_METHOD_1\n       local nextTime = (timList[1].timLeft < 100 && 100) || timList[1].timLeft \n       i_timStart(nextTime)\n       i_timAdjust(nextTime)    \n       #endif\n    elif time.timLeft > timList[1].timLeft  then\n       //table.sort(timList, i_timCompare)\n       debugTrace ("TIM_timStart time1")\n       sortTimerList()\n    else\n       //table.sort(timList, i_timCompare)\n       sortTimerList()\n\n       #ifdef TIME_METHOD_1\n  local nextTime = (timList[1].timLeft < 100 && 100) || timList[1].timLeft \n  debugTrace ("TIM_timStart nextTime = " .. nextTime)\n       i_timStart(nextTime)\n       i_timAdjust(nextTime)      \n       #endif\n    end\n  end\n\n  return\nend\n\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timStop(aTimerId)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xd4\xdd\xcd\xa3\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xbd\xab\xb6\xa8\xca\xb1\xc6\xf7\xd6\xc3\xce\xbb\xb7\xc7\xbb\xee\xa3\xac\xbd\xab\xb6\xa8\xca\xb1\xc6\xf7\n                         \xb5\xc4timleft\xd6\xc3\xce\xbb\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef timer.stop(aTimerId)\n   local time = {}\n   local timNum = table.getn(timList)\n   \n  if(aTimerId ==nil || aTimerId <1000 || timNum == 0) then\n     debugTrace ("TIM_timStop error id")\n     return\n  end\n   debugTrace ("TIM_timStop aTimerId = " .. aTimerId .." numoftimetable = ".. timNum)\n   \n   for i = 1,  timNum do\n      time = timList[i] \n      if time.timerId == aTimerId then\n         if time.timActive == 1 then\n            debugTrace ("TIM_timStop tim is activing")\n         else\n            debugTrace ("TIM_timStop tim is inactive")\n         end\n          time.timRepeat = 0\n          time.timActive = 0\n          time.timLeft = 0\n      end //    if time.timerId == aTimerId then\n   end //  for i = 1,  timNum do\n \n   if timeInSystemCycleCb == 0 then\n      //table.sort(timList, i_timCompare)\n      sortTimerList()\n   end\n   \n   return\nend\n\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timSetTime(aTimerId, aTimTime)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xd6\xd8\xd0\xc2\xc9\xe8\xd6\xc3\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xb6\xa8\xca\xb1\xca\xb1\xbc\xe4\xa3\xac\xd5\xe2\xc0\xef\xd0\xe8\xd2\xaa\xd7\xa2\xd2\xe2\n                         \xb5\xc4\xca\xc7\xa3\xac\xc8\xe7\xb9\xfb\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xca\xb1\xbc\xe4\xd4\xad\xcf\xc8\xd2\xd1\xbe\xad\xb1\xbb\xbc\xa4\xbb\xee\xa3\xac\xc4\xc7\xc3\xb4\n                         \xd5\xe2\xb4\xce\xd0\xde\xb8\xc4\xb2\xbb\xbb\xe1\xd3\xb0\xcf\xec\xb5\xbd\xd6\xae\xc7\xb0\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xca\xa3\xd3\xe0\xca\xb1\xbc\xe4\xc9\xe8\xd6\xc3\xa1\xa3\n                         \xb5\xb1\xc8\xbb\xbf\xc9\xd2\xd4\xcf\xc8\xb5\xf7\xd3\xc3TIM_timSetTime\xa3\xac\xc8\xbb\xba\xf3\xd4\xda\xb5\xf7\xd3\xc3TIM_timStart\xa1\xa3\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef timer.setTime(aTimerId, aTimTime)\n  local time = {}\n  local timNum = table.getn(timList)\n  \n  if(aTimerId ==nil || aTimerId <1000 || timNum == 0) then\n     debugTrace ("TIM_timSetTime error id")\n     return\n  end\n  //debugTrace ("TIM_timSetTime aTimerId =" .. aTimerId)\n  \n  for i = 1,  timNum do\n      time = timList[i] \n      if time.timerId == aTimerId then\n          if time.timActive == 1 then\n        debugTrace ("TIM_timSetTime tim is activing")\n          else\n        debugTrace ("TIM_timSetTime tim is inactive")\n          end\n          time.timTime = aTimTime\n      end\n  end\n  \n  return\nend\n\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  TIM_timDelete(aTimerId)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xc9\xbe\xb3\xfd\xd2\xbb\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xc8\xe7\xb9\xfb\xd4\xad\xcf\xc8\xb6\xa8\xca\xb1\xc6\xf7\xca\xc7\xb1\xbb\xbc\xa4\xbb\xee\xa3\xac\n                         \xc4\xc7\xc3\xb4\xc9\xbe\xb3\xfd\xd5\xe2\xb8\xf6\xb6\xa8\xca\xb1\xc6\xf7\xbd\xab\xb5\xbc\xd6\xc2\xba\xaf\xca\xfd\xb2\xbb\xbb\xe1\xb1\xbb\xb5\xf7\xd3\xc3\xa1\xa3\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef timer.delete(aTimerId)\n  local time = {}\n  local timNum = table.getn(timList)\n  \n  if(aTimerId ==nil || aTimerId <1000 || timNum == 0) then\n     debugTrace ("TIM_timDelete error id")\n     return\n  end\n//  debugTrace ("TIM_timDelete aTimerId =" .. aTimerId .." numoftimetable = ".. timNum)\n  \n  for i = 1,  timNum do\n     time = timList[i] \n     if time.timerId == aTimerId then\n         if time.timActive == 1 then\n            debugTrace ("TIM_timDelete tim is activing")\n         else\n            debugTrace ("TIM_timDelete tim is inactive")\n         end\n         if timeInSystemCycleCb == 0 then\n            table.remove(timList , i)\n         else\n            time.autoDelete = 1     \n            debugTrace ("TIM_timDelete  time.autoDelete")\n         end            \n         return\n     end //       if time.timerId == aTimerId then\n  end //    for i = 1,  timNum do\n  \n  local timNum = table.getn(timList)\n  \n  debugTrace ("TIM_timDelete aTimerId =" .. aTimerId .." numoftimetable = ".. timNum)\n  \n  debugTrace ("TIM_timDelete error not foud aTimerId =" .. aTimerId)\n  \n  return\nend //  def TIM_timDelete(aTimerId)\n\n\n/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\xcb\xb5\xc3\xf7:     \xc4\xda\xb2\xbf\xca\xb5\xcf\xd6\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc:  20060707 \xb4\xb4\xbd\xa8\xd5\xe2\xb2\xbf\xb7\xd6\xb4\xfa\xc2\xeb\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/\n  /******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_timCompare()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb1\xc8\xbd\xcf\xb6\xa8\xca\xb1\xc6\xf7\xc1\xd0\xb1\xed\xd6\xd0\xc1\xbd\xb8\xf6\xd4\xaa\xcb\xd8\xb5\xc4\xb4\xf3\xd0\xa1\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef i_timCompare(aTimer1, aTimer2)\n    if aTimer2.timActive == 0 then\n     return true\n    end\n    if aTimer1.timActive == 0 && aTimer2.timActive == 1 then\n     return false\n    end\n    return aTimer1.timLeft <= aTimer2.timLeft\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  sortTimerList()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xc1\xd0\xb1\xed\xbd\xf8\xd0\xd0\xc5\xc5\xd0\xf2\xa1\xa3\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef sortTimerList()\n    local time1 = {}\n    local time2 = {}\n    local timNum = table.getn(timList)\n\n    for i = 1,timNum-1 do\n   time1 = timList[i]\n        for j = i+1,  timNum do\n     time2 = timList[j]\n        if i_timCompare(time1, time2) then\n        //do nothing\n     else\n        timList[i] = timList[j]\n        timList[j] = time1\n        time1 = timList[i] \n     end\n   end\n    end\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_timGetUuid()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7: \xbb\xf1\xc8\xa1\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4id\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef i_timGetUuid()\n  timeIdUuid = timeIdUuid +1\n  return timeIdUuid\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_timAdjust(nextTimeLeft)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xcd\xb3\xd2\xbb\xbd\xab\xb6\xa8\xca\xb1\xc6\xf7\xd6\xd0\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xb5\xb1\xc7\xb0\xd6\xb5\xbc\xf5\xc8\xa51\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef i_timAdjust(nextTimeLeft)    \n     for n,timeItem in timList do\n        //debugTrace ("i_timAdjust n   " .. n .. " timeItem.timLeft " .. timeItem.timLeft)   \n        timeItem.timLeft = timeItem.timLeft - nextTimeLeft  \n     end\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_systemTimFunc()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xcf\xb5\xcd\xb3\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ni_systemTimFunc = def()\n    //debugTrace ("i_systemTimFunc \\n")\n    //\xb5\xf7\xca\xd4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb5\xf7\xca\xd4\xcd\xea\xb3\xc9\xc9\xbe\xb3\xfd\n    #ifdef TIME_METHOD_2\n    i_timStart(TIME_TICK)     \n    i_timAdjust(TIME_TICK)\n    //i_timStart(TIME_TICK)     \n    #endif\n    \n    timeInSystemCycleCb = 1   \n    local nextTimeLeft = i_timCycleCb()\n    //\xb5\xf7\xca\xd4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb5\xf7\xca\xd4\xcd\xea\xb3\xc9\xc9\xbe\xb3\xfd\n    \n    timeInSystemCycleCb = 0\n    #ifdef TIME_METHOD_1\n    if nextTimeLeft != 0 then \n       if (nextTimeLeft <100 ) then\n          nextTimeLeft = 100\n       end\n       i_timAdjust(nextTimeLeft)\n       //debugTrace ("i_systemTimFunc nextTimeLeft" .. nextTimeLeft)      \n i_timStart(nextTimeLeft)\n    end\n    #endif  \nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_timStart(ms)\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xc6\xf4\xb6\xaf\xcf\xb5\xcd\xb3\xb6\xa8\xca\xb1\xc6\xf7\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef i_timStart(ms)\n  TimerStop(0)\n  TimerStart(0, ms, "i_systemTimFunc")\n  //\xb5\xf7\xca\xd4\xb6\xa8\xca\xb1\xc6\xf7\xa3\xac\xb5\xf7\xca\xd4\xcd\xea\xb3\xc9\xc9\xbe\xb3\xfd\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6: i_timStop()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xcd\xa3\xd6\xb9\xcf\xb5\xcd\xb3\xb6\xa8\xca\xb1\xc6\xf7\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/  \ndef i_timStop()\n  TimerStop(0)\nend\n\n/******************************************************************************\n\xba\xaf\xca\xfd\xc3\xfb\xb3\xc6:  i_timCycleCb()\n\xb2\xce\xca\xfd\xcb\xb5\xc3\xf7:  \n\xba\xaf\xca\xfd\xcb\xb5\xc3\xf7:  \xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xc4\xda\xb2\xbf\xd1\xad\xbb\xb7\xba\xaf\xca\xfd\n\xb4\xb4\xbd\xa8\xd5\xdf  :     \xcc\xc6\xd1\xe5\n\xc0\xfa\xca\xb7\xbc\xc7\xc2\xbc: 20060710\xb4\xb4\xbd\xa8\n******************************************************************************/   \ndef i_timCycleCb()\n\n    local time = {}\n    local timNum = table.getn(timList)\n\n    if timNum <= 0 then\n       return 0;\n    end\n    \n    if (timList[1].timActive == 0) then\n       debugTrace ("i_timCycleCb error ocur no active timer")\n       sortTimerList()\n       return 0\n    end\n\n\n    \n    for i = 1, timNum do\n        time = timList[i] \n        \n        if time.timActive != 0 then\n            if time.timLeft < 1 then\n              //  debugTrace ("tim func is execute timid = " .. time.timerId)\n        time.timActive = 0      \n        time.timLeft = 0    \n                if time.timRepeat == 1 &&  time.autoDelete == 0   then\n                   //debugTrace ("tim func")\n                    time.timLeft = time.timTime\n                    time.timActive = 1\n                end  // if time.timRepeat == 1  &&  time.autoDelete == 0   \n        //\xd3\xc3\xd3\xda\xb5\xf7\xca\xd4\xb6\xa8\xca\xb1\xc6\xf7\xcd\xa3\xd6\xb9\xce\xca\xcc\xe2\xa3\xac\xcd\xea\xb3\xc9\xba\xf3\xc9\xbe\xb3\xfd\n                time.timFunc()\n        //\xd3\xc3\xd3\xda\xb5\xf7\xca\xd4\xb6\xa8\xca\xb1\xc6\xf7\xcd\xa3\xd6\xb9\xce\xca\xcc\xe2\xa3\xac\xcd\xea\xb3\xc9\xba\xf3\xc9\xbe\xb3\xfd\n            end // if time.timeLeft < 1 then\n        end//if time.timActive != 0 then\n    end//    for i = 1, timNum do\n\n     //\xcd\xb3\xd2\xbb\xc9\xbe\xb3\xfd\xc4\xc4\xd0\xa9\xd4\xda\xbb\xd8\xb5\xf7\xba\xaf\xca\xfd\xd6\xd0\xd2\xaa\xc7\xf3\xc9\xbe\xb3\xfd\xb5\xc4\xb6\xa8\xca\xb1\xc6\xf7\n     for n,timeItem in timList do\n        if timeItem.autoDelete == 1 then\n    //debugTrace ("timeItem.autoDelete")\n            table.remove(timList , n)\n  end           \n     end\n\n     local timNum = table.getn(timList)\n     \n     if timNum <= 0 then\n        return 0;\n     end\n     //\xb6\xd4\xb6\xa8\xca\xb1\xc6\xf7\xb5\xc4\xb6\xd3\xc1\xd0\xbd\xf8\xd0\xd0\xc5\xc5\xd0\xf2\n    //for i = 1, timNum do\n    //     debugTrace ("i_timCycleCb 1 timerId == " .. timList[i].timerId .. " timeItem.timLeft =  " .. timList[i].timLeft) \n   // end\n     \n     // table.sort(timList, i_timCompare)\n     sortTimerList()\n     \n   // for i = 1, timNum do\n   //      debugTrace ("i_timCycleCb 1 timerId == " .. timList[i].timerId .. " timeItem.timLeft =  " .. timList[i].timLeft) \n  // end\n    \n     if timList[1].timActive == 1 then\n        return timList[1].timLeft\nelse\n   return 0\nend\nend\n\n//end do\nTIM_timInit()\n\nprint("mythroad init finish")\n_loadFile("main.mr")()\n'
import sys, os, re, mr, getopt, struct, string, copy, time, zlib, _winreg, random, MRC_ConfigParser, mr_compilev2, win32api
if not (hasattr(os, 'spawnvpe') or hasattr(os, 'spawnvp')) and hasattr(os, 'spawnve') and hasattr(os, 'spawnv'):

    def _os__spawnvpe(mode, file, args, env=None):
        import sys
        from errno import ENOENT, ENOTDIR
        from os import path, spawnve, spawnv, environ, defpath, pathsep, error
        if env is not None:
            func = spawnve
            argrest = (args, env)
        else:
            func = spawnv
            argrest = (args,)
            env = environ
        (head, tail) = path.split(file)
        if head:
            return func(mode, file, *argrest)
        if 'PATH' in env:
            envpath = env['PATH']
        else:
            envpath = defpath
        PATH = envpath.split(pathsep)
        if os.name == 'nt' or os.name == 'os2':
            PATH.insert(0, '')
        saved_exc = None
        saved_tb = None
        for dir in PATH:
            fullname = path.join(dir, file)
            try:
                return func(mode, fullname, *argrest)
            except error, e:
                tb = sys.exc_info()[2]
                if e.errno != ENOENT and e.errno != ENOTDIR and saved_exc is None:
                    saved_exc = e
                    saved_tb = tb

        if saved_exc:
            raise error, saved_exc, saved_tb
        raise error, e, tb
        return


    def _os_spawnvp(mode, file, args):
        return os._spawnvpe(mode, file, args)


    def _os_spawnvpe(mode, file, args, env):
        return os._spawnvpe(mode, file, args, env)


    def _os_spawnlp(mode, file, *args):
        return os._spawnvpe(mode, file, args)


    def _os_spawnlpe(mode, file, *args):
        return os._spawnvpe(mode, file, args[:-1], args[(-1)])


    os._spawnvpe = _os__spawnvpe
    os.spawnvp = _os_spawnvp
    os.spawnvpe = _os_spawnvpe
    os.spawnlp = _os_spawnlp
    os.spawnlpe = _os_spawnlpe
    os.__all__.extend(['spawnvp', 'spawnvpe', 'spawnlp', 'spawnlpe'])

def get_start_lines():
    global start_file
    lines = string.split(start_file, '\n')
    for n in range(0, len(lines)):
        lines[n] = lines[n] + '\n'

    return lines


def debuginfo(s):
    global DEBUG_MOD
    if DEBUG_MOD:
        print s


def infoprint(s):
    print s


def extractFilename(filename):
    return filename[string.rfind(filename, '\\') + 1:]


def extractFileDir(filename):
    if string.rfind(filename, '\\') == -1:
        return '.'
    else:
        return filename[:string.rfind(filename, '\\')]


def auth_infoprint(s):
    global mr_authorization
    if mr_authorization == 'mr':
        pass


def addfile2cache(filename, data, origin_len=-1):
    filecache.append((extractFilename(filename), data, origin_len))


def addcfile2cache(filename, localfilecahe=None):
    if None == localfilecahe:
        cfilecache.append(filename)
    else:
        localfilecahe.append(filename)
    return


def dealclib(project_path, output_file, localfilecahe=None):
    if localfilecahe == None:
        localfilecahe = cfilecache
    if len(localfilecahe) == 0:
        return
    infoprint('making c lib...')
    filelist = ''
    for filename in localfilecahe:
        filelist = filelist + ' ' + filename

    param = ' r '
    param = param + output_file
    param = param + ' ' + filelist
    debuginfo(param)
    try:
        ret = os.spawnlpe(os.P_WAIT, 'armar', param, armenv)
    except:
        infoprint('run armar error!')
        raise

    if ret != 0:
        raise
    return


def dealcfiles(project_path, with_c_global=None, c_address=None, c_helper=None, localfilecahe=None, extname='cfunction', c_scatter=None, exram_fix=None, fileparams=[]):
    global COMMAND_PATH
    global C_Address
    global MR_FROMELF
    global MR_LINK
    global RAM_Address
    global WITH_C_GLOBAL
    global WITH_C_HELPER
    global WITH_C_MAP
    if with_c_global == None:
        with_c_global = WITH_C_GLOBAL
    if c_address == None:
        c_address = C_Address
    if c_helper == None:
        c_helper = WITH_C_HELPER
    if localfilecahe == None:
        localfilecahe = cfilecache
    if len(localfilecahe) == 0:
        return
    infoprint('linking c module...')
    filelist = ''
    for filename in localfilecahe:
        filelist = filelist + ' ' + filename

    temp_file = os.environ['TMP'] + '\\mr_' + extname + '.fmt'
    param = ''
    if c_scatter == None:
        if c_address == None:
            if project['plat'] == 'mstar':
                param = param + '--ropi --rwpi'
                param = param + ' "--ro-base" 0x80000'
                param = param + ' --remove '
                if MR_C_Compiler != 'thumb':
                    param = param + ' --first mr_c_function_load'
                    param = param + ' --entry mr_c_function_load '
                else:
                    param = param + ' --first mr_c_function_load'
                    param = param + ' --entry mr_c_function_load '
            else:
                param = param + '-ropi -rwpi'
                param = param + ' "-ro-base" 0x80000'
                param = param + ' -remove '
                if MR_C_Compiler != 'thumb':
                    param = param + ' -first mr_c_function_load'
                    param = param + ' -entry mr_c_function_load '
                elif bmp_mode == 2:
                    param = param + ' -first mr_c_function_load_thumb'
                    param = param + ' -entry mr_c_function_load_thumb '
                else:
                    param = param + ' -first mr_c_function_load'
                    param = param + ' -entry mr_c_function_load '
        else:
            param = param + ' "-ro-base" ' + c_address + ''
            if MR_C_Compiler != 'thumb':
                param = param + ' -first mr_c_function_load '
            else:
                param = param + ' -first mr_c_function_load_thumb'
    else:
        param = param + ' -scatter ' + c_scatter + ' '
        if MR_C_Compiler != 'thumb':
            param = param + ' -entry mr_c_function_load '
        else:
            param = param + ' -entry mr_c_function_load_thumb '
    if RAM_Address == None:
        pass
    else:
        param = param + ' "-rw-base" ' + RAM_Address + ' '
    if DEBUG_MOD or WITH_C_MAP:
        if project['plat'] == 'mstar':
            param = param + ' ' + '--map --info sizes,totals,veneers --xref --symbols --list ' + extname + '.txt'
        else:
            param = param + ' ' + '-map -info sizes,totals,veneers -xref -symbols -list ' + extname + '.txt'
    param = param + '  -o '
    param = param + temp_file
    param = param + ' ' + filelist
    if bmp_mode == 2:
        helper_lib = 'mr_helpersp'
    elif project['plat'] == 'via':
        helper_lib = 'mr_helperv4'
    elif project['plat'] == 'mstar':
        helper_lib = 'mr_helpermstar'
    else:
        helper_lib = 'mr_helper'
    if MR_C_Compiler == 'thumb':
        helper_lib = helper_lib + 't'
    auth_infoprint(param)
    if c_helper == True:
        base_helper_lib = helper_lib
        if project['plugin_now'] == 'plugin':
            base_helper_lib = helper_lib + 'pluginext'
        elif project['plugin_now'] in ('app', 'appdev'):
            base_helper_lib = helper_lib + 'pluginapp'
        elif project['plugin_now'] == 'speed':
            base_helper_lib = helper_lib + 'pluginspeed'
        elif project['plugin_now'] == 'main':
            base_helper_lib = helper_lib + 'pluginmain'
        elif project['plugin_now'] == 'mainns':
            base_helper_lib = helper_lib + 'pluginmainns'
        elif project['plugin_now'] == 'reg':
            base_helper_lib = helper_lib + 'pluginreg'
        elif project['sdk_stack'] == 1:
            base_helper_lib = helper_lib + 'stack'
        elif project['sms_indication'] == 1:
            base_helper_lib = helper_lib + 'sms'
        if mr_authorization == 'mr':
            param = param + ' ' + builder_path + base_helper_lib + '.lib(mr_helper.o) '
            param = param + ' ' + builder_path + base_helper_lib + '.lib '
        else:
            param = param + ' ' + builder_path + base_helper_lib + '.lib(mr_helper.o) '
            param = param + ' ' + builder_path + base_helper_lib + '.lib(mr_helper_s.o) '
            param = param + ' ' + builder_path + helper_lib + 'exf.lib '
        if project['plugin_now'] in ('app', 'speed'):
            param = param + builder_path + helper_lib + 'exbnp.lib '
            param = param + builder_path + helper_lib + 'exbev.lib '
        elif project['plugin_now'] in ('main', 'mainns', 'reg', 'plugin', 'appdev'):
            param = param + builder_path + helper_lib + 'exbnp.lib '
        else:
            param = param + builder_path + helper_lib + 'exb.lib '
    if MR_C_Compiler == 'thumb':
        if c_scatter == None:
            if with_c_global == True:
                if bmp_mode == 2:
                    param = param + ' ' + builder_path + helper_lib + 'exd.lib(mr_helper_thumb.o) '
                else:
                    param = param + ' ' + builder_path + helper_lib + 'exd.lib(mr_helper_thumb.o) '
            elif bmp_mode == 2:
                param = param + ' ' + builder_path + helper_lib + 'exc.lib(mr_helper_thumb.o) '
            else:
                param = param + ' ' + builder_path + helper_lib + 'exc.lib(mr_helper_thumb.o) '
        elif bmp_mode == 2:
            param = param + ' ' + builder_path + helper_lib + 'exe.lib(mr_helper_thumb.o) '
        else:
            param = param + ' ' + builder_path + helper_lib + 'exe.lib(mr_helper_thumb.o) '
    if project['c_flags']:
        param = param + ' ' + project['c_flags']
    auth_infoprint(param)
    try:
        ret = os.spawnlpe(os.P_WAIT, COMMAND_PATH + MR_LINK, param, armenv)
    except:
        infoprint('run armlink error!')
        raise

    if ret != 0:
        raise
    if c_scatter == None:
        extfile = os.environ['TMP'] + '\\mr_' + extname + '.ext'
    else:
        extfile = os.environ['TMP'] + '\\mr_' + extname
    param = ''
    if project['plat'] == 'mstar':
        param = param + ' --bin -o ' + extfile
    else:
        param = param + ' -bin -o ' + extfile
    param = param + ' ' + temp_file
    auth_infoprint(param)
    try:
        ret = os.spawnlpe(os.P_WAIT, COMMAND_PATH + MR_FROMELF, param, armenv)
    except:
        infoprint('run fromelf error!')
        raise

    if ret != 0:
        raise
    if c_scatter == None:
        data = get_file(extfile, 'rb')
        data = 'MRPGCMAP' + data
        if 'unzip' in fileparams:
            zip_data = data
        else:
            zip_data = zipfile(data)
        addfile2cache(extname + '.ext', zip_data, len(data))
    files = os.listdir(extfile)
    for f in files:
        data = get_file(extfile + '\\' + f, 'rb')
        debuginfo('before head len = ' + hex(len(data)))
        data = 'MRPGCMAP' + data
        if 'unzip' in fileparams:
            zip_data = data
        else:
            zip_data = zipfile(data)
        addfile2cache(f + '.ext', zip_data, len(data))

    return


def unpackfile_remove(filename, fileparams=[]):
    for fileparam in fileparams:
        m = re.match('^\\s*remove\\s*=\\s*%s\\s*' % filename, fileparam)
        if m != None:
            return True

    return False
    return


def unpackfile_filehead(fileparams=[]):
    for fileparam in fileparams:
        m = re.match('^\\s*remain_head\\s*', fileparam)
        if m != None:
            return True

    return False
    return


def unpackfile_rename(filename, fileparams=[]):
    for fileparam in fileparams:
        m = re.match('^\\s*rename\\s*=\\s*%s\\s*\\:\\s*(\\S+)' % filename, fileparam)
        if m != None:
            infoprint("rename '%s' as '%s'" % (filename, m.group(1)))
            return m.group(1)

    return filename
    return


def unpackfile(packfilename, fileparams=[]):
    global filehead
    data = get_file(packfilename, 'rb')
    (t1, headlen, t3, indexoffset) = struct.unpack('<IIII', data[:16])
    if unpackfile_filehead(fileparams):
        project['filehead'] = 1
    if headlen > 232:
        filehead = data[:indexoffset]
        indexlen = headlen + 8 - indexoffset
        pos = 0
        index = data[indexoffset:headlen + 8]
        debuginfo(index)
        while pos < indexlen:
            (filenamelen,) = struct.unpack('<I', index[pos:pos + 4])
            pos = pos + 4
            filename = index[pos:pos + filenamelen - 1]
            pos = pos + filenamelen
            (filestart, filelen) = struct.unpack('<II', index[pos:pos + 8])
            pos = pos + 12
            filename = unpackfile_rename(filename, fileparams)
            if unpackfile_remove(filename, fileparams):
                infoprint("remove '%s' in the pack '%s'" % (filename, packfilename))
            else:
                addfile2cache(filename, data[filestart:filestart + filelen])

    filehead = data[:headlen + 8]
    mrplen = len(data)
    pos = headlen + 8
    while pos < mrplen:
        (filenamelen,) = struct.unpack('<I', data[pos:pos + 4])
        pos = pos + 4
        filename = data[pos:pos + filenamelen]
        pos = pos + filenamelen
        (filelen,) = struct.unpack('<I', data[pos:pos + 4])
        pos = pos + 4
        filename = unpackfile_rename(filename, fileparams)
        if unpackfile_remove(filename, fileparams):
            infoprint("remove '%s' in the pack '%s'" % (filename, packfilename))
        else:
            addfile2cache(filename, data[pos:pos + filelen])
        pos = pos + filelen


def zipfile(data):
    global WITH_ZIP
    if WITH_ZIP:
        debuginfo('before zip len = ' + hex(len(data)))
        return mr.mrzip(data)
    else:
        return data


def getstr(s, l):
    s_len = len(s)
    if s_len >= l:
        return s[:l]
    else:
        return s + '\x00' * (l - s_len)


def get_str_from_mpr(section, key, report=True, default='default'):
    try:
        ret = project_config.get(section, key)
    except:
        if report:
            infoprint('Can not open project file "' + sys.argv[1] + '" or miss the key "' + key + '" in section "' + section + '"!')
            sys.exit(-1)
        else:
            ret = default

    return ret


def get_int_from_mpr(section, key, report=True, default=0):
    try:
        ret = project_config.getint(section, key)
    except:
        if report:
            infoprint('project file miss the key "' + key + '" in section "' + section + '"!')
            sys.exit(-1)
        else:
            ret = default

    return ret


def get_section_from_mpr(section, report=True, default=[]):
    try:
        ret = project_config.options(section)
    except:
        if report:
            infoprint('project file miss the section "' + section + '"!')
            sys.exit(-1)
        else:
            ret = default

    return ret


def readprojectconfig():
    config = get_str_from_mpr('information', 'config')
    debuginfo('information->config=' + config)
    project['config'] = config.split(',')


def buildfilehead(project_path):
    global filehead
    if project['visible'] == 0:
        flag = 0
    else:
        flag = 1
    if project['filehead'] == 1:
        return
    flag = flag + project['cpu'] * 2
    flag = flag + project['shell'] * 8
    filehead = 'MRPG'
    filehead = filehead + '\x00' * 4
    filehead = filehead + '\x00' * 4
    filehead = filehead + '\x00' * 4
    filehead = filehead + getstr(project['filename'], 12)
    filehead = filehead + getstr(project['appname'], 24)
    filehead = filehead + g_host_auth_str[2] + g_host_auth_str[4] + g_host_auth_str[8] + g_host_auth_str[9] + g_host_auth_str[11] + g_host_auth_str[12] + g_host_auth_str[1] + g_host_auth_str[7] + g_host_auth_str[6] + '\x00' * 7
    filehead = filehead + struct.pack('<i', project['appid'])
    filehead = filehead + struct.pack('<i', project['version'])
    filehead = filehead + struct.pack('<i', flag)
    filehead = filehead + struct.pack('<i', 10002)
    filehead = filehead + '\x00' * 4
    filehead = filehead + getstr(project['vendor'], 40)
    filehead = filehead + getstr(project['description'], 64)
    filehead = filehead + struct.pack('>i', project['appid'])
    filehead = filehead + struct.pack('>i', project['version'])
    filehead = filehead + '\x00' * 4
    filehead = filehead + struct.pack('<H', project['scr_w'])
    filehead = filehead + struct.pack('<H', project['scr_h'])
    if project['plat'] == 'mtk' or project['plat'] == 'mstar':
        filehead = filehead + struct.pack('<B', 1)
    elif project['plat'] == 'spreadtrum':
        filehead = filehead + struct.pack('<B', 2)
    else:
        filehead = filehead + struct.pack('<B', 0)
    filehead = filehead + '\x00' * 31
    if project['head_append'] != None:
        filehead = filehead + get_file(project_path + project['head_append'], 'rb')
    return


def adjustfilehead():
    global filehead
    filehead_len = len(filehead)
    debuginfo('adjustfilehead:filehead_len:' + str(len(filehead)))
    indexbuf_len = len(indexbuf)
    filesbuf_len = len(filesbuf)
    appinfo_len = filehead_len + indexbuf_len - 8
    index_pos = filehead_len
    file_len = filehead_len + indexbuf_len + filesbuf_len
    filehead = filehead[:4] + struct.pack('<i', appinfo_len) + struct.pack('<i', file_len) + struct.pack('<i', index_pos) + filehead[16:]
    crc = zlib.crc32(filehead + indexbuf + filesbuf)
    filehead = filehead[:84] + struct.pack('<i', crc) + filehead[88:]


def write_file(name, s, mode='w'):
    try:
        f = file(name, mode)
        try:
            f.write(s)
        finally:
            f.close()
    except:
        infoprint('Can not open file "' + name + '"!')
        raise


def packfiles():
    global MR_START_FILE
    global filesbuf
    global indexbuf
    index_len = 0
    for (filename, data, origin_len) in filecache:
        index_len = index_len + len(filename) + 1 + 16

    filehead_len = len(filehead)
    debuginfo('filehead_len:' + str(len(filehead)))
    filesbuf = ''
    indexbuf = ''
    filebuf_pos = filehead_len + index_len
    infoprint('%-*s%*s    %*s' % (30, '  File Name', 18, 'Size', 18, 'Origin Size'))
    for (filename, data, origin_len) in filecache:
        datasize = len(data) / 1024.0
        if origin_len < 0:
            origin_len_str = 'UNKNOW'
        else:
            origin_len_str = '%5.1f' % (origin_len / 1024.0)
        if filename == MR_START_FILE:
            pass
        elif filename == 'cfunction.ext':
            infoprint('%-*s%*s KB%*s KB' % (30, 'Main Module', 15, '%5.1f' % datasize, 15, origin_len_str))
        else:
            infoprint('%-*s%*s KB%*s KB' % (30, filename, 15, '%5.1f' % datasize, 15, origin_len_str))
        name_len = len(filename) + 1
        data_len = len(data)
        name_buf = struct.pack('<i', name_len) + filename + '\x00'
        filesbuf = filesbuf + name_buf + struct.pack('<i', data_len) + data
        filebuf_pos = filebuf_pos + len(name_buf) + 4
        indexbuf = indexbuf + name_buf + struct.pack('<iii', filebuf_pos, data_len, 0)
        filebuf_pos = filebuf_pos + data_len

    return indexbuf + filesbuf


def get_file(filename, mode='r'):
    try:
        f = file(filename, mode)
        try:
            data = f.read()
        finally:
            f.close()
    except:
        infoprint('can not open file "' + filename + '"')
        sys.exit(-1)

    return data


def compliecfile(src_file, obj_file, with_c_global, c_address, c_helper, local_cdefine_map, local_cinclude_map, local_filecache=None, exram_fix=None, cpu='ARM7EJ-S'):
    global MR_C_Optimization_Lever
    global MR_C_Optimization_Type
    param = ''
    if MR_C_Compiler == 'thumb':
        if src_file[-2:] == '.c':
            command = 'tcc'
        else:
            command = 'tcpp'
        if project['plat'] == 'mstar':
            param = param + ' --thumb '
    elif src_file[-2:] == '.c':
        command = 'armcc'
    else:
        command = 'armcpp'
    param = param + '-c -I. -c '
    if MR_C_Optimization_Lever != 'none':
        param = param + '-O' + MR_C_Optimization_Lever + ' '
    else:
        param = param + '-O2 '
    if MR_C_Optimization_Type != 'none':
        param = param + '-O' + MR_C_Optimization_Type + ' '
    else:
        param = param + '-Otime '
    if exram_fix == None:
        if MR_C_Compiler == 'thumb':
            if bmp_mode == 2:
                param = param + '-DGET_C_FUNCTION_P()=(*(((mr_c_function_st**)mr_c_function_load_thumb)-1)) '
                param = param + '-DGET_HELPER()=(*(((mr_table**)mr_c_function_load_thumb)-2)) '
            else:
                param = param + '-DGET_C_FUNCTION_P()=(*(((mr_c_function_st**)mr_c_function_load)-1)) '
                param = param + '-DGET_HELPER()=(*(((mr_table**)mr_c_function_load)-2)) '
        else:
            param = param + '-DGET_C_FUNCTION_P()=(*(((mr_c_function_st**)mr_c_function_load)-1)) '
            param = param + '-DGET_HELPER()=(*(((mr_table**)mr_c_function_load)-2)) '
    else:
        param = param + '-DGET_C_FUNCTION_P()=(*(((mr_c_function_st**)' + exram_fix + ')+1)) '
        param = param + '-DGET_HELPER()=(*(((mr_table**)' + exram_fix + '))) '
    param = param + get_cdefine(local_cdefine_map)
    param = param + get_cinclude(local_cinclude_map)
    if with_c_global == True:
        if c_address == None:
            if bmp_mode == 2:
                param = param + '-DMR_SPREADTRUM_MOD -DMR_BIG_ENDIAN -bi -apcs /ropi/rwpi/interwork/swst -fy -fa -zo '
            elif project['plat'] == 'mstar':
                param = param + '--apcs /ropi/rwpi/interwork --bss_threshold=0 --cpu 5TEJ --fpu softvfp --min_array_alignment=4 --split_sections '
            else:
                param = param + '-cpu ' + cpu + ' -littleend -apcs /ropi/rwpi/interwork -fa -zo '
        elif bmp_mode == 2:
            param = param + '-DMR_SPREADTRUM_MOD -DMR_BIG_ENDIAN -bi -fy -fa -zo '
            param = param + '-apcs /interwork/swst '
        else:
            param = param + '-cpu ' + cpu + ' -littleend -fa -zo '
            param = param + '-apcs /interwork '
    elif bmp_mode == 2:
        param = param + '-DMR_SPREADTRUM_MOD -DMR_BIG_ENDIAN -bi -apcs /ropi/interwork/norwpi/swst -fy -fa -zo '
    else:
        param = param + '-cpu ' + cpu + ' -littleend -apcs /ropi/interwork/norwpi -fa -zo '
    param = param + '-o '
    param = param + obj_file
    param = param + ' ' + src_file
    auth_infoprint(param)
    auth_infoprint(COMMAND_PATH + command)
    addcfile2cache(obj_file, local_filecache)
    try:
        ret = os.spawnlpe(os.P_WAIT, COMMAND_PATH + command, param, armenv)
    except:
        infoprint('run armcc error!')
        raise

    if ret != 0:
        raise
    return


def compliesfile(src_file, obj_file, with_c_global, c_address, c_helper, local_filecache=None):
    param = ''
    param = param + ' ' + src_file + ' '
    if with_c_global == True:
        if c_address == None:
            if bmp_mode == 2:
                param = param + '-bi -apcs /ropi/interwork/rwpi/swst '
            else:
                param = param + '-apcs /rwpi/interwork/ropi '
        elif bmp_mode == 2:
            param = param + '-bi -apcs /interwork '
        else:
            param = param + '-apcs /interwork '
    elif bmp_mode == 2:
        param = param + '-bi -apcs /ropi/interwork/norwpi '
    else:
        param = param + '-apcs /ropi/interwork/norwpi '
    param = param + '-o '
    param = param + obj_file
    auth_infoprint(param)
    addcfile2cache(obj_file, local_filecache)
    try:
        ret = os.spawnlpe(os.P_WAIT, COMMAND_PATH + 'armasm', param, armenv)
    except:
        infoprint('run armasm error!')
        raise

    if ret != 0:
        raise
    return


def compileextfile(extconfig, extname, project_path, fileparams, cpu):
    global WITH_PLUGGIN
    name = extconfig[:-4]
    with_c_global = get_str_from_mpr('config_' + name, 'with_c_global', False, WITH_C_GLOBAL)
    if with_c_global == 'false':
        with_c_global = False
    else:
        with_c_global = True
    c_address = get_str_from_mpr('config_' + name, 'c_address', False, C_Address)
    c_helper = get_str_from_mpr('config_' + name, 'with_c_helper', False, WITH_C_HELPER)
    exram_fix = get_str_from_mpr('config_' + name, 'exram_fix', False, None)
    project['plugin_now'] = get_str_from_mpr('config_' + name, 'plugin', False, project['plugin'])
    if WITH_PLUGGIN:
        if project['plugin_now'] == 'normal':
            infoprint("Can not compile a pluggin ext without 'pluggin' setting!")
            raise
    if (project['plugin_now'] == 'main' or project['plugin_now'] == 'mainns') and not (extname == 'cfunction.ext' or extname == 'logo.ext'):
        infoprint("Can not compile a sub ext with 'main' config!")
        raise
    if c_helper == 'false' or c_helper == False:
        c_helper = False
    else:
        c_helper = True
    c_scatter = get_str_from_mpr('config_' + name, 'c_scatter', False, None)
    files = get_section_from_mpr('files_' + name)
    localfilecahe = []
    for f in files:
        filename = get_str_from_mpr('files_' + name, f, False)
        filename = string.lower(filename)
        if filename[-2:] == '.c' or filename[-4:] == '.cpp':
            infoprint('compiling c\\c++ file ' + filename + '...')
            obj_file = os.environ['TMP'] + '\\mr_' + string.replace(filename[:-2], '\\', '_') + '.o'
            compliecfile(filename, obj_file, with_c_global, c_address, c_helper, cdefine_map, cinclude_map, localfilecahe, exram_fix, cpu)
        elif filename[-2:] == '.s':
            infoprint('compiling asm file ' + filename + '...')
            obj_file = os.environ['TMP'] + '\\mr_' + string.replace(filename[:-2], '\\', '_') + '.o'
            compliesfile(filename, obj_file, with_c_global, c_address, c_helper, localfilecahe)
        elif filename[-4:] == '.lib':
            addcfile2cache(filename, localfilecahe)

    dealcfiles(project_path, with_c_global, c_address, c_helper, localfilecahe, extname[:-4], c_scatter, exram_fix, fileparams)
    return


def unique(s):
    u = []
    for x in s:
        if x not in u:
            u.append(x)

    return u


def get_name(s):
    m = re.match('^([^\\(]+)', s)
    if m != None:
        return m.group(1)
    else:
        return s
    return


def get_params(s):
    m = re.search('\\s*\\(\\s*([^\\(\\)]+)\\s*', s)
    if m != None:
        return string.split(m.group(1), ',')
    else:
        return []
    return


def buildproject(projectfile):
    global ADD_FILE
    global ADD_SINGLE_FILE
    global APP_ID
    global ARMCPU
    global BMP_SUPPORT
    global COMMAND_PATH
    global FILE_NAME
    global MR_C_Compiler
    global MR_C_Optimization_Lever
    global MR_C_Optimization_Type
    global MR_EXT
    global OUTPUT_FILE
    global WITH_C_HELPER
    global WITH_START
    global WITH_ZIP
    global armenv
    global bmp_mode
    global cfilecache
    global filecache
    project_path = extractFileDir(projectfile) + '\\'
    armenv = copy.deepcopy(os.environ)
    armenv['LM_LICENSE_FILE'] = 'license.dat'
    commandline_define = copy.deepcopy(define_map)
    commandline_cdefine = copy.deepcopy(cdefine_map)
    commandline_cinclude = copy.deepcopy(cinclude_map)
    readprojectconfig()
    for config_real in project['config']:
        config = get_str_from_mpr('config_' + config_real, 'config', False, config_real)
        ResetDefine(commandline_define, commandline_cdefine, commandline_cinclude)
        project['plat'] = get_str_from_mpr('config_' + config_real, 'plat', False, get_str_from_mpr('config_' + config, 'plat', False, get_str_from_mpr('information', 'plat', False, 'none')))
        if project['plat'] == 'none':
            bmp_config = get_str_from_mpr('config_' + config_real, 'bmp_mode', False, get_str_from_mpr('config_' + config, 'bmp_mode', False, get_str_from_mpr('information', 'bmp_mode', False, 'normal')))
            if bmp_config == 'spreadtrum':
                bmp_mode = 2
            else:
                bmp_mode = 0
        elif project['plat'] == 'spreadtrum':
            bmp_mode = 2
        elif project['plat'] == 'via':
            bmp_mode = 0
            ARMCPU = 'ARM7TDMI'
        elif project['plat'] == 'mstar':
            bmp_mode = 0
            armenv['LM_LICENSE_FILE'] = armenv['RVCT22BIN'] + '/license.dat'
            COMMAND_PATH = armenv['RVCT22BIN'] + '/'
        else:
            bmp_mode = 0
        output_format_config = get_str_from_mpr('config_' + config_real, 'output_format', False, get_str_from_mpr('config_' + config, 'output_format', False, get_str_from_mpr('information', 'output_format', False, 'none')))
        infoprint('dealing ' + config_real + '(' + config + ')' + ' config...')
        MR_C_Optimization_Lever = get_str_from_mpr('config_' + config_real, 'optimization_lever', False, get_str_from_mpr('config_' + config, 'optimization_lever', False, get_str_from_mpr('information', 'optimization_lever', False, 'none')))
        cpu = get_str_from_mpr('config_' + config_real, 'armcpu', False, get_str_from_mpr('config_' + config, 'armcpu', False, get_str_from_mpr('information', 'armcpu', False, ARMCPU)))
        MR_C_Optimization_Type = get_str_from_mpr('config_' + config_real, 'optimization_type', False, get_str_from_mpr('config_' + config, 'optimization_type', False, get_str_from_mpr('information', 'optimization_type', False, 'none')))
        MR_C_Compiler = get_str_from_mpr('config_' + config_real, 'c_compiler', False, get_str_from_mpr('config_' + config, 'c_compiler', False, get_str_from_mpr('information', 'c_compiler', False, 'arm')))
        project['c_flags'] = get_str_from_mpr('config_' + config_real, 'c_flags', False, get_str_from_mpr('config_' + config, 'c_flags', False, get_str_from_mpr('information', 'c_flags', False, None)))
        outputfile = get_str_from_mpr('config_' + config_real, 'output', False, get_str_from_mpr('config_' + config, 'output', False, get_str_from_mpr('information', 'output', False, OUTPUT_FILE)))
        project['sdk_stack'] = get_int_from_mpr('config_' + config_real, 'sdk_stack', False, get_int_from_mpr('config_' + config, 'sdk_stack', False, get_int_from_mpr('information', 'sdk_stack', False, 0)))
        project['plugin'] = get_str_from_mpr('config_' + config_real, 'plugin', False, get_str_from_mpr('config_' + config, 'plugin', False, get_str_from_mpr('information', 'plugin', False, 'normal')))
        project['scr_w'] = get_int_from_mpr('config_' + config_real, 'scr_w', False, get_int_from_mpr('config_' + config, 'scr_w', False, get_int_from_mpr('information', 'scr_w', False, 0)))
        project['scr_h'] = get_int_from_mpr('config_' + config_real, 'scr_h', False, get_int_from_mpr('config_' + config, 'scr_h', False, get_int_from_mpr('information', 'scr_h', False, 0)))
        project['sms_indication'] = get_int_from_mpr('config_' + config_real, 'sms_indication', False, get_int_from_mpr('config_' + config, 'sms_indication', False, get_int_from_mpr('information', 'sms_indication', False, 0)))
        project['head_append'] = get_str_from_mpr('config_' + config_real, 'head_append', False, get_str_from_mpr('config_' + config, 'head_append', False, get_str_from_mpr('information', 'head_append', False, None)))
        project['visible'] = get_int_from_mpr('config_' + config_real, 'visible', False, get_int_from_mpr('config_' + config, 'visible', False, get_int_from_mpr('information', 'visible', False, 1)))
        project['cpu'] = get_int_from_mpr('config_' + config_real, 'cpu', False, get_int_from_mpr('config_' + config, 'cpu', False, get_int_from_mpr('information', 'cpu', False, 1)))
        project['shell'] = get_int_from_mpr('config_' + config_real, 'shell', False, get_int_from_mpr('config_' + config, 'shell', False, get_int_from_mpr('information', 'shell', False, 0)))
        project['filename'] = get_str_from_mpr('config_' + config_real, 'filename', False, get_str_from_mpr('config_' + config, 'filename', False, get_str_from_mpr('information', 'filename', False, FILE_NAME)))
        project['appname'] = get_str_from_mpr('config_' + config_real, 'appname', False, get_str_from_mpr('config_' + config, 'appname', False, get_str_from_mpr('information', 'appname')))
        project['appid'] = get_int_from_mpr('config_' + config_real, 'appid', False, get_int_from_mpr('config_' + config, 'appid', False, get_int_from_mpr('information', 'appid', False, APP_ID)))
        project['version'] = get_int_from_mpr('config_' + config_real, 'version', False, get_int_from_mpr('config_' + config, 'version', False, get_int_from_mpr('information', 'version')))
        project['vendor'] = get_str_from_mpr('config_' + config_real, 'vendor', False, get_str_from_mpr('config_' + config, 'vendor', False, get_str_from_mpr('information', 'vendor')))
        project['description'] = get_str_from_mpr('config_' + config_real, 'description', False, get_str_from_mpr('config_' + config, 'description', False, get_str_from_mpr('information', 'description')))
        project['loader'] = get_str_from_mpr('config_' + config_real, 'loader', False, get_str_from_mpr('config_' + config, 'loader', False, get_str_from_mpr('information', 'loader', False, 'mr')))
        define_config = get_str_from_mpr('config_' + config_real, 'define', False, get_str_from_mpr('config_' + config, 'define', False, get_str_from_mpr('information', 'define', False, '')))
        if mr_authorization == 'mr':
            pass
        else:
            define_config = 'MRC_CP_MOD,' + define_config
        define_config = re.sub('\\(\\$_VERSION\\)', str(project['version']), define_config)
        define_configs = define_config.split(',')
        for define in define_configs:
            AddDefine(define)

        include_config = get_str_from_mpr('config_' + config_real, 'include', False, get_str_from_mpr('config_' + config, 'include', False, get_str_from_mpr('information', 'include', False, '')))
        include_configs = include_config.split(',')
        for include in include_configs:
            AddInclude(include)

        project['files'] = get_section_from_mpr('files')
        project['files'] = project['files'] + get_section_from_mpr('files_' + config, False)
        project['files'] = project['files'] + ADD_SINGLE_FILE
        project['files'] = unique(project['files'])
        project['filehead'] = None
        with_c_global = get_str_from_mpr('config_' + config, 'with_c_global', False, get_str_from_mpr('information', 'with_c_global', False, WITH_C_GLOBAL))
        if with_c_global == 'false' or with_c_global == False:
            with_c_global = False
        else:
            with_c_global = True
        c_address = get_str_from_mpr('config_' + config, 'c_address', False, get_str_from_mpr('information', 'c_address', False, C_Address))
        c_helper = get_str_from_mpr('config_' + config, 'with_c_helper', False, get_str_from_mpr('information', 'with_c_helper', False, WITH_C_HELPER))
        with_zip = get_str_from_mpr('config_' + config, 'zip', False, get_str_from_mpr('information', 'zip', False, WITH_ZIP))
        exram_fix = get_str_from_mpr('config_' + config, 'exram_fix', False, get_str_from_mpr('information', 'exram_fix', False, None))
        if exram_fix != None:
            AddDefine('EXRAM_FIX=' + exram_fix)
        if c_helper == 'false' or c_helper == False:
            c_helper = False
            WITH_C_HELPER = False
        else:
            c_helper = True
            WITH_C_HELPER = True
        if with_zip == 'false' or with_zip == False:
            WITH_ZIP = False
        else:
            WITH_ZIP = True
        c_scatter = get_str_from_mpr('config_' + config, 'c_scatter', False, None)
        filecache = []
        cfilecache = []
        if WITH_START == True:
            mr_compilev2.init_compile(copy.deepcopy(define_map))
            lines = get_start_lines()
            data = mr_compilev2.complie(MR_START_FILE, lines)
            zip_data = zipfile(data)
            addfile2cache(MR_START_FILE, zip_data, len(data))
        if c_helper and (project['plugin'] == 'normal' or project['plugin'] == 'main' or project['plugin'] == 'mainns'):
            if project['plat'] == 'mstar' and project['loader'] == 'c':
                infoprint("Warnning:Mstar mode don't support c loader!")
                project['loader'] = 'mr'
            if mr_authorization != 'mr':
                if project['loader'] == 'c':
                    mr_helper_filename = '\\mr_helperk.mrp'
                elif project['loader'] == 'cbuf':
                    mr_helper_filename = '\\mr_helpero.mrp'
                else:
                    mr_helper_filename = '\\mr_helpere.mrp'
            elif project['loader'] == 'c':
                if project['shell'] == 1 and mr_authorization == 'mr':
                    if project['plat'] == 'via':
                        mr_helper_filename = '\\mr_helperv4s1c.mrp'
                    elif bmp_mode == 2:
                        mr_helper_filename = '\\mr_helperg.mrp'
                    else:
                        mr_helper_filename = '\\mr_helperd.mrp'
                elif project['shell'] == 3421 and mr_authorization == 'mr':
                    if project['plat'] == 'via':
                        mr_helper_filename = '\\mr_helperv4s3c.mrp'
                    elif bmp_mode == 2:
                        mr_helper_filename = '\\mr_helperj.mrp'
                    else:
                        mr_helper_filename = '\\mr_helperi.mrp'
                elif bmp_mode == 2:
                    mr_helper_filename = '\\mr_helperf.mrp'
                else:
                    mr_helper_filename = '\\mr_helperc.mrp'
            elif project['loader'] == 'cbuf':
                mr_helper_filename = '\\mr_helpern.mrp'
            elif project['loader'] == 'logo':
                mr_helper_filename = '\\mr_helperl.mrp'
            elif project['loader'] == 'fix':
                mr_helper_filename = '\\mr_helperm.mrp'
            elif project['shell'] == 1 and mr_authorization == 'mr':
                mr_helper_filename = '\\mr_helperb.mrp'
            elif project['shell'] == 3421 and mr_authorization == 'mr':
                mr_helper_filename = '\\mr_helperh.mrp'
            else:
                mr_helper_filename = '\\mr_helper.mrp'
            unpackfile(builder_path + mr_helper_filename)
        fileparams = []
        if ADD_FILE:
            filename_params = string.lower(ADD_FILE)
            filename = get_name(filename_params)
            fileparams = get_params(filename_params)
            unpackfile(filename, fileparams)
        for f in project['files']:
            filename_params = get_str_from_mpr('files_' + config, f, False, get_str_from_mpr('files', f, False, f))
            filename_params = string.lower(filename_params)
            filename = get_name(filename_params)
            fileparams = get_params(filename_params)
            filename_in_mrp = filename
            for fileparam in fileparams:
                m = re.match('^\\s*name\\s*=\\s*([\\w\\.]+)\\s*', fileparam)
                if m != None:
                    filename_in_mrp = m.group(1)

            if (filename[-3:] == MR_EXT or filename[-3:] == '.mr') and mr_authorization == 'mr':
                infoprint('compiling mr file ' + filename + '...')
                mr_compilev2.init_compile(copy.deepcopy(define_map))
                mr_compilev2.set_compile_info(project_path + filename, 0)
                lines = mr_compilev2.get_file_lines(project_path + filename)
                data = mr_compilev2.complie(project_path + filename, lines)
                if 'unzip' in fileparams:
                    zip_data = data
                else:
                    zip_data = zipfile(data)
                addfile2cache(filename_in_mrp, zip_data, len(data))
            elif (filename[-3:] == MR_EXT or filename[-3:] == '.mr') and mr_authorization != 'mr':
                infoprint('Warnning: Authorization is required for mythroad file ' + filename + '!')
                raise
            elif filename[-4:] == '.bmp' and BMP_SUPPORT:
                infoprint('compile bmp file ' + filename + '...')
                data = get_file(project_path + filename, 'rb')
                data = mr.bmpconvert(data, bmp_mode)
                if 'unzip' in fileparams:
                    zip_data = data
                else:
                    zip_data = zipfile(data)
                addfile2cache(filename_in_mrp, zip_data, len(data))
            elif filename[-2:] == '.c' or filename[-4:] == '.cpp':
                infoprint('compiling c\\c++ file ' + filename + '...')
                obj_file = os.environ['TMP'] + '\\mr_' + string.replace(filename[:-2], '\\', '_') + '.o'
                compliecfile(filename, obj_file, with_c_global, c_address, c_helper, cdefine_map, cinclude_map, None, exram_fix, cpu)
            elif filename[-2:] == '.s':
                infoprint('compiling asm file ' + filename + '...')
                obj_file = os.environ['TMP'] + '\\mr_' + string.replace(filename[:-2], '\\', '_') + '.o'
                compliesfile(filename, obj_file, with_c_global, c_address, c_helper)
            elif filename[-4:] == '.mrp' and not 'packing' in fileparams:
                infoprint('compile mrp file ' + filename + '...')
                unpackfile(filename, fileparams)
            elif filename[-4:] == '.ext':
                infoprint('compile ext file ' + filename + '...')
                compileextfile(filename, filename_in_mrp, project_path, fileparams, cpu)
            elif filename[-4:] == '.mrh':
                pass
            elif filename[-4:] == '.lib':
                addcfile2cache(filename)
            else:
                infoprint('compile resource file ' + filename + '...')
                data = get_file(project_path + filename, 'rb')
                if len(data) > 512 * 1024:
                    infoprint('file "' + filename + '"' + 'is too big!')
                    sys.exit(-1)
                if 'unzip' in fileparams:
                    zip_data = data
                else:
                    zip_data = zipfile(data)
                addfile2cache(filename_in_mrp, zip_data, len(data))

        if output_format_config == 'lib':
            outputfile = dealoutputfile(outputfile, project['version'])
            if string.find(outputfile, ':') != -1:
                dealclib(project_path, outputfile)
            else:
                dealclib(project_path, project_path + outputfile)
        else:
            project['plugin_now'] = project['plugin']
            dealcfiles(project_path, with_c_global, c_address, c_helper, None, 'cfunction', c_scatter, exram_fix, [])
            buildfilehead(project_path)
            data = packfiles()
            adjustfilehead()
            data = filehead + data
            outputfile = dealoutputfile(outputfile, project['version'])
            if string.find(outputfile, ':') != -1:
                write_file(outputfile, data, 'wb')
            else:
                write_file(project_path + outputfile, data, 'wb')

    return


def dealoutputfile(filename, ver):
    s = filename
    s = re.sub('\\(\\$_DATE\\)', time.strftime('%Y%m%d%H%M'), s)
    s = re.sub('\\(\\$_YYMMDD\\)', time.strftime('%y%m%d'), s)
    s = re.sub('\\(\\$_VERSION\\)', str(ver), s)
    m = re.search('\\(\\$(\\w+)\\)', s)
    while m != None:
        k = m.group(1)
        debuginfo('deal a output macro ' + k)
        if define_map.has_key(k):
            if define_map[k] == '$$MR_COMMAND_LINE_DEFINE$$':
                s = re.sub('\\(\\$(' + k + ')\\)', 'Y', s)
            else:
                s = re.sub('\\(\\$(' + k + ')\\)', define_map[k], s)
        else:
            s = re.sub('\\(\\$(' + k + ')\\)', 'N', s)
        debuginfo(s)
        m = re.search('\\(\\$(\\w+)\\)', s)

    return s
    return


def get_cdefine(c_map):
    d = ''
    for s in c_map:
        d = d + '-D' + s + ' '

    return d


def get_cinclude(c_include):
    d = ''
    for s in c_include:
        d = d + '-I' + s + ' '

    return d


def SetDefine(name, value):
    define_map[name] = value


def ResetDefine(commandline_define, commandline_cdefine, commandline_cinclude):
    global cdefine_map
    global cinclude_map
    global define_map
    define_map = copy.deepcopy(commandline_define)
    cdefine_map = copy.deepcopy(commandline_cdefine)
    cinclude_map = copy.deepcopy(commandline_cinclude)


from netbios import *
import md5

mr_authorizationstrings = ['c5d19b7c3fb6ec74b9885c830c43b3e9']
cp_authorizationstrings = ['166a07fa8ea3404f6afc8daf32eabe54']
mr_auth_check = '021ec93a70c1e14b3ee6bcdbfbe13c'
mr_authorization = 'cp'

def getauthorizationstrings():
    ret = []
    ncb = NCB()
    ncb.Command = NCBENUM
    la_enum = LANA_ENUM()
    ncb.Buffer = la_enum
    rc = Netbios(ncb)
    if rc != 0:
        mrpbuilder.infoprint('Unexpected result %d' % (rc,))
        raise
    for i in range(la_enum.length):
        ncb.Reset()
        ncb.Command = NCBRESET
        ncb.Lana_num = ord(la_enum.lana[i])
        rc = Netbios(ncb)
        if rc != 0:
            mrpbuilder.infoprint('Unexpected result %d' % (rc,))
            raise
        ncb.Reset()
        ncb.Command = NCBASTAT
        ncb.Lana_num = ord(la_enum.lana[i])
        ncb.Callname = '*               '
        adapter = ADAPTER_STATUS()
        ncb.Buffer = adapter
        Netbios(ncb)
        auth_str = md5.new(adapter.adapter_address).digest()
        auth_str = mr.mrencode(auth_str)
        auth_str = md5.new(auth_str).hexdigest()
        ret.append(auth_str)

    return ret


def getauthorizationstrings01():
    ret = []
    ncb = NCB()
    ncb.Command = NCBENUM
    la_enum = LANA_ENUM()
    ncb.Buffer = la_enum
    rc = Netbios(ncb)
    if rc != 0:
        mrpbuilder.infoprint('Unexpected result %d' % (rc,))
        raise
    for i in range(la_enum.length):
        ncb.Reset()
        ncb.Command = NCBRESET
        ncb.Lana_num = ord(la_enum.lana[i])
        rc = Netbios(ncb)
        if rc != 0:
            mrpbuilder.infoprint('Unexpected result %d' % (rc,))
            raise
        ncb.Reset()
        ncb.Command = NCBASTAT
        ncb.Lana_num = ord(la_enum.lana[i])
        ncb.Callname = '*               '
        adapter = ADAPTER_STATUS()
        ncb.Buffer = adapter
        Netbios(ncb)
        auth_str = md5.new(adapter.adapter_address).digest()
        auth_str = mr.mrencode(auth_str)
        auth_str = auth_str + str(win32api.GetVolumeInformation('c:\\')[1])
        auth_str = md5.new(auth_str).hexdigest()
        ret.append(auth_str)

    return ret


def checkauthorization():
    global AUTH_SUCP
    global cp_authorizationstrings
    global g_host_auth_str
    global mr_authorization
    global mr_authorizationstrings
    authorizationstrings01 = getauthorizationstrings01()
    try:
        for auth_str in cp_authorizationstrings:
            for host_auth_str in authorizationstrings01:
                if auth_str == host_auth_str:
                    g_host_auth_str = host_auth_str
                    mr_authorization = 'cp'
                    return True

        for auth_str in mr_authorizationstrings:
            for host_auth_str in authorizationstrings01:
                if auth_str == host_auth_str:
                    g_host_auth_str = host_auth_str
                    mr_authorization = 'mr'
                    if AUTH_SUCP:
                        print 'SUCP: The privilege level is degraged from dev to cp mode.'
                        mr_authorization = 'cp'
                    return True

        infoprint('Authorization String:')
        for host_auth_str in authorizationstrings01:
            infoprint(host_auth_str)

        raise
    except:
        raise


def checkauthorizationprt():
    global AUTH_PRT
    auth = md5.new()
    try:
        for auth_str in mr_authorizationstrings:
            auth.update(auth_str)

        for auth_str in cp_authorizationstrings:
            auth.update(auth_str)

        if AUTH_PRT:
            debuginfo(auth.hexdigest())
        if auth.hexdigest()[:-2] != mr_auth_check:
            raise
    except:
        raise


help_info = '\n  Mythroad\xb1\xe0\xd2\xeb\xb9\xa4\xbe\xdf  V1011\n  \xca\xb9\xd3\xc3\xc0\xfd\n  mrpbuilder.exe dsm.mpr\n  \xb2\xce\xca\xfd\xcb\xb5\xc3\xf7\n  -h           \xb0\xef\xd6\xfa\xa3\xbb\n  \xb7\xb5\xbb\xd8\xc0\xe0\xd0\xcd\xa3\xba\n  0     \xc9\xfa\xb3\xc9\xb3\xc9\xb9\xa6\xa1\xa3\n  <0    \xca\xa7\xb0\xdc\xa1\xa3\n'

def usage():
    global help_info
    infoprint(help_info)


def init_build():
    global cdefine_map
    global cfilecache
    global cinclude_map
    global define_map
    global filecache
    global filehead
    global project
    define_map = {}
    filecache = []
    filehead = ''
    project = {}
    cfilecache = []
    cdefine_map = []
    cinclude_map = []


def AddDefine(a):
    if a != '':
        macro_set = a.split('=', 1)
        if len(macro_set) < 2:
            SetDefine(macro_set[0], '$$MR_COMMAND_LINE_DEFINE$$')
        else:
            SetDefine(macro_set[0], macro_set[1])
        cdefine_map.append(a)
        debuginfo('macro_set:')
        debuginfo(str(macro_set))


def AddInclude(a):
    if a != '':
        cinclude_map.append(a)
        debuginfo('include:')
        debuginfo(str(a))


def parseoptions():
    global ADD_FILE
    global ADD_SINGLE_FILE
    global APP_ID
    global AUTH_PRT
    global AUTH_SUCP
    global BMP_SUPPORT
    global C_Address
    global DEBUG_MOD
    global FILE_NAME
    global MR_EXT
    global OUTPUT_FILE
    global RAM_Address
    global WITH_C_GLOBAL
    global WITH_C_HELPER
    global WITH_C_MAP
    global WITH_PLUGGIN
    global WITH_START
    global WITH_ZIP
    global builder_path
    builder_path = extractFileDir(sys.argv[0]) + '\\'
    try:
        (opts, args) = getopt.getopt(sys.argv[2:], 'd:hl:rf:o:a:', ['sucp', 'define=', 'mythroadtestmode', 'withoutsart', 'withsart', 'withoutdefine', 'bmpsupport', 'help', 'ziplevel=', 'release', 'without_zip', 'without_c_global', 'without_c_helper', 'with_c_map', 'c_address=', 'ram_address=', 'ram_address_time=', 'file=', 'output=', 'pluggin', 'c3c', 'filename=', 'appid=', 'add='])
    except getopt.GetoptError:
        infoprint('\xb2\xce\xca\xfd\xb4\xed\xce\xf3!')
        usage()
        sys.exit(-1)

    debuginfo(opts)
    try:
        for (o, a) in opts:
            if o in ('-h', '--help'):
                usage()
                sys.exit(0)
            if o in ('', '--mythroadtestmode'):
                DEBUG_MOD = True
                mr_compilev2.DEBUG_MOD = True
            if o in ('-f', '--file'):
                ADD_FILE = a
            if o in ('-o', '--output'):
                OUTPUT_FILE = a
            if o in ('-l', '--ziplevel'):
                mr.zipsetlevel(int(a))
            if o in ('-r', '--release'):
                mr.mr_set_release_version()
            if o in ('', '--withoutdefine'):
                mr_compilev2.WITHOUT_DEFINE_MOD = True
            if o in ('', '--bmpsupport'):
                BMP_SUPPORT = True
            if o in ('', '--withoutsart'):
                WITH_START = False
            if o in ('', '--without_zip'):
                WITH_ZIP = False
            if o in ('', '--without_c_global'):
                WITH_C_GLOBAL = False
            if o in ('', '--pluggin'):
                WITH_PLUGGIN = True
            if o in ('', '--without_c_helper'):
                WITH_C_HELPER = False
            if o in ('', '--with_c_map'):
                WITH_C_MAP = True
            if o in ('', '--c_address'):
                C_Address = a
            if o in ('', '--ram_address'):
                RAM_Address = a
            if o in ('', '--c3c'):
                MR_EXT = '.ct'
                MR_START_FILE = 'in.ct'
            if o in ('', '--withsart'):
                WITH_START = True
            if o in ('', '--ram_address_time'):
                if a == 'mythroad':
                    AUTH_PRT = True
            if o in ('-d', '--define'):
                debuginfo(a)
                AddDefine(a)
            if o in ('', '--filename'):
                FILE_NAME = a
            if o in ('', '--appid'):
                APP_ID = int(a)
            if o in ('-a', '--add'):
                ADD_SINGLE_FILE = ADD_SINGLE_FILE + [a]
            if o == '--sucp':
                AUTH_SUCP = True

    except:
        if DEBUG_MOD:
            raise
        else:
            infoprint('parse options error!')
            sys.exit(-1)


REG_TIME_KEY0 = 'International'
REG_TIME_KEY1 = 'sNativeColour'

def checkauthorizationtime():
    global REG_TIME_KEY0
    global REG_TIME_KEY1
    max_times = 30
    if mr_authorization == 'mr':
        max_times = 500
    elif mr_authorization == 'cp':
        max_times = 300
    root = _winreg.ConnectRegistry(None, _winreg.HKEY_CURRENT_USER)
    ControlKey = _winreg.CreateKey(root, 'Control Panel')
    ColorsKey = _winreg.CreateKey(ControlKey, REG_TIME_KEY0)
    try:
        value = _winreg.QueryValueEx(ColorsKey, REG_TIME_KEY1)
    except:
        if mr_authorization == 'mr':
            _winreg.SetValueEx(ColorsKey, REG_TIME_KEY1, 0, _winreg.REG_SZ, '212208200789')
            value = (u'212208200789', 1)
        else:
            _winreg.CloseKey(ColorsKey)
            _winreg.CloseKey(ControlKey)
            _winreg.CloseKey(root)
            raise

    v = str(value[0])
    if v == '212208200789':
        thistime = time.gmtime(time.time())
        v = u'' + str(random.randint(1100, 9899)) + str(max_times * 3 + 2437) + str(thistime[1] * 37 + thistime[2])
        v = str(zlib.adler32(v) % 8900 + 1000) + v
        _winreg.SetValueEx(ColorsKey, REG_TIME_KEY1, 0, _winreg.REG_SZ, v)
    else:
        thistime = time.gmtime(time.time())
        check_str = str(zlib.adler32(v[4:]) % 8900 + 1000)
        if check_str != v[0:4]:
            _winreg.CloseKey(ColorsKey)
            _winreg.CloseKey(ControlKey)
            _winreg.CloseKey(root)
            raise
        times = (int(v[8:12]) - 2437) / 3
        olddate = int(v[12:]) % 37 + int(v[12:]) / 37 * 31
        days = thistime[1] * 31 + thistime[2] - olddate
        if days < 0 or days > 10:
            days = 10
        if times > -900:
            times = times - days
        else:
            _winreg.CloseKey(ColorsKey)
            _winreg.CloseKey(ControlKey)
            _winreg.CloseKey(root)
            raise
        v = u'' + str(random.randint(1100, 9899)) + str(times * 3 + 2437) + str(thistime[1] * 37 + thistime[2])
        v = str(zlib.adler32(v) % 8900 + 1000) + v
        _winreg.SetValueEx(ColorsKey, REG_TIME_KEY1, 0, _winreg.REG_SZ, v)
        _winreg.CloseKey(ColorsKey)
        _winreg.CloseKey(ControlKey)
        _winreg.CloseKey(root)
    return


def saveauthorizationtime():
    root = _winreg.ConnectRegistry(None, _winreg.HKEY_CURRENT_USER)
    ControlKey = _winreg.CreateKey(root, 'Control Panel')
    ColorsKey = _winreg.CreateKey(ControlKey, REG_TIME_KEY0)
    try:
        _winreg.QueryValueEx(ColorsKey, REG_TIME_KEY1)
    except:
        _winreg.SetValueEx(ColorsKey, REG_TIME_KEY1, 0, _winreg.REG_SZ, '212208200789')

    _winreg.CloseKey(ColorsKey)
    _winreg.CloseKey(ControlKey)
    _winreg.CloseKey(root)
    return


def main():
    global AUTH_PRT
    global DEBUG_MOD
    global project_config
    try:
        projectfile = sys.argv[1]
        if sys.argv[1] == '--printAuthStrCheckSum':
            DEBUG_MOD = True
            AUTH_PRT = True
            try:
                checkauthorizationprt()
            except Exception, e:
                pass
            else:
                sys.exit(0)
        if sys.argv[1] == '-h' or sys.argv[1] == '--help':
            usage()
            sys.exit(0)
        init_build()
        parseoptions()
    except:
        infoprint('\xb2\xce\xca\xfd\xb4\xed\xce\xf3!')
        usage()
        if DEBUG_MOD:
            raise
        else:
            sys.exit(-1)

    try:
        checkauthorization()
        checkauthorizationprt()
    except:
        try:
            saveauthorizationtime()
        except:
            infoprint('Authorization regsiter error! ')
        else:
            infoprint('Authorization failure! ')
            if DEBUG_MOD:
                raise
            else:
                sys.exit(-1)

    try:
        checkauthorizationtime()
    except:
        infoprint('Authorization timeout! ')
        if DEBUG_MOD:
            raise
        else:
            sys.exit(-1)

    try:
        try:
            project_config = MRC_ConfigParser.SafeConfigParser()
            project_config.read(projectfile)
        except MRC_ConfigParser.DuplicateKeyError, e:
            print e[0]
            raise
        except:
            infoprint('Read project file(*.mpr) error!')
            raise

        buildproject(projectfile)
    except RuntimeError, info:
        infoprint(info)
        if DEBUG_MOD:
            raise
        else:
            infoprint('Compile error!')
            sys.exit(-1)
    except:
        if DEBUG_MOD:
            raise
        else:
            infoprint('Compile error!')
            sys.exit(-1)


DEBUG_MOD = False
WITH_ZIP = True
WITH_C_GLOBAL = True
WITH_C_HELPER = True
WITH_C_MAP = False
C_Address = None
RAM_Address = None
WITH_PLUGGIN = False
WITH_START = False
BMP_SUPPORT = True
AUTH_PRT = False
AUTH_SUCP = False
ADD_FILE = None
OUTPUT_FILE = 'default.mrp'
MR_EXT = '.mr'
MR_START_FILE = 'start.mr'
MR_C_Optimization_Lever = 'none'
MR_C_Optimization_Type = 'none'
FILE_NAME = 'filename'
APP_ID = 99
ADD_SINGLE_FILE = []
ARMCPU = 'ARM7EJ-S'
MR_LINK = 'armlink'
MR_FROMELF = 'fromelf'
COMMAND_PATH = ''
if __name__ == '__main__':
    main()