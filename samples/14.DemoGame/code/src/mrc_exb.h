#ifndef SKY_SDK_EXB_H
#define SKY_SDK_EXB_H

void   mrc_sand(uint32   seed);
uint32   mrc_rand(void);


  #define abs(VAL) (((VAL)>0)?(VAL):(-(VAL)))

/*
功能:
	打开、关闭LCD定时休眠功能。
	
输入:
	char CanSleep=1 时，允许LCD定时休眠；
	char CanSleep=0时，不允许LCD定时休眠。

输出：
MR_SUCCESS ：成功
MR_FAILED  ：失败
MR_IGNORE  : 不支持该功能
*/
int32 mrc_LCDCanSleep(char CanSleep);


/*
函数名:
					mrc_GetCurrentDirectory:
功能：
					获得当前目录路径，注意，返回的目录路径是GB编码的。

输入：
					nBufferLength接收目录信息的缓冲区字节数。
					lpBuffer 接收目录信息的缓冲区指针。
输出：
					当前目录。
返回值:	
					目录信息的字节数，不包括字符串结束符。
					若读取失败，则返回值为0。
*/
int32 mrc_GetCurrentDirectory(
  int32 nBufferLength,  // size, in characters, of directory buffer
  char *lpBuffer       // pointer to buffer for current directory
);

/*
函数名:
					mrc_GetDiskFreeSpaceEx:
功能：
					获得指定盘符的空间信息。

输入：
					lpDirectoryName，目标磁盘上的一个目录，若为NULL表示当前目录。
					目前限制当前目录必须为NULL，且必须是手机上的T卡；
输出：
					TotalBytes	该磁盘总的字节数；
					FreeBytes	该磁盘空闲字节数；
返回值:	
					该盘符空闲字节数，当失败或空闲字节数为0时，返回0。
*/
uint64 mrc_GetDiskFreeSpaceEx(
  uint8 *lpDirectoryName,                 // pointer to the directory name
  uint64 *TotalBytes, // receives the number of bytes on disk
  uint64 *FreeBytes // receives the free bytes on disk
  );


/*
函数名称:		mrc_strrchr

函数功能:		从一个字符串中搜索一个字符最后出现的位置。

输入参数:		string，以NULL结尾的字符串。
								c，需要查找的字符。

返回值:			函数返回字符在串中最后出现的位置指针，若没有找到，
								返回NULL。
*/
char * mrc_strrchr (
        const char * string,
        int32 ch
        );




typedef enum {
   MRP_ORICODING,//直接读取编码。只有斯凯的特权用户方可执行该类型操作。
   MRP_FILENAME,//MRP文件名称，最大11个有效字符，不包括'\0'
   MRP_APPNAME,//MRP应用名称，用户可见的应用名，最大23个有效字符，不包括'\0'，例如"雷电1944"。
   MRP_APPID,//每个应用对应一个唯一的ID，uint32类型。
   MRP_APPVER,//uint32类型   
   MRP_VENDER,//开发商信息，最大39个有效字符，不包括'\0'。
   MRP_DESCRIPTION,   //应用描述信息 ，最大63个有效字符
   MRP_VERSION,//计费通道版本编号,uint16类型，两个字节。
   MRP_CHANNEL,//计费通道编号,两个字节，低地址的RecBuf[0]是移动，高地址的RecBuf[1]是联通。
   MRP_NONE
}E_MRP_INFOID;

/*
函数名称:		mrc_GetMrpInfo

函数功能:		从当前MRP文件中读取头信息。

输入参数:		CMD，操作命令码。
								RecBuf，接收返回数据的缓冲区指针；
								BufLen，接收返回数据的缓冲区字节数；

返回值:			当操作不支持、操作失败等情况时，函数返回值小于等于0；
								若操作成功，函数返回值为RecBuf中实际填写的字节数。
备注:
	该函数尚未实现。
*/
int32 mrc_GetMrpInfo(char *MrpName,E_MRP_INFOID CMD,uint8 *RecBuf,int32 BufLen);

/*************************************************************************
  Function:       mrc_tell
  Description:    得到当前文件读写指针的位置。参考MSDN的_tell实现。
  Input:          aFileHandle:文件句柄
  Output:         
  Return:         操作结果，当前文件读写指针。返回值小于0,表示操作有误
  Others:         None
备注:
  1、此函数目前只能在模拟器上使用；在手机上使用将返回MR_FAILED(-1)；
  2、目前仅提供32bit版本，当读取文件长度超过2GB将发生溢出。
  
**************************************************************************/
int32 mrc_tell(int32 aFileHandle);

//将一个无符号32bit整数从主机字节序(little-endian)转换为网络字节序(big-endian)。
uint32 mrc_htonl(uint32 hostlong);
//将一个无符号32bit整数从网络字节序(big-endian)转换为主机字节序(little-endian)。
uint32 mrc_ntohl(uint32 netlong);

/*************************************************************************
  Function:       mrc_BCDEncode
  Description:    对输入的ASCII数字串进行BCD压缩编码。
  Input:          char *in	:ASCII数字串;
  						char *out :输出字符串缓冲区，函数调用者负责创建该缓冲区，长度
  						必须不少于mrc_strlen(in)/2+mrc_strlen(in)%2，此外，输出串无串结束标志。
  Output:        char *out	:BCD编码字符串。
  Return:         若输入参数*in和*out均不是NULL，则返回out的指针，否则返回NULL。
  Others:         None
**************************************************************************/
char* mrc_BCDEncode(char *in,char *out);

//功能同mrc_getPackName(void);
char* mrc_getPackNameMr(void);

//功能同 int32 mrc_setPackName(char * name);
int32 mrc_setPackNameMr(char * name);
#endif
