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
					目前限制必须为"C"，即手机上的T卡；
输出：
					TotalKB	该磁盘总的容量，单位为KB；
					FreeKB	该磁盘空闲容量，单位为KB；
返回值:	
					该盘符空闲字节数，当失败或空闲字节数为0时，返回0。
*/
uint32 mrc_GetDiskFreeSpace32(
  uint8 *lpDirectoryName,                 // pointer to the directory name
  uint32 *TotalKB, // receives the number of bytes on disk
  uint32 *FreeKB // receives the free bytes on disk
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
   MRP_CTRCHN,
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

/*
函数名称:mrc_BCDDecode:
	功能简介:将压缩BCD编码的数字串解码出来。
输入:
	char *bcd:	压缩BCD编码的数字串；
	int32 len:	压缩BCD编码的数字串长度；

输出:	
	char *output:	输出字符串。该空间由调用者负责申请和释放，本函数不负责申请释放内存。	
返回值:
	成功:返回指针output；
	失败:返回NULL
*/
char *mrc_BCDDecode(char *bcd,int32 len,char *output);

//功能同mrc_getPackName(void);
char* mrc_getPackNameMr(void);

//功能同 int32 mrc_setPackName(char * name);
int32 mrc_setPackNameMr(char * name);

/*
函数名称:GetCurLanguageID:
功能简介:获取手机的当前语言设置
输入:
		无；
		
输出:

返回：
MR_PLAT_VALUE_BASE值是1000
MR_PLAT_VALUE_BASE + 0 ：中文即1000
MR_PLAT_VALUE_BASE + 1 ：英文即1001
MR_FAILED              ：获取失败
MR_IGNORE              ：不支持该功能

*/
int32 GetCurLanguageID(void);


/*
函数名称:md5MakeFromMem
功能简介:将内存中的数据加入密钥后计算MD5。
输入:
char *key:	密钥。若不加入密钥，置为NULL即可。若加入密钥，
					则将密钥和数据一起计算MD5
uint8* in:		数据区指针。
int32 offset:	从in+offset的地址偏移开始的len个字节的数据计算MD5。
					如果offset<0，返回失败。
int32 len:		需要计算的数据区总字节数，若该值小于0，返回失败。
					如果len=0，若key!=NULL，则将返回key的MD5，
					否则len==0 && key==NULL，返回的MD5值依赖于MD5函数的具体实现。

输出:
uint8* out:	若函数返回MR_SUCCESS，则通过out返回16个字节的MD5校验值。
					这16个字节的内存由调用者申请、释放。

返回：
MR_SUCCESS:MD5获取成功。
MR_FAILED    :获取失败，此时out中的值是不确定的，不可作为MD5值使用。
*/
int32 md5MakeFromMem(char *key,uint8* in,int32 offset , int32 len, uint8* out);


/*
函数名称:md5MakeFromFileHandle
功能简介:将文件中的数据加入密钥计算MD5。
输入:
char *key:	密钥。若不加入密钥，置为NULL即可。若加入密钥，
					则将密钥和数据一起计算MD5。
int32 fhandle:	需要计算MD5的文件句柄。
int32 offset:	从文件头的offset字节的地址偏移开始的len个字节的数据计算MD5。
					如果offset<0，返回失败。
int32 len:		需要计算的数据区总字节数。
				(1)、若该值小于0，返回失败。
				(2)、如果len=0，若key!=NULL，则将返回key的MD5，否则
							若len==0 && key==NULL，返回的MD5值依赖于MD5函数的具体实现。
				(3)、由于暂时不能通过文件句柄获取文件长度，所以将在
							连续9次读取失败或者连续9次读到0个字节时返回失败，
							即(len+offset)>filelen时通常将返回失败。
输出:
uint8* out:	若函数返回MR_SUCCESS，则通过out返回16个字节的MD5校验值。
					这16个字节的内存由调用者申请、释放。

返回：
MR_SUCCESS:MD5获取成功。
MR_FAILED    :获取失败，此时out中的值是不确定的，不可作为MD5值使用。
*/
int32 md5MakeFromFileHandle(char *key,int32 fhandle,int32 offset , int32 len, uint8* out);
/*
函数名称:md5MakeFromFile
功能简介:将文件中的数据加入密钥计算MD5。
输入:
char *key:	密钥。若不加入密钥，置为NULL即可。若加入密钥，
					则将密钥和数据一起计算MD5
char *filename:	需要计算MD5的文件名。
int32 offset:	从文件头的offset字节的地址偏移开始的len个字节的数据计算MD5。
					如果offset<0，返回失败。
int32 len:		需要计算的数据区总字节数，
				(1)、若该值小于0，返回失败。
				(2)、如果len=0，若key!=NULL，则将返回key的MD5，否则
							若len==0 && key==NULL，返回的MD5值依赖于MD5函数的具体实现。
				(3)、如果(offset+len)>文件长度，则取到文件末尾为止，不触发错误。
					
输出:
uint8* out:	若函数返回MR_SUCCESS，则通过out返回16个字节的MD5校验值。
					这16个字节的内存由调用者申请、释放。

返回：
MR_SUCCESS:MD5获取成功。
MR_FAILED    :获取失败，此时out中的值是不确定的，不可作为MD5值使用。
*/
int32 md5MakeFromFile(char *key,char *filename,int32 offset , int32 len, uint8* out);


/*
函数名称:md5ToString
功能简介:将16字节的MD5校验值转换为32字节的ASCII可见字符串。
输入:
uint8 *in:	MD5校验值。
输出:
uint8* out:	若函数返回MR_SUCCESS，则通过out返回32个字节的MD5校验值。
					这32个字节的内存由调用者申请、释放。

返回：
MR_SUCCESS:MD5获取成功。
MR_FAILED    :获取失败
*/
int32 md5ToString(uint8* in, uint8* out);



/*
加速传感器使用说明
使用步骤。
1、	配置加速传感器参数，如果返回 MR_IGNORE 那么就不支持。
2、	配置成功以后，启动加速传感器。启动成功以后，就可以在mr_event()
中接收数据了。
3、	mr_event()中
param1  MR_MOTION_TITLE事件以后表示有接收到加速传感器的事件了。
Param2  表示x、y方向的偏移，x占用低位16bit，y占用高位的16bit，
Param3  表示z方向偏移
应用程序只需要对这些数据进行处理就可以。
4、	停止加速传感器，应用使用结束以后停止传感器。

特别注明：
对于有需要监听direct（方向）、shark（震动）、转动角度方面需求，可以通过增加对x
、y、z这些原始数据处理以后得到。
*/



typedef enum
{
    MR_MOTION_SENSITIVE_LOW,
    MR_MOTION_SENSITIVE_NORMAL,
    MR_MOTION_SENSITIVE_HIGH,

    NUM_OF_MDI_MOTION_SENSITIVE
} MR_MOTION_SENSITIVE_ENUM;//传感器的敏感度。枚举类型。

typedef struct 
{
	uint8 isStart;
	int32 key;//0:IDLE,2:up,4:left;6:right;8:down
	int16 x;
	int16 y;
	int32 maxRange;
}CTRL_MOTION2KEY_T;
int32 mrc_motion2KeyStart(int32 sensitive);
int32 mrc_motion2Key(CTRL_MOTION2KEY_T *ctrlMotion2key,int32 *code,int32 *param0,int32 *param1);
int32 mrc_motion2KeyStop(void);

typedef enum
{
    MOTION_SENSITIVE_LOW,
    MOTION_SENSITIVE_NORMAL,
    MOTION_SENSITIVE_HIGH
}MOTION_SENSITIVE_T;

typedef enum
{
	MOTION_SHAKE_NO_DIRECT,
	MOTION_SHAKE_LEFT,
	MOTION_SHAKE_RIGHT,
	MOTION_SHAKE_FORWARD,
	MOTION_SHAKE_BACKWARD
}MOTION_SHAKE_T;

typedef enum
{
	MOTION_EVENT_SHAKE,
	MOTION_EVENT_TILT
}MOTION_EVENT_T;

typedef struct
{
	int32 x;
	int32 y;
	int32 z;
}T_MOTION_TILT;

#define MR_MOTION_STOP_LISTEN               4001
#define MR_MOTION_SENOR_PWRON 		4002
#define MR_MOTION_SENOR_PWROFF 		4003
#define MR_MOTION_LISTEN_SHAKE             4004
#define MR_MOTION_LISTEN_TILT                4005
#define MR_MOTION_SENSOR_MAXRANGE	4006

//打开传感器
int32 mrc_motionSensorPowerOn(void);

//关闭传感器
int32 mrc_motionSensorPowerOff(void);

//暂停接收传感器事件
int32 mrc_motionSensorStopListen(void);

//监听晃动事件
int32 mrc_motionSensorStartShakeListen(int32 sensitive);

//监听倾角事件
int32 mrc_motionSensorStartTiltListen(int32 sensitive);

/*获取返回参数的取值范围的最大值MAXRANGE。
成功:
	返回MR_PLAT_VALUE_BASE+MAXRANGE；因此需要将最终结果减去1000(MR_PLAT_VALUE_BASE的值)
失败:
	返回MR_FAILED;
不支持:
	返回MR_INGORE;
*/
int32 mrc_motionSensorGetRange(void);


/*
函数名:mrc_unicodeToGb2312
输入：
将unicode编码的字符串转成gb2312编码
input：需要转换的unicode字符串
input_len:需要转换的unicode字符串长度，单位字节数
output：转换成功以后的bg2312编码字符串存放缓冲区，
缓冲区的内存由应用调用者提供并管理、释放。
注意：该输出缓冲区必须使用malloc分配处理的空间，否则手机可能会出现重启。
output_len：output缓冲区的长度，单位字节数

返回：
    MR_SUCCESS	转换成功
    MR_FAILED   转换失败

*/
int32 mrc_unicodeToGb2312(uint8* input, int32 input_len, uint8** output, int32* output_len);


/*
函数名:mrc_getRegAppAddr
	获取固化应用、内存镜像应用的运行时加载地址。
	应用名称可以通过mrc_getPackName()获取。
输入：
char *MrpName:	应用名称，固化应用都是"*"开头	的，RAM应用都是"$"开头的；

返回：
NULL:获取失败；
其他值为应用内存地址。
*/
int32 mrc_getRegAppAddr(char *MrpName);



//-----------------------录音功能-------------------------------------
enum
{
	DSM_ERROR_NO_ERROR =0,
	DSM_ERROR_UNKNOW,
	DSM_ERROR_NO_SPACE,
	DSM_ERROR_TERMINATED
};

typedef enum
{
   SRC_NAME = 0,    //传到移植接口是文件名
   SRC_STREAM   //传到移植接口的是图片数据流
}VOICE_REC_TYPE;

typedef struct{
    char *src;       		//录音文件的相对文件名，当采用stream模式下可为NULL
    int32 src_len;		//当采用stream模式时忽略该参数。
    int32 src_type;	//参见VOICE_REC_TYPE，若为 SRC_STREAM 表示实时获取数据流模式。
    int32 format;		//MR_SOUND_WAV , MR_SOUND_PCM , MR_SOUND_AMR , MR_SOUND_AMR_WB 
}VOICE_REC_REQ_T;

typedef void (*VOICE_REC_CB)(uint8* output, int32 output_len);

/*
函数名:mrc_voiceRecStart



输入：
VOICE_REC_REQ_T *voiceCtl

返回：
MR_SUCCESS	: 	请求成功
MR_FAILED  		:	请求失败
MR_IGNORE  	:	不支持该功能

注：
录音的异常情况通过mr_event通知，mr_event的参数如下：
第一个：MR_ERROR_EVENT
第二个：DSM_ERROR_NO_SPACE	：空间满
        				DSM_ERROR_TERMINATED：被中断
        				DSM_ERROR_UNKNOW		：未知错误
第三个：0
*/
int32 mrc_voiceRecStart(VOICE_REC_REQ_T *voiceCtl);

/*
函数名:mrc_voiceRecStreamProc
	stream录音模式下获取当前已录数据，比如使用者可以开启个几十毫秒的定时器定时查询、获取、处理数据。
输入：
	无； 
输出:
	*output  ：当前录音数据读取地址；
    *output_len  ：录音数据长度；
	MR_PLAT_EX_CB *cb ： 当output_len>0 并且 应用处理完毕上面地址中的数据时，必须调用此回调以移动设备缓冲的读指针。

返回：
MR_SUCCESS	: 	请求成功
MR_FAILED  		:	请求失败
MR_IGNORE  	:	不支持该功能

注意:
	若使用流方式录音且使用WAV格式，需要在录音结束后由应用添加wav头信息，否则无法播音。
*/
int32 mrc_voiceRecStreamProc(uint8 **output,int32 *output_len,VOICE_REC_CB *cb);

/*
函数名:mrc_voiceRecPause
	暂停录音
输入：
	无。 
输出:
	无。
返回：
MR_SUCCESS	: 	请求成功
MR_FAILED  		:	请求失败
MR_IGNORE  	:	不支持该功能
*/
int32 mrc_voiceRecPause(void);

/*
函数名:mrc_voiceRecResume
	恢复录音
输入：
	无。 
输出:
	无。
返回：
MR_SUCCESS	: 	请求成功
MR_FAILED  		:	请求失败
MR_IGNORE  	:	不支持该功能
*/
int32 mrc_voiceRecResume(void);

/*
函数名:mrc_voiceRecStop
	停止录音
输入：
	无。 
输出:
	无。
返回：
MR_SUCCESS	: 	请求成功
MR_FAILED  		:	请求失败
MR_IGNORE  	:	不支持该功能
*/
int32 mrc_voiceRecStop(void);


#define MRC_PLAT_VALUE_BASE 1000

/*
函数名:mrc_isTouchSupport
	功能：获取手机是否是触摸屏信息。
	输入：
		  无
	返回：
	MRC_PLAT_VALUE_BASE	：非触摸屏
	MRC_PLAT_VALUE_BASE+1	：触摸屏
	MR_FAILED	：获取失败。
	MR_IGNORE	：不支持获取触摸屏信息。

*/
int32 mrc_isTouchSupport(void);



int32 mrc_writeBigEndianU32(uint32 data,uint8 *p);

int32 mrc_writeBigEndianU16(uint16 data,uint8 *p);

uint32 readBigEndianUint32(uint8 *p);

uint16 readBigEndianUint16(uint8 *p);

uint32 readLittleEndianUint32(uint8 *p);

uint16 readLittleEndianUint16(uint8 *p);

typedef struct
{
	uint8       IMEI[16];	     //IMEI 长度为15字节
	uint8       IMSI[16];	     //IMSI 长度为15字节
	char        manufactory[8];  //手机设计公司名，最大7个字符，空字节填\0
	char        type[8];         //手机研发项目名，mobile type，最大7个字符，空字节填\0
	uint32      ver;             //移植软件版本
	uint8       spare[12];       //备用
}MRC_PHONEINFO_T;
/*
函数名:mrc_getphoneInfo
	功能：获取手机的厂商机型信息。
	输入：
		  无
	输出:
			MRC_PHONEINFO_T* phoneInfo;其中的IMSI号码是伪码，只是真实的IMSI的映射。
	返回：
	MR_SUCCESS :	获取乘公共。
	MR_FAILED	：获取失败。
	MR_IGNORE	：不支持获取触摸屏信息。

*/

int32 mrc_getphoneInfo(MRC_PHONEINFO_T* phoneInfo);



/*
函数名:mrc_getSdkVer
	功能：获取SDK计费模块版本号。
	输入：
		  无
	返回：
		SDK的版本号。版本号为AABBCCCDDD形式的int32整数，其中，
		AA为最高位版本号；
		BB为次高位版本号；
		CCC是子功能版本号，每次有大的功能变化都将修改子功能版本号。
		DDD是Build版本号，每次改动代码之后，都将修改Build版本号。

*/

int32 mrc_getSdkVer(void);

typedef struct
{
	char       IMEI[16];	     //IMEI 长度为15字节，最后一个字节用'\0'填充
	char       IMSI[16];	     //IMSI 长度为15字节，最后一个字节用'\0'填充
	char       manufactory[8];  //手机设计公司名，最大7个字符，空字节填\0
	char       type[8];         //手机研发项目名，mobile type，最大7个字符，空字节填\0
	unsigned int     ver;             //移植软件版本
	unsigned char    spare[12];       //备用
}MR_PHONEINFO_T;

/*
函数名:mrc_editNetworkAccount
	功能：用户编译网络接入帐号。只有海外的联网应用需要使用这个接口。
	
	因为海外的运营商很多，各个运营商使用的帐号资料也不尽相同。而且网关地址也可能不一样。所以为了处理这样复杂的情况。我们做了如下假定：
	A． 海外版本只支持直接连接互联网的模式（避免网关地址不同的情况）
	B． 开放接口，在连接网络失败的情况下，让用户来设置正确的帐号资料

	1.	在海外的版本中需要增加一个菜单。这个菜单的功能就是让用户来设置正确的帐号资料。调用的接口是：mrc_editNetworkAccount();调用这个接口之后应用会收到PAUSE事件，
	等用户输入正确的信息后，应用会收到RESUME事件，同时需要应用保存一个标志位来表明用户是否已经设置过新的帐号资料，以后每次运行该应用在调用mr_initNetWork的前都需要判断这个标志位，并调用接口来设置这个标志位：
	设置标志位的接口是：mrc_selectNetworkAccount(option) 的值的含义如下：
	option：
		0：使用用户设置的帐号资料
	   	1：使用出厂预设的帐号资料

	
	输入：
		  无
	返回：
	MR_SUCCESS :	设置成功。
	MR_FAILED	:	设置失败。
	MR_IGNORE	:	不支持。

*/
int32 mrc_editNetworkAccount(void);

/*
函数名:mrc_editNetworkAccount
	功能：用户编译网络接入帐号。只有海外的联网应用需要使用这个接口。
	
	因为海外的运营商很多，各个运营商使用的帐号资料也不尽相同。而且网关地址也可能不一样。所以为了处理这样复杂的情况。我们做了如下假定：
	A． 海外版本只支持直接连接互联网的模式（避免网关地址不同的情况）
	B． 开放接口，在连接网络失败的情况下，让用户来设置正确的帐号资料

	1.	在海外的版本中需要增加一个菜单。这个菜单的功能就是让用户来设置正确的帐号资料。调用的接口是：mrc_editNetworkAccount();调用这个接口之后应用会收到PAUSE事件，
	等用户输入正确的信息后，应用会收到RESUME事件，同时需要应用保存一个标志位来表明用户是否已经设置过新的帐号资料，以后每次运行该应用在调用mr_initNetWork的前都需要判断这个标志位，并调用接口来设置这个标志位：
	设置标志位的接口是：mrc_selectNetworkAccount(option) 的值的含义如下：
	option：
		0：使用用户设置的帐号资料
	   	1：使用出厂预设的帐号资料

	
	输入：
		  无
	返回：
	MR_SUCCESS :	设置成功。
	MR_FAILED	:	设置失败。
	MR_IGNORE	:	不支持。

*/
int32 mrc_selectNetworkAccount(int32 option);

#endif
