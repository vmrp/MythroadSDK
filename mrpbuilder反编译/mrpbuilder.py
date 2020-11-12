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
mr_authorizationstrings = [
 'c5d19b7c3fb6ec74b9885c830c43b3e9', '592af9e45608febb668ee1134fc85bf8', 'd64f71132ce49028a8ff4600ec5de4ed', 'dc0526ca82a4bb7fcc762cc2dd52cc7e', 'db6a4a5bc8944054867fd7180d5e5e17', 'b0e46ca1f2ffdc73c9a3efdca5dd84f9', 'c3464b3398f47d97e84df48ebe26f63a', 'b382238b24b7c5d2c5ff4b02353878cc', '74c760549913da7fba9b407e7eed3b47', '66759947a0e8b2d9fa93f67121ea51db', '12b14afcf1b207d4b1301b8fb9ca8c5c', 'ff74e8a9a0efc7e5820deddb01d8c60f', '6c01d4ae8253335d7d64d3ac047f29cd', 'c35bf64ae43ba9c4227d649e0ffc3757', '581941279d2033686e9cb72da5421f95', 'e55be288547608802121dbb4b031e2b7', '9543c7082b44f1e6a5d1238629c3393d', '2d19a65f6f59f6c9308faffd008b0804', '119b2dda108436d38528ee02815ce1a4', '30876d89e2ed6d295f310e8d96b35cee', '29132b240779d6b566beaaf6afac9c29', '47b8c6d8f9695bad33ad09381c2400fc', '2b8b036274af177a183112ea40ebdf1d', '86fce19ce9796d656451544c7cfb060f', '9c455c15b01557058ed589bffecab7ad', '30c2e6a806104229b4a077357b24e1fe', '95715a0d575bdc84913d049cf0396574', 'b55438bafa6d9bd5e49f7af5eea5bcaf', '42c67fc0c6f2b05b7dc3d35b5115af79', 'd2dc7bc7c9660b1e94f9abffc4e25315', 'dc5b2e0fd20afe8ed233bf516f76cceb', '0a8fe14e8038b7903d1207e2b6a982fc', 'e76449cb3b5af7da6e785fa77c48eb22', '3bdc5d72098190230819d387efd94ba6', 'fcee5c8b6d6ac77f494377ec751edd35', '1d9f3dc92ad19659665129f5e0489de0', 'cb8346215153932d02e25c078680ecdf', '930d2a7e471f98709d4c5a9d40096d77', 'c9a182644f30c539b3e7d3295b28ea55', '2051b819b789dd9a49c510673581883c', '2f19dafc317d5715ec590dec8cdf2d00', 'a60fecb987e7e6cbe0175ab7704d5ef6', 'e55be288547608802121dbb4b031e2b7', '9a667e2a8fdc19ef75367601c79528ac', '7d1f629616f25079ef486f14db2a46dc', 'b92af64f3c66dffa733e83a2c6a0ac01', '39f01f047ec461aaf59e283283344564', '7dcdb4ac0283e8de4dc22196d958e043', '401e7d5e42d103ea2f969a498714e7c5', '8b5de151701179670e30477f752a9871', '205932a00cde2307d073fcb0fae33223', 'c5ac2a0eaa45b2add51a53be68a2f633', 'cfb0f723f76380803dc3721418c861a8', 'a6b45601ede401501aa230e3f24f75b4', '43c9123774fd2b439c8387a361cfeff1', 'cfed28ba3e44d2b57f470c2d1598b115', '294ec1a018043165626059ca086f6f52', '330423cd2d957b0dbb1ededc2a170b79', 'ac4bd0777380dda6e26ad8dd0fa0626f', '47ff24b55037c064b9d72fa4aaba1691', '512be7f8e323413111b771d630920600', '1cbd0acfeb9cf9729a9ab2bd7c38bbcc', '46e2c5a95e201038e17bb9d668797652', '47ff24b55037c064b9d72fa4aaba1691', '73f43c7d947ad4a0f29abee10a8be6e1', '2b1e58fc0d908d6fc8367c16272bcd9f', '6a6176e0b4df74debf472f14c76d0f4a', '29fd51ba2eda0eb9d6f6326149043bf7', 'de7aaa7f3850ee3c3da77b7a725123fa', '4e4ee279bc09c1a5612a55d9ca82550a', '8e297c756d3e58a4bfa547d6003d7741', '60393e794e73d0b9812cd64f874d6f2a', '6dd3ed8ee1165fba8631543c413c077a', '884612a6ce9de6acca1a728cb7be5b4b', '9246682b0e73fcebf53e0857519c31b3', '14f74d5bf42f8b568d354a78219d2330', 'b266631fbaa50cd41d39e05311741213', 'a94df01db61e41f5c1b3a49e0ef0aead', 'f21e77a4d55bba5279a3d9d7e197d59f', 'd1a4414210e4ca449fdd6a7496c5a453', '8d619130dfaed1b6c2e207bf1aef62b2', '00673fc4b7cb1e4d5f9653f705b8bfc3', 'f87b8e820844ac8a608df2607efeef54', 'db77f2efd9db268970889a6ff1f18fcf', '3ad130b16b041b494e5d7e693e5d781a', 'a09d269e27c7bd8b62b00053fc760f48', 'a783fe09d06a28157b8c5e3156c97c5e', 'e076397dc7c34b732b2ec1d78b302f3e', 'da366a551244fa17720525f74cd9ca24', 'fee6f72802e844e1d152480cb9875b15', '8bf4e78cf7e65379a250b11678968d1a', 'f4ba882c2364fdfffce24d9478fe6807', '6c742807534f1117b0ee74021c835aa6', '67d37188d32d19422ee2f08e1006e736', '728af530dd14e161b22d9fd8670afa37', 'de7e58173aed74640e9059faa6a7c124', '553438d14ade0d5bc8a06651208b57a3', 'ee2b15d458d731328ea04a28d3421489', '5c2f4fb971e262b30cbe1ad7a914de0f', 'dbc380d6837433690a2154e1fbe3503d', '7ffea1871e171e513147456d048c224d', '58b88a99f584f8a0871f28dcfd7f60ef', '7e746aa8b3ce3902412ed391a258dbf2', '2c0b968158afbd3bc52a485c80f93cf7', 'eff5b0487c5a8ade5234341929b4e53a', 'e766d084ea39eb8e35b1902f1940c7e9', 'af03326ac570155d15b17f5e71d96812', '88ab3c3216f730572890f30ac123ef35', '0b254e185f21c42a7577dc12b9630012', 'c764882013aa460725ff8ee5fc0b5db0', '6d4ab06dbdca139e45e0032694cb8a50', '4632bd052dc9c0f43ffff62ca0d001d8', '72a1fb4e40ebdb83b2729cd475f957db', '2abc4d1985f1b6b2d742e0d1774bd2ad', '5ba6dc626b11760d011bfbe8f2b3aee2', '8ebda3f6a8d1ed2af7d469a8290b371a', '336949b854ccb1da93f12c70cfa11fdd', 'b85c7ee2de2ed8e7be738436e99a154a', '2c975ea7366a0d10e919fec4006e6230', 'fb428712d758ede291a1de05b6832295', '852455d79e7fe688a04f593585580aa6', '90061c89403d5430ab2c193497123cb9', 'e3fd9b8137809ac8192feecda0904e9a', 'ba95b7f673f60bb07017490d1ea2f842', '52d159e097f8c56c37e915c78811d0d5', '4b9edaca0d5105c28c42f036f8dcb5ac', 'a3625b04ff452a6b563523778057b5fd', 'c8bd528e6e4f5cdf4424a7a3d3fc5fcb', 'ae32900a10ee99c626b675a72d09ebcb', 'cb3e0b1c7b76819b76248c53f2cb877c', '25681c9166a98876a399f9541bd09cdc', 'd376f29a6d02b0d1d9acfff4170d392f', '9e5ac4a93812ef9c658ecd64023cecb3', 'e2a01b4e2d820f5db07e83a38870f3f6', '595df6c5415d74ae9774c62957d2de4d', '1cb77ee39da18a5f3fe5fba4886ac09e', '546acc725a666e14debad4d47ac0f64b', 'c86d2888a580166b4691655914c4794b', 'f3ec8045063d0b6332abd359757c6de7', '38cb0853e0844c812c7e305acb47e51c', 'b7cba2c6419c8682653c41ffc2ec70bf', 'e8e017aa9b4824ae514007499c42f016', '287ed5fdcbafe2fb9d7144e3ba355baf', 'ddf7f7a7c46a220ca1038d395846b423', 'c650774e05f7b0a511bfd5f799486dcf', '2483b017df1afbbfd29971bfdef451fe', '68d91d5c1ce369aba0392d99cef8c6d5', 'dfa0c2735afb83e4580af394480cc35d', '2a4976e637035d6e234382cf3a6ac3ee', '9a0939262f2f7e7f0a5b25f21b2db5e0', '3196a7c4687ed437ef231e704cdc5a5b', '2451b6eed46829e3252d8433b0be1ccf', 'bafab642b9fd74850f27b6282432a70c', '3c04fe97c5b42e786a53b0ce012b57b2', '0fac99d1aee3663dc08331e3b2fcb400', 'fd49750f3a728d274f69b6725df277de', 'e5b0bc1cc1f6623deb7a2cb2d227def6', '6ff28163ab3e6467757053a163582170', '99b7b2095f19e64d1338a96382cff94c', 'dc29f8ed7c5c76b583b37a1b68d07ac2', '8bb9d27267dab106743e5e15a011bb40', 'a1e6385a6860b5c6ac796e37c3c5658e', '0eb3e4f299c153f436dab721a1b1ba60', '2e69a0d80dbb53604a73c9c682c598fb', '8245bb62421ed7e5d310ef7e5e1f1991', '380a6d8c1d91506c3a9b55ee358eb2b8', 'fecb7115fa655fa335a40e3c109747a1', 'b9aab8788ecc862622d89a35b819baba', 'd35ecb21d06516942f83f5e565c00ae2', '79ab289c20f3c15a8f9efc70dd98dc82', '3e265d2616002c9553f7e9e4ab8be0db', '44bd0030971ea71ee031dfd567e62278', '9762f7564d9f880ea44b05a6b2ebcbab', '9762f7564d9f880ea44b05a6b2ebcbab', 'dfbd5cf45380ca698396df3a210193fb', '33a19f4d6e0e8b7aa8659230b0e59d45', '6af235c2e77a0590feb7d4626dbf62de', '14ad49634da53b6ae620c64d726b9bbc', '2959f124f11ab0d8032391310b331b16', '78daa136786dd23a85393834a6103773', 'd6cf7b0be8c3332bc708d7b80997174c', '2bcacc4900ecb802de1a1cca6646cac6', '0d651a10f26f9b1ec0d9e2ab876f0855', '63b34c94557d8ca4fc6f07fbfc09ffb0', 'c49dd1048dcba2f011031593a4ae9d39', 'c24cadcd64b9734e9e351b6a6c63cfeb', '275efcfa1c8ba6f0506f782c3ce5d33f', 'ab698be1b6765ae1caa58d3c042bccb0', '8defbf6005ea543c6b26647a78558caf', '6dc478d78c88b933fe81825e8af0ea0a', '662a7b7ab85df464b481111497bff17a', '72da99ddd6397c25da8590011001a2d1', 'f31630017e6a6696256b3b92dbac2e9f', '24ac2b0fb3a2783cce4c2d9ad57c8232', '28392328478d1c8ab134b1708c953d9d', 'a00cc689ed1662f784fcb6abf2d45cd5', 'f6518d82a4d3d9f36a40c1538a566848', '3808d989ef10999397b259da2db564cc', '09a347ea27275542428f62aacb2b64ab', '9b6206b92ba562e9734eaedd3d9ac9dc', 'f46c560dd65ee86bc10fa6d8eefb7b41', '5868e8e0e115bd2a9450d60e2d4c9055', 'b4a140c3705631a2d96d33120f8e6702']
cp_authorizationstrings = [
 '2eecf38058f259e4356a5116a1f0fda3', '014899c7da890c94bd835e0806971390', '32e2becd88ae1f885874d89aea6c483a', 'bcd8fde7596b8d817e1c72f47c3a3f3d', 'fe0062b48b1fad6a2b05808d88e7710f', '290c19849e6261e737bd6c3c4e7cfe19', '2ea90ddb54bfd318358e2d9a27adb6c5', 'bbf1450f78c88a1a5a169b5b4bec3679', '454d526cf99399ab295cff098f668113', '017f2bd3f0a4a99bb40343329d85aea5', '2a337615512dbd1ec08a9ef8cd14b62f', 'fb4a2df5956089a7e64759bdcc293b4c', '40c0272392696cdce8b67ef498333d36', 'eb00becdd96f1183bd9b48bd4517b40b', '48321c2f17936f68d248a71acc605717', '94b9f48bd7b75c6715829873c8067f1a', 'a7cac72eac077c62c06f04250d685012', '17504d4eaf14a864d32fa4d1b527e8b2', '38f836c250155f9cb482ec1b44c5d854', 'b877730e47c479453a48a27430bd84ec', 'd74c26185567536a898a523fc448f603', '8ff5e24081b9889ba5d21eca5e647eb2', '63d0a1444b11ed42862fd8f255356502', '59232d9721d0eaec1cd5d49679126f6c', '32adf0d101267f65f984865dd7b033fc', '57a85424809e30c0357612ce51c416c0', '57a85424809e30c0357612ce51c416c0', 'd39278e8070d33e54a012e2656b0c92f', '53df30b028e9af533b67c6a885a351ca', '74e4686a45e01cf569f4b27764360478', 'aab4f9c26c5a4e0ece500bb16ba015f8', '17504d4eaf14a864d32fa4d1b527e8b2', '3e625c365a54eb820d6c00b11c91bff5', 'b877730e47c479453a48a27430bd84ec', '591c6dc92be681f4aba30bc295f1844f', 'fb563dfa152423281db2b6897844aa08', 'e371bfddd41735b573bdace429b5a2bd', '593f1e6b5aeffd0e5b09772c16942f2e', '4e9a5139a5782c5668fdc9be1e191785', '9dbef2d36bb8221e6eac97a390b680d6', 'b4ecf6d49b6f6cbed48e7f4676a59373', 'bde9858108f9b87bf4bb9e0f89534f56', '4f180f695ee8828b71bdadd1cc113b1d', '504d2000e4ac31661177c85dcdaba195', 'ea337a0e7d01d5a1243bbae3cc9a61d8', '23eebded3539e62e46e45969151c8e93', '685303f1947550e257a75feb4faffde5', '6dd1dde36211b4e4019b0c2b9a44fad8', 'cfc4242597b69fceb5a51a16bd2274bd', 'd849b5f66a4002d6de8c4ddd792dda2c', '35844f40799b2039b2af5c90ce90e0c1', '67603bd7aa54912846f997cc2a264ba7', '8453f05052ce0a51aa4cbd577865a3a6', 'f7ae9f75c331606b1908a0ec0badb7a2', '7794237cdc341a6f02da4eabbc874e2a', 'a686f252179ff886a8efb2dfe5a2bed6', 'faa1cdf722721e4bee6a15f7c8ac0a36', 'e8f4f022f09978c6e1d37f564fbad3e0', 'f0d0ea64bb08399d9842c504fff4723c', '75f2930700548664fec6df6a09e0d2d1', '490a0152829a1915712e61e2e03b7f4e', 'e8d1f5a58db8e55ef0fa847b38e06f2a', '9aec22d1e505ba4b76bfbd5942817177', 'b88ef012e5029dbc92ac109d20e1903f', '2ebf6c7a025f1155dd0e134464e0472f', 'aab97287bb783b916221b0c3c9b84c2b', 'd642120575f913d96611b3e7deb7e280', '986dc3b9192158b126ecaaf73b90c274', '185ab6371b00054b588ea7256aa45892', 'aaf161600f73e7a0a682882597560fd9', 'ded7822de3f5df951e7622a612f9ac91', '73d6c759fe8f44aeeb2c294b75e88b15', '10cb3a97d867f5e46d9142780bc065eb', 'aebb77cbf200bbdbe6af1f9269f7f11b', '7bdb20ff2e5ec9c05a876ec7c75cb49c', '62d2be0a144dfb1d048d339f35d5fbaa', '39916d06bd8a346a685a6d798289b3dc', '51e97a829f85eec147cddad6ae4b7c72', '38e943d59d66cbe80739485ae724d2d5', 'ad0443921fcf7ad17826ca241a2c2adf', '54daea89301bceb3863251904be19959', '191164ee7cecb3c81ac2ca8a528aa335', '3e631237b5aad2a027229cac101bfc77', 'b70a59bff9676532dc730df90cd41138', '23ceab9780658da71ba78ff361250141', '61a3998947c9d1638de8d59f587f0852', 'b87d9b42b236ffc8ad139dceac3c6b10', 'bfbe705b7ed1e356d378b30dac964ff4', '24c8b3151a7a48fd94f86319ee303417', 'ade3eacde998b8d2b043f00c722a55c8', '4ded028ce1d4fe50ebadb8c234fe7cb8', 'e55cbbb55c2a8c07eece38be93657050', 'c130c86069a096d605a97d2c7ac6ebd4', '5285b8411391ebc37f2429be68cf1142', '6216c08704243c8fafd73e920a27ae59', '2618e1d6216b247f86690a9397ab543f', 'b293fd1cf4d64ebfd6e6fc921cd3f05d', '2f37337cb4e0c4062e247d490ab5112d', '05a2b61956bccb34fe4decb9eed71e7f', 'a383657e8c7d139f6845f0dae219ef76', '8c18413138294c31cd11218274d14378', '344fd7435f19a93221446a7d6cb3d327', '85afd30fd9dabd1f031e7f35c59b417f', 'cd592b7a3f0e8d7684c3f504a56d9014', 'e6cc4dfabc07d0ea6afda4b554228147', 'ee7ca3aea6d2524f17414e818b5ae491', 'bd8401533f22e22a3d2626c2cb6d249e', 'b45bf5565bfd5a2c65548254167fa28f', '7bbb38ab541913ccc5b9872b609649c7', 'cb9e067f9e84b50d1309616cb240f141', 'b4446101701f0d770a3ecb485d0e9279', '86061878f442eba14f67aa6c016f6f29', '437f84b994048761108cfb8b6a8b7972', '1d838be3178c3fd7e2d5d141f0e266c8', '698733950ec65b73d14e4354cb4df458', 'c21915a5b5c918be740b7e922572c179', '9f3921f698f10841803cae0c45a7a70e', 'a9fe75a0d1c9a86ad06571a38ca2b65b', '9fe75a0d1c9a86ad06571a38ca2b65b', 'e310f89349bd6b3d38dec55e16bff877', '18f6b615228f4fa004a5604240bf40eb', '400a334edd89a1f42abc5bf53cae8759', 'be140260adbf3f9ae1767d907ddaef64', 'ced6488209a3483f4c03b03fd7d00998', 'c4019387b86c032aa066dcfc131787ff', '12a1f4056ab10c3c2dd483f40e45e887', '8529f361f97b9251948b3fa0b60b4780', '8b0ebdefc722576d78b80651223891c9', '280640cff7f19256896592a9234d37eb', 'c0b40148c307e8996640a5cc6fd6fec9', 'e4a8bbf84025eeb66f5a28ed22b14a57', '0d2f07487b6c9e85ef3ae7b501c9c4ac', 'aa263b9fdb071fba202d4be63ba8f5d9', 'fecb7115fa655fa335a40e3c109747a1', 'b76d97252656ea485f6174b8eec4b9aa', '271b472f896d658b40a4949eb0258b5c', '271b472f896d658b40a4949eb0258b5c', '28f1849bb176894785d7d75a612dd9a5', '558a3d95180c81782530892f87478ed5', '66e3944b3622654fa9b99d533ea5a01c', 'dd335df6924bb27e3c0005831fdd76ab', '6dfb8ab6daa245629a511a9fa1f43542', '2ce92c9b522233ad1f7d45c2fc4c15ab', 'd14335cfedd06b6b38ca0da91b6b4cd6', '3364f33d92ceecbc35c150c626b800e7', '7a88ff74edaf481a9ae49203ae1a48e0', 'c8d6309e6c8162b475fc8c6d25791619', '5e5738b21c199e65482220d437dea77f', 'e99e570e582224e499d648fea81a8cb5', 'e48f9c83b2c127f795bbbdfe8e0d3402', '7b256a0a43a9b04484772493676d01dd', 'bd0ca697d0ba277c393a42f4fc9b2004', 'cb709166fce8438b668d9587052be691', 'ee7ca3aea6d2524f17414e818b5ae491', '104932a662065b6febd939e7a9dd39d2', '3542d6d27a718680cd9038074d44c305', '70cf3cb17b34b63f6e3ff6635660bfc3', '81cd9da2b4a4fe9d4af69ddf739dbd96', 'd1eb1e4de76f36e0c20807dcc7463c1e', '848ef372c80ee0457c404b8a2ab8e4ee', '0b7c78c4045875d58ea0873bc41c73c6', 'bebef91aa98d3d1ecdb2092288adf0e4', '9aa1d9595f2d7c4407224d76c34af766', '46c422e51c1489d9d431fd2ffef3abf2', 'f93ad5ea48c5194bb402b8e190904e8e', '10e2aa9def375244a8a24cd0a5d6b9a4', '7d6e69703530260f93bccc03515aa22c', '72e57c85e557308caea6315e6f4342fc', 'ca8fff68beb2e1b6e895326eb0ef7f83', '0a00c19962454dc5ab692d458456df40', 'c5a4693055bb67dc4c5ee7ee3065d84c', '003116d21d31723e962cf545e4e61751', '5a47df74696335f05672704fd16e4c9e', 'e919a8fa78f8743fabbbfe464a677eec', 'fefddf4f5970575928608d7eb406be65', '865b6e993a6336afa1074ba48bf96189', '208c08a994127bb59f592a6a5c16dc68', 'c6c338566315646718792ab45c98eb68', '6f8604aba20a32127546faa288043364', '6dbfd5be201757039baeda6d4f1fd948', '0fb78bf57c233ac35bf8b4a8b8edec73', '0aa6f06ffda5e1ea9f9e231a6d57c310', 'befba92f80f5d9cf5749281ee8115900', 'd7a247c914c79c4ef14f8e26782852ed', 'c486dbbb672006d8f2261587b1c8be82', '563a83692328efd5be51cd88fb7a484b', 'a2bade2f3b1afb11f0cfbed471716b98', '61f3fd31bc80295b283eb1a72e9b761b', 'a946ed9930db563ac36fec6658d55ce1', '17664aa3eec226afc6e685e2223ae9f1', '4cd397fda9714c7aeda83c6d6a0df8bd', 'c56e10dc554668dbd7bd978ab3cafef8', 'd7bd94d2d735d6df8e7bd265b9e78cd6', '25afe3455b98b5156b186aed65a8a908', 'fd14a67144629134021bc37d4f5e970e', '336cfd870af92527e78d98c8e3533dd4', '4770b294bdabaa9e2181e0111802eeb4', '545f3b66e8e5f65bebc26b2c17019cb6', '922a211e0c2ad1f7cc7514b1c5f74c79', '335507f78d6cddbca9aa037aeadcd14e', '2094831489ad5a28fa5420be4292e486', '1b0f591a14804fae0f11882df7a48769', 'ac37028c12e08fd9cce9ba1dc50536e6', 'eb82951ca980630e5cda7e72f1187874', '5e7c942d09a04613e469ef10f7303f73', 'd052be62a8e1d3f8a6ed6109fccadbf0', 'd3cf01c3a36bd3ce650916da6d4b1010', 'b7f419f22d0278db5f868252467fe0aa', 'f2b1632e714bf46d0fbb08f38ab5521b', 'cbf40702277f226bc5ec38504d00180d', '2eecf38058f259e4356a5116a1f0fda3', '014899c7da890c94bd835e0806971390', '32e2becd88ae1f885874d89aea6c483a', 'bcd8fde7596b8d817e1c72f47c3a3f3d', 'fe0062b48b1fad6a2b05808d88e7710f', '290c19849e6261e737bd6c3c4e7cfe19', '2ea90ddb54bfd318358e2d9a27adb6c5', '02fc373520cf25e99687fe73c1913769', 'c1dedc7472e289f4ba57fbff49a67ecd', '75ed6d8ff74ad59ba00af87db7239428', '2724ec4d112849669dbb61361876a2b0', '2c169a5d097bb99ec567e25473abb4a3', '0f35c4766aec609d27f42662281529e5', '87b4ffad196e2f5ce0b79eeb3a20d2b4', 'f17efa015d3f145f2ffb0e443f21e5e1', 'bc8d41dbd455d8242d2e7c04e36343fc', '4071fa0b324d5fa76f6bf0163ad7ac2a', '07a22534d28416595e92477ca56b1da3', '2737826523110d46364d9b567e327ee0', 'd6a0b98e7c6d5f9f81321efee1845c79', '9c5e90588eeb47d1b769ff727dc33ab9', 'd8db202473281520a0a206e9814915db', '0c926426f8d5fda7b88099affa9e8126', '9cf8d054d34d6d1e2503cbea409ded27', '5bf4f558cc9a369baaba387056d2dd73', '02f872daee3649e5865b08dc3f69a588', 'e172d7ce044fbad3a03552943266332b', 'c487baaf9f65f9c224dd5f75e491806e', '0b19d2b25b65926359ecfb64f6647f8d', '543178f16d66241434004acadb33f762', '108da8af8232fec8192f267d4deb96ce', '0f98ea04d881151c3eb1e0df630982a7', 'ebc1f3ba16d2695c6699586897c32a41', '2999a790506b639b1a41b360a25b398a', '1dd7ff94596ec2095daaa8c8628b3643', 'ff803ef01093e63aff04c5dd8d459991', '53af7a6e95a305afba9fc7ecd89902f6', 'bbf1450f78c88a1a5a169b5b4bec3679', '454d526cf99399ab295cff098f668113', '017f2bd3f0a4a99bb40343329d85aea5', '2a337615512dbd1ec08a9ef8cd14b62f', 'fb4a2df5956089a7e64759bdcc293b4c', '40c0272392696cdce8b67ef498333d36', 'eb00becdd96f1183bd9b48bd4517b40b', '6e3705d9d679f8d0d16c10e43fc53d36', 'e1060df381a7bdbc45ce60c6d60beef1', '3750b0aeba744446cd4fb437c3432d43', 'bf581d63c79f20e088e3ee272ae66496', '54894ab265b3c47a6ae99bfaf774e390', '6ff50934d5d34b135389a679f24836c6', '4f180f695ee8828b71bdadd1cc113b1d', '504d2000e4ac31661177c85dcdaba195', 'e680766a9fd67f35a8fe9e33c7115dde', 'ea337a0e7d01d5a1243bbae3cc9a61d8', '23eebded3539e62e46e45969151c8e93', '685303f1947550e257a75feb4faffde5', '6dd1dde36211b4e4019b0c2b9a44fad8', 'cfc4242597b69fceb5a51a16bd2274bd', 'd849b5f66a4002d6de8c4ddd792dda2c', '3e1561a3bf43cc9317176bd5639c977c', '138802eec14499473dc866aad355c04c', '26f70e6d3bd0511e8099cef6be88b719', '0c988859cbb34f4991de24efee17fbed', 'e04606d59ba0894e3f7d4c5466f2b826', 'a30907e041c48d7b68640aa21a872317', '6ac84e43e582467b3bb76b53b90f7594', 'b1fe2ec241e3903b954cc2be39dd85bb', '5c62c077657828ca59b5f40803a84512', '5975d1c57f4762c57ea2dcf3cba88111', 'edf279d86bdcb065772a2789c178619f', '6d6cf243de00e3844890236aaaf4cdf1', 'dd02323048a27cd08a445b835410b45d', 'e386b05a16010eadcbf7aa5560d59450', '953accb2ada079b4d1e2a9bd9d4c98c2', 'a76cacb78630a3f78923cc4b8215bcd2', '627f1b8a80d9384e52f0639a41723538', '3b62205063f57d8efc0ade57d3065bdc', 'f7ae9f75c331606b1908a0ec0badb7a2', 'f0d0ea64bb08399d9842c504fff4723c', 'bd63e1e9db7e8c8725bdc48a53c67c5e', '490a0152829a1915712e61e2e03b7f4e', '34600e5d7e6f159dd5d67f05bce14d08', '443ed121e23d08ea816305caa7a353e6', 'faa1cdf722721e4bee6a15f7c8ac0a36', '29055bb5873f793e4cf5b4109dac22e9', '5332a9c2da508f098519ff1317985fdb', '8453f05052ce0a51aa4cbd577865a3a6', 'a6a38b872fe60ee7dc82068bf0160b6a', '35844f40799b2039b2af5c90ce90e0c1', '02785bcb4267085f0efd7b147f37b36f', 'a686f252179ff886a8efb2dfe5a2bed6', '75f2930700548664fec6df6a09e0d2d1', '7f01eb5260a94efae4a0a9fd0a084fca', '7794237cdc341a6f02da4eabbc874e2a', '67603bd7aa54912846f997cc2a264ba7', 'fda8c603ad1827dbda49edc7809d6196', '3fab3137fe0f5fc9650e8f175676e023', 'e8d1f5a58db8e55ef0fa847b38e06f2a', 'f0ec91a00405110b99719e9c6277b6cc', '471b41a77690c39f7045e444aa912e92', 'b906a9edb5da14098ae34a85fe8348e7', '57e73fe845b7d754b79370b376ad001a', 'e4262cc6989042fafb958cfebe6015eb', 'c34c5db9f3501e10ee4077ca24c37f3e', '64c874d82a8682c142743180a8933c52', 'c5456d4a41e238c17fce0c695f08866e', 'e1e211fb659786e182ddade8bd5b5a12', 'a18c0ebba66b0e7a160c01b66966acc9', 'd642120575f913d96611b3e7deb7e280', '986dc3b9192158b126ecaaf73b90c274', '185ab6371b00054b588ea7256aa45892', 'aaf161600f73e7a0a682882597560fd9', 'ded7822de3f5df951e7622a612f9ac91', '73d6c759fe8f44aeeb2c294b75e88b15', '10cb3a97d867f5e46d9142780bc065eb', 'aebb77cbf200bbdbe6af1f9269f7f11b', '7bdb20ff2e5ec9c05a876ec7c75cb49c', '61a1175e4951a7d5841ec49b4821e9ce', '67943b33cb7f9d298286d690efa55942', '62d2be0a144dfb1d048d339f35d5fbaa', '8d94e5d29f1a4fe6e7998b49e3c6feab', 'fdc9924a428ccdd1e9b32cd06a1a383f', '3bc35c1031689fe3953d74cf28e6bc09', '62d2be0a144dfb1d048d339f35d5fbaa', 'ed4893635cb1e918ed8cd6522f3ae572', 'daf6bd07d5ff5fc13a3f7f3c9f6d0b4f', '0811695a53ca58b62595a638a9b4e4f0', '79043a51022ad0b54b0d4d7c18eb7779', '8d94e5d29f1a4fe6e7998b49e3c6feab', '79043a51022ad0b54b0d4d7c18eb7779', '9f8a048080ebbc58845b6cecdcd78574', '971ddbffca533e6625297bb10adcb04e', 'c9d7ff896a03c34d01c88dd1f4f57a8c', 'f903f4d3674c54b7f699d776677fe57b', '8b64306db54fc5fc07dd6ebfd066130c', '90da7538ee2cfc125e0e76b720b76d35', '203d3c14b4f9beac5daed104614b22c6', '3a02544bf2817658dc69c9b6da41ab5c', '393300a92c434012d9e0d5284e92ff39', 'ecdf27b552c0340ec2d2493708490b19', '2610bcfa6fbbbaeedc2d04ba68574b84', 'e3c79d0e1fd0b6e137275675c5cc8983', '10e1ad26677eae21fb922364cb8bf8fd', '15be7cddbfcd126396a14da3e2cff1fd', 'da26d149c1ef853e1bd41da9adbd239b', '10a767ce62de3b8aa997914012db88c1', '38cbb5f69da038a90ff9ae08463c062a', 'a3cbdd01091ed1ead04481359d3a341c', '50ed0ce2c0f5614d3d26686ae755895e', '51c99fbf1bebcb010f7f9c34c5ce499a', '35ead8e6f8668d692fe1c77a5f4488d9', '81bcb4a6e5431dd51dcf81a5b5de1a8f', '96f9d5e6daf8e4bf7ad55e8619a973a9', '5051043ec94a4f3fcebf95b55e4b69e2', '9d1ab9918c2bd9690fcb4f21e93206b2', '15be7cddbfcd126396a14da3e2cff1fd', 'e43009d6eafad90ee7886397791d8bb7', '516d0c123260d02009cf9652e9c55a67', '221749f4df0dfa19cc13e5276a64e0c7', 'a7e2b1fe343f245380bb25d3196dad14', 'ff230732c4d5601261dc09d92c8ea97a', '78ab558a82dd2c51953a79816e043532', 'e99097489bd94d929ddfddb14ba7176b', '3a02544bf2817658dc69c9b6da41ab5c', 'c33f0d11fbae66bf2da6ddff9e421d6d', 'f85d5226a43a44bb7cd5831a17e854cb', 'a3cbdd01091ed1ead04481359d3a341c', '9d5499db5b327e9f352f06ef31ecabfd', 'a82d8f9a235cec7d02d29b59b71ebbb5', '43af396165122ade0f57528783723eda', 'b5c8780b4f3d8b891766e89c2ce37f5c', '72bf67a58444fb5082d404f4c38f47e9', 'c0d404a22153fbb64d9a76e8f278d313', '516d0c123260d02009cf9652e9c55a67', '2f6d8bd01890d2e8e5ef9045f89db9d3', '54f4faba98d87305e92bce07db02fc5c', '0f733791243d796ec3a44d86ce81c98f', 'ab2655ac182d01aefb8780bfc6b1a3c2', 'a4ff07d5f24279a7c1fd4d95c52f4f71', '7f8ddb82ed326ae7db7d0deaebfd9871', '1a118cd6279f10d20c77a4dc00a6ac25', '4ee964934c2c7e743dea600ef8d10ef2', '67fc50f01a44b9cec52f3d36bda95f03', 'f8671788f9ccb407c52bdffb7fa5aa88', '88a51d07cf4fa4938c20483b3827ab6e', 'af4a9b2af4ddd8cca6a2fffdf689becb', 'd32dae1a4dd99f4d76db5a229b3aa016', 'a9c10fe872114e6b1acbf8ab74d34f60', '072d6b7e98427c148f1cd351030fc4e3', '0d395e9c867f4b0a9bc513ca6f161391', '7fc03807222319628497b89b6cc01355', '7da0141e0b682b42ece318435f93e557', '667d7e7a41a3a52718ffcd4677992c1e', 'f11638ef024a55444a7f0e1902992310', '1073df549d0ebf9e379a83a63cb4be9c', '0c65fdba23334c8616376959c62797f7', '3b6700689cacd30b68181ba07f083d10', '447c2b4fa6e1cd7223e515d661f995d1', '7e84e77407dae751a9f440a8cfb03a00', 'a5fe72b7dc026df220395dda686c4989', '960d74ae697cc97152d6b9a9e210d040', '347c4dd4ffc4ae0ac1d4c4ec8ae2a63a', 'a0e04664eda0c7830d2b5fad799c48cb', '265b8a19256cf95d8aa2b4cb8380bf40', '26389b7b06df383ac7586fb4e3e55260', 'a6ac8089c486b457ec53421104e1ccf4', 'd43796039779144de877412251edcaec', '0326862c7559d7230dd35c567e2900ae', 'b96e7488161a4725ddd4ddd2da541a6a', '1d84a97b1b7507d2acc4654eaedd1214', '0920efa61884b00b2ad79645a0c0f33e', '1ce64dbe98cf0da7bc7bd612acf0e30e', 'ac2d5d8e61fbe9e5ac88f9f7265b3138', '698733950ec65b73d14e4354cb4df458', '716f07f5b6abc974878b246c2590809f', 'dd5b33a7da2a5b53bc936568fb3bafc1', '86061878f442eba14f67aa6c016f6f29', '6de61aa5cfe9dc9e5aeffab1c2924373', '56f8524589eff6a85970073de5b272f7', 'c21915a5b5c918be740b7e922572c179', 'e87699f83f7a784ddfcbca5958a2643c', '76377e33d6ddc22bdf26bcf086838b8a', '1d838be3178c3fd7e2d5d141f0e266c8', '614b7a0242ee88a5861b8d8f684dd756', '9dcf33a1a289e805c274aa431530ad8e', '278a738aaa0549a809a207affaeae2c2', '9dcf33a1a289e805c274aa431530ad8e', '9f3921f698f10841803cae0c45a7a70e', '83323b593af187b53619bde6da901521', '1d838be3178c3fd7e2d5d141f0e266c8', '512e5a664869a6b0161c1c0cea009030', '437f84b994048761108cfb8b6a8b7972', 'f10b5a4d7a01a7a54d61d6b21421edf4', '49418632cd924cb1a219bdeef6bfb9b4', 'ebd9dd90560245161e35cd4a0d3abbf5', 'cb01656aeea127ea7bc467525f38b4d3', 'd278ffa2a0645595f0128c11dd1cff0b', 'c3d2981836d8a45d677a973d30daa3b5', '81c907fbcfc827da0bd98f2e14190139', '69e44365a19dd452e3505b6f6e364362', '8b39d9d606d40984780a53bda6a6b75e', 'e34571ac5d56356873c5dd6f744bf31a', 'e949bfb5de9d28b16dfe03657f4b1c40', '74ffd1a25c6c5f87fe6ccc09385a1c0f', '6bf7a838d38fa34affae98fc280370b8', '82c5216e9af2984bf1120d7f627507af', '327fb39b3369111dedd9b59ba715df37', 'b4446101701f0d770a3ecb485d0e9279', 'c2f836dd6f17aa54837abd28ec13b9f4', '6b92253ee3c3625828c92cf2bafd116a', '694b0f35e60bff3d7bf2856a8df6f4d5', '1c2e910c671df8f87fe438e8459d7d49', 'f07da7e57f4dcaa588cec62c2229870b', '4ab0c26524030c22f9d0ae7a4a8ab7e4', '463267b2f940b9935809b531f968c4a1', '1d8b12bde21ce73f37e7a4cf7bfa32c7', '5b520a0cd7586b405889a19abf4229f2', '755eee37ed613fd7bbcf08aceed258d6', 'a9fe75a0d1c9a86ad06571a38ca2b65b', 'dda6484ef2e70a6bc223019978261631', 'e122121c321e78f7de9efcc7c802fd59', 'c9010b9a1a9690791efd9373ffed1d43', 'e49f2c9640a57c77b788da45f9d0ee3f', '4061766981ef988e12a4eb6e9b475bba', '73af90738a3b5f79a2e24b937e5d37be', 'd45cfa2b7757f97b86cf277b8bd2a2e7', '197e9078b46122d57aee3a149f3658b2', '89fee83a622050401e0aab9bb4b50a11', '11f142a93e8968947481a1840ca9599e', '632e4922c7729e89d72c7c8d7cb46a2c', '3b554794fcd3c77276767f318f278e1b', '517bbaade5c57d9a4982f9b45583852b', '62da907d4bdcbc3d27f8eee9a52ff117', '9be2ad9c23dcdb82aa4f77f3302f93d9', '75318492f99944a17d7be8eb46003430', 'b904e0bd398e209ea7e83b857b85f850', '83dc09cf1434a6318c76c9aad7b9651d', '876a0d3bf7f734bf539d60fcde8a9c87', 'd9ec329b08dd295677cbfd54f3cb89aa', '3ae1dec8d97f34513e560b002eb7a87b', '734eaba5ee55b822af2e3c29e585c06f', '83dc09cf1434a6318c76c9aad7b9651d', '2c4129a8fe42a9bbafed3c6d5605089e', '5ade16fba85aa5bd8362019120b28e43', 'da89a252d21be5bf0d7d1bc2f3b5e67c', '4fb537998af44159220a4303c5b1bbbe', '7ca1ad9f7af13b0215e4275d10c03605', 'f0e4a4ea1d498bfa610ae689b20a1b13', '8e3fa53d6af5764815492fcc956c5dfc', 'ffc2769e928ce2465951d5e362c8fd11', 'c4bca405ee5abdba7480dc86f13b52f8', '6bedf1b45cbc7633c284e7662deee816', '513e2155817b97b3ede255df29e4c85e', '2148f3ca4a374cbe5957fd5c2d152e7f', '875590caf4370c7ec2f66f15f8483780', '64c44d9ce39cf12986c34afa15cc8577', '842f44a154c72ccb95a9789da9cce2b8', '29aa910d4dd080f16b7cf26a536d5d91', 'c8fd9331b3d00551e31845f2942ac693', '22e4795e939ce7c583ea6508590ab43e', 'c4d4fad3917b3aad3c6fc378d4c9c2d7', '05e67d065b4f8e3daf3addb595a20cc4', 'c4d4fad3917b3aad3c6fc378d4c9c2d7', '5226c9260f1a17f40c9f45370223159c', '665b8cefe9cfa9adac8a07db9087523d', '7b4cbfe9ea1448ea31d699b5a6f593b1', '1e4538599f4bf8950868c0dd3d4c62fd', 'c190ddfdd5b02cea0a7b0697ac9425d1', '6f53f69e2159c8db0ac1e62d16037e52', 'f10b5a4d7a01a7a54d61d6b21421edf4', '49418632cd924cb1a219bdeef6bfb9b4', '9c65098eef4449a562aef055395ceab1', 'c3d2981836d8a45d677a973d30daa3b5', '1f832b1683fdecd39c854e9a20306c7e', '0a5fb1afe583ee4670b6f81124aef56e', '3577d2bdac6142fba5de13488b4b9007', '613606979c145b8b774289eb9065fe43', 'a7516efe606eb30ca5df6cb9cff1bb92', 'de2e0eeb89ea15337fedb7eff95a8b7c', '4e4b16accb04961948932072cb0013bc', '20e1c588957e72c8af2d46acafc5ebbb', '1155b19a2154dc4941c9aa9f76ba26a3', 'b20607ce0198ae9150c017404d3a18de', 'b076176368a70efcda8b498ceea5e270', 'd734b2244c5bccbd1c1e1329a4106d5e', '827c0fb2563da977f8fbbe31b9cb6062', '3a5ff6402cf9c3237a2855b0be89a964', '483ed7f8229ef0cd7713bd87985e904d', '1e663ec7815efb6afea5ab61725d3fcf', 'fd5eddc1e2be98807b527cf757b61a5e', '7709c147d876a0d784391755206ee6cc', 'b623af84495b46238be977e6f98d3271', '7182d234e03995d3869d02cde58e1af8', '4902504935452c0af2976ab2161c4998', 'ff7fd82b5844f6d647abfeb41417a5b3', '9d7e2068bce0462d727986e1244b003f', '127c92d23f39b7e423db1aa5198042da', 'af20d88470e6a4dc3515342779b8d593', '6e6888967d79b21bc767705b5e44f4e4', 'c0b5b9c4663b01f5f41c140e8e301703', '5a4d81e0de7089b2751fc4a8f330f38b', '43495ad0537ce7d639bb06b0be04f2c6', '9217b85539f5abdd1742dd8259b6f317', '8c70d68471f12694c025a9a17cb20c86', '9b0b001b6a1a99b44bb4578c0252fa1a', '08fcf69142080ff8018b7af31cb17753', 'f64fa258db15d0e8cd79273faee59af4', '51da24005986588abe6e78cf0045f88b', 'bb36915cf0d2214b7acb0087ace43195', '950a30226860adc9e05790365364dac2', 'c3056c00bd0708754bfda6eb34c3aa83', '60eb79da43aefb3fac3ed8fe8ff2e39a', '96b1f5fd5e94d1041681b23e094591ea', '6ac7866a81dca3baff9f62dd0f51491c', 'db7be2ee567be02221834040f73a7e95', '89c7e6e260a0a8e27011ec77cc3d98f7', '6286e6e01c93d35886c4434862b0cbe4', '8381b72bc76cf864f6f36a68db0fa5bf', '5e5d4320fddcb85c8987542a51461b76', '6cd744dcadcb0c3de09967113c9cd9f5', 'c670f163ab82e981177d58ac2c1bf6a1', 'ae9e9674ab03b7360b528acef6f7cf8e', '7e5325cd6985b2e26e285e2f9b26bac3', '700e4aa980eef2f60991457c3edcd670', '9aef983548e94aa6500c52099a51d5a1', '95b4b0591b00a4a5f8284a40ed0d11f5', '904dceabaf7bca6ef2d0086ec5fbc0d6', '0939e776bb556afc372d29d3f5aaafd6', '8c25266a86af816de1bec65cb1334859', '47c52075f13f5dc85e457b8eb6d513d5', '49b786f29a49d41e9202ea3a05909ac7', '2ea2cf0cc7d4ce88f1d43e073353de48', '4fa7e9fc1057fb5f0e0ce815052a32d7', 'fa6fd2c81535552486023b98101bf1d9', '6eb4c9184cbf66d6f5176a760e356fa3', '6f38e8664c9fcac8b19907f67ac85e75', 'cd5ac721424e3f5ee4693614cca55dbf', 'ee7a25568b39269eb982a08f7cde7048', 'aa0ca0bff8bf494209fcb25f7b1a442d', '54c254cf20e1c2dfefb7c722860edd6a', '17bdf09dfa3609ac222ebb0398766304', 'fcb4fdecfad44d2d7e3023a3c69f4086', '40c86c4e0d71995e5365d264997ad44e', 'c66f083f38327d06e6dbfd1682bd2610', 'cee679439d621f161d4f9e2b9bf37afe', '6dbe96e8d5cbad64c9895dd0d0cd8318', 'dc7a7b410c771ce85dbbc25cf2164429', '44d82e13dab5e24210fbb89d093cf1e3', '90af69d3c76346af41fb68e3112415f5', '2d9d652ed3ceaf4657b82e2f9e2c342f', '91076b8abe02d29afcfd471ee586b308', 'd52cfee475931282802d8e959d40f910', '3ff22f6518c4cb6b68ac28f54e6edb64', '791f2825011fc10d30a2ea0bbfdaad13', 'db9898e3ec808b7fd421b29014262aaa', 'fc1f775975ade268d48f8fdfac9c06a7', '6213535cdd2f4d73db51344c49ac2029', '62d67708d1570155def26d9934b1cb16', '27b66bee02dabed663a12f6568ddb286', '246febf44b76695daa5d53c277ad4be1', '61a130e58aa00a66bf833fcc50f8a194', '5b4b7af1df36eb4a91d1f4de67091bbc', '246febf44b76695daa5d53c277ad4be1', '53820077835af5976e61f9b33ceb02a8', 'f13e2ca098beb2913d79abb827c83921', '105d92e972be86111cf8102d4fb26b93', 'ebbabd39e52c6a51c83bc80d2bb643a7', '36149fe1aed199b17fe128c6c92d6f92', '3469d09682b91a494b179f1803b3259e', 'cc8d5fbb14a4603a2e2bf6905353f4fa', '80d63f6ff192710ca5f5b04a1fe361e1', '9e838e84365443f47b36b8921dd2695b', '311095a2cf1855391e85ec1bb0623a37', 'f84b9264d6206087fff8a31bfff8eaf9', '422f6bdeefc20396ab24b13e47b6af91', '566723f089f9b00f6994a045ae56ccbb', '05071b4aa6d71181903f59205f11fcb7', '9e654ed5d5ac7c34ec6878f8d87c74ba', '7970c4ec950e25a994178a92c5549b42', 'de03a065386feb828ad762b8b048574b', 'efd13571714a4d86dd69fce4cb14f093', '03a474ab3ef1ada59cb9050bdbfeb907', 'a5973cb1965868fd282d0fe22d8aaa23', '422f6bdeefc20396ab24b13e47b6af91', '6afab9e04fe4baeea14824cc7d428893', '27d23ddb37ffc619c618b3eaf3ead307', '6afab9e04fe4baeea14824cc7d428893', '27d23ddb37ffc619c618b3eaf3ead307', 'cd3c6317f4e99a4581e999341da4c81c', '03bfca4c6389df01ebc8c717a87ce768', 'ce99d3116ee3039d1f34ba84ca24ec37', '2c4ab443f9d7b71039775be00fcfc188', '3fb62ad57711efbfd60ccab0df8c5ea7', '8c83802785baa2313bfa5e87a3dce3c9', '488a83f516c57a4c59588e770ac5fdb4', 'b5d9b0ee6b889635cdffb54a6266284f', 'f7e4b14e494e46ff2292201c07d55c4c', '0a0acad5f509f5a65a8741bb7ce29b9f', 'ff8303d6b32e4c35259f778b5e68a053', 'd54ebe2c3c9b52aeb0a58d450117a461', '86f4d91927bd27c4135d3a8af56c156d', 'f65f868cae23127c02d56a850934a19c', '5637de1e9525e1638b513fd837590733', 'ff8303d6b32e4c35259f778b5e68a053', 'd54ebe2c3c9b52aeb0a58d450117a461', '0a0acad5f509f5a65a8741bb7ce29b9f', '5b91b55c4f54b260cd5795c9da4a3b3b', '7d210fa8f2ee91e568e8e998fa6e50c2', 'fb7a042be1c5d86eebf6d2efd973d528', '6f72cbb5e6fddc164653df8df6647831', '00dca266f41a3c9472d585955543691b', '179a6a30b1eefd123bbf3baeef4e8c29', 'd4c6d99f55af58596bc8c5b1e4f7039f', 'b77ae628d27ea51767b3d19fb5b4d7f1', '1352314e7fe5f0f2abac1dc5687239ff', 'beeeccc0ae75f6713c369e0e81e67721', '4ec13ab05282518e79ab4f2923fe412e', 'cfb988a8cac47d2c91da30a323d0dfad', 'dc0b885ec0e179314ea701d74cb852ef', '66a3c60389c62c0c0c256133c8a6a064', '4327ffbf5ca7c5c6851c341810785e1f', '2e894970e5f3e2b09a66693d73d0521d', '45ca5b693e4833a12fd3d10193d015c6', 'bba9e64ed730db7ec64360cf35349b62', '8ce858403d653421283dca9162cdc413', '42e1a0d72193b671a209d3e9a99ea7a3', '1352314e7fe5f0f2adac1dc5687239ff', '6f043fc521cea08acb7a14ee7079ed36', '650c3a31875ee3d8f87b6b399b9c1803', 'a42a01ab63074cc4f37efe349801b2ef', '0e2a604d4e9eca68c3bb47eef754b452', '6da8bfd28386e5ffa0090f7f913cf213', '46862d3554b23381514f8c5e650e0d02', 'f1bcf23e1cb219d54739fd28e635017e', 'f1bcf23e1cb219d54739fd28e635017e', '414d7754caaf608118a047557e66de07', '3941c940dc671dfb5d54d06a8817cfce', '970135a83f2bb6469912aa36e89ed10f', '5d1af15620a09b8e6d1fd7dc796e2ea1', '94ab7b1f01ce94a35c7f990a9ab43227', '4bf48ccf0f6c9ae567bfec78416a3cd3', '7299855da36892aca46f32d8b21eccb5', '5025fb4f6e3102be7131d5da5855aac1', '8d27a9f114ce152172cafc43a9bac145', '4b719a0e0ae9daa6dce73feb00ff2717', '25ea6b1e2140c3c5ba86c034ef131ce0', '25ea6b1e2140c3c5ba86c034ef131ce0', '7240bb7b2ec93eecd7d6d3054e948705', '779b96123d649bad97b31c70dc5287d3', '48c4c429eed8de04b0188bf67103d49c', 'dcbab6fd56a506ad9d6128413a4337be', 'dc37172acb8be340a39a4c26ec801e0c', 'ffaee06a9f741f08eb7458e0a528e2dc', '4911201d043cd70617d7ce2c4063c5a7', 'b7159a90fdb9e248f2b95972f57b000b', '3cdc2e606f07f3c9e1926dc81a408802', 'cfea1b7af162216d07eeb55147950f05', '9d79a3c2253108353152d22fdd4824e8', '76af7b85a6a0fe139f2a917bd1236952', '6c86cc66acbe54f80759c1afbcb2a30b', 'df5a3f9a83efd451cbecf1fd32a89cbc', '99098c7a612a5f9b829a8b1fdffff729', 'f6a24def9c981ed29c19af6c1e275390', 'c27eb7a359d4598e5f4c178b345227dd', '6cb07ea82682cee191958d45692f489a', 'ac5a8ac622045a7e7fae07233f3d5b74', 'e43b404941b51149d298bf5f1c112928', '4034a3b90b9a6d4a1994f80841eec3f0', 'cb8c10954cf05cb6f0b1e3912ee584c8', 'e43b404941b51149d298bf5f1c112928', 'cb8c10954cf05cb6f0b1e3912ee584c8', '90e0079dc12742859a4f00d6405ff1b7', 'b04fe832a27e24af86068b069dca736f', '81950a16b53f492ea21903502df6ee11', '779a9cd81e4a672da508bcfdedf5ea5e', '43ff9241d775657e7c780abfc88d2201', 'e4d82f2020249e81fb17fa953e66ef04', 'a0056ca01c257eef2fe46496386914f5', 'dbe39e7ee48872e03cb8653a08e74b1c', 'e4d82f2020249e81fb17fa953e66ef04', 'a0056ca01c257eef2fe46496386914f5', 'b0580a9c43626f3b319e27fb41fafca2', 'dbe39e7ee48872e03cb8653a08e74b1c', '198fc17bdf7ccba6227f7a26792e7f33', 'b0580a9c43626f3b319e27fb41fafca2', 'd32805fba44fe120c6307ee6dd2cba68', '4ef96f31f70c6a9d428793cd0a37de57', '8fe6b39670ec3dc88fb1fb5646d67757', '0c76778d875236d7e0fafa59993532b3', 'dcf79dcb4d2eead0ff844ebfb1cabcad', '5049a6cf27724639f619a8a2290a3c54', '290f53c0e22fcdae077d14b0fe164194', '664146b1bf10587d6004f849a3d83dba', '41c63744126682cfd2b3e0bdc584039c', '528975258b9d71edac74c028e9cf872c', '61b37046530382c014fd1fadd9819984', '4333d547706753066d9daa2941d7a679', '9711f0f11d4dae289da72250b921fdac', '77cdc885cefb5bb8da03607816ecb7fd', 'e7c9ad086a4fc9fa799d56463c9a27de', 'a30cd660cbb29c04846977d3ae71da90', '93081c881e21d0101ec03698daa208f0', '5636c37eec0f45d21cb93e3fd2e19ede', '28ea0f091a0ab0f82b8d3ebf65ca2028', '1002ef4987e5db86dcaac771dccfac32', '0053d7752a09a6189f0c5f88d66762bc', '20e04505ef290c803889543e79426861', '8e1e5c2602988f0620173730836d1006', 'e69e01495e705a50bea75a7735fcb3b4', '4d71313cd28d65ce687d0638dca23415', '7fb03bff951e99d937bdd263a0cd182a', '77beb41e1eed736a211d21d29d8ffa09', '5fbbf313cb9b8fb672c3a0bd748ac989', '0f54c9c11e554cf588731e6ee79852f9', '2e01d6f132f88d8b391fd7d12705c426', 'b3b62c2f72b4602fd6f9d097b5c2f9e3', 'dd7adbc8e0f20abce792eb37829229cd', '6d8deff6a2b25b8a812f21b9e6bebbf0', '6df00cce46809c2765ccc3477b727985', '90f8beb304dd17dd07c4ba013a79f9bc', '8e4cc4b5d38cba4cc59d9cf867ae9fa9', '35a87eb0538579075f1bd512cab677f0', 'ba97720d19f39fb32ab83f9e7f435f8f', '3f56c720be03f9ab119d96160d2318b9', 'ee128166a0de16b0f1bfa0e4da074da9', '34ea0775456463a7d680bb6fc6f459c7', '1b5d73ac458fb2d73f6df99c83d9fcc8', 'aecfbba9926e8d839485c7f0caed2c7b', '293948a56049c8282cefa111c3188b2a', '9b77d5e27a9725136d61414a685a1e3f', 'd51af7310b192229aaa851ecd3bd50d7', '8ae15f91762fdad1e640cd779ef8613b', 'b1cae7b87b5ef48f35db204097d0aade', '01797e561399c80d37d52bedb0e00bbc', 'b67fd142d2d0cc974943a376267f0d13', '8e889fdc17e7fddc8ffd90285f1cbd6e', 'e6c41c847468b4f5dbfbc6c7e7c27047', '3dceb4939027fe383e60f7017d1de0f1', 'c7996e8e30dc24c96d3d9f7c80ac83de', 'bc77e78e6318f670e580bcd73553dc5c', '96b01255d64c533062bed6ec2010526a', '3dc0b7b0dbf892c263ef5689080957fa', '55ce38d1ff7280734ec5fc94e8ec7dcf', '91f7e0767acfffedc88c7d0246ab1d35', '3c04fe97c5b42e786a53b0ce012b57b2', '878d3e8e2854257dd9dd1d4bded722fc', '58b1722ecf72575efe5f5643cec96842', '44b6d0514441bfdd8451abd364a9ca93', 'ed38a7f02e31839092441f81ad7f47f4', 'b827812feb2eb654b494f171778430b2', 'bcf9e5f3673ea166db3304a420c43fdc', '2f87b489d8ef4f0b5dfe2ee1a2dcd610', 'ddd54a336a951a42c0b225a0d60148b0', '18c35028eacfee33f3c7c16a0fff5989', '643e0fb269a80401fdc6f3fdcf66062e', '24d8087a4055f23ae841c94698a043a6', '16437561a3baa52095b729b0373e3228', 'fda0e2c30963ce05bfecc5c8d2c9051b', '166a07fa8ea3404f6afc8daf32eabe54']
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