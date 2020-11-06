#ifndef MRC_BASE_H
#define MRC_BASE_H

/*
��ͷ�ļ��а�����mythroadֱ��֧�ֵĸ��ֺ������ã�
�Լ���ں�����
*/
#ifndef SIM_MOD
	typedef  unsigned long long  uint64;      /* Unsigned 64 bit value */
	typedef  long long                int64;      /* signed 64 bit value */
#else
	typedef	unsigned _int64	uint64;
	typedef	 _int64	int64;
#endif
typedef  unsigned short     uint16;      //�з���16bit����
typedef  unsigned long int  uint32;      //�޷���32bit����
typedef  long int                int32;      //�з���32bit����
typedef  unsigned char      uint8;        //�޷���8bit����
typedef  signed char          int8;        //�з���8bit����
typedef  signed short         int16;       //�з���16bit����

#define MR_SUCCESS  0    //�ɹ�
#define MR_FAILED   -1    //ʧ��
#define MR_IGNORE   1     //������
#define MR_WAITING   2     //�첽(������)ģʽ

#ifndef NULL
#define NULL (void*)0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifdef MR_SPREADTRUM_MOD
#pragma no_check_stack
#endif

enum {
   MR_KEY_0,               //���� 0
   MR_KEY_1,               //���� 1
   MR_KEY_2,               //���� 2
   MR_KEY_3,               //���� 3
   MR_KEY_4,               //���� 4
   MR_KEY_5,               //���� 5
   MR_KEY_6,               //���� 6
   MR_KEY_7,               //���� 7
   MR_KEY_8,               //���� 8
   MR_KEY_9,               //���� 9
   MR_KEY_STAR,            //���� *
   MR_KEY_POUND,           //���� #
   MR_KEY_UP,              //���� ��
   MR_KEY_DOWN,            //���� ��
   MR_KEY_LEFT,            //���� ��
   MR_KEY_RIGHT,           //���� ��
   MR_KEY_POWER,           //���� �һ���
   MR_KEY_SOFTLEFT,        //���� �����
   MR_KEY_SOFTRIGHT,       //���� �����
   MR_KEY_SEND,            //���� ������
   MR_KEY_SELECT,          //���� ȷ��/ѡ����������м���ȷ�ϼ���������Ϊ�ü���
   MR_KEY_VOLUME_UP,          //���� �����
   MR_KEY_VOLUME_DOWN,          //���� �����
   MR_KEY_NONE             //���� ����
};

enum {
   MR_NET_ID_MOBILE,                  //�ƶ�
   MR_NET_ID_CN,          // ��ͨgsm
   MR_NET_ID_CDMA,       //��ͨCDMA
   MR_NET_ID_NONE       //δ�忨
};

enum {
   MR_EDIT_ANY,                  //�κ��ַ�
   MR_EDIT_NUMERIC,          // ����
   MR_EDIT_PASSWORD       //���룬��"*"��ʾ
};

enum {
   MR_SIM_NEW,     //���ֻ���һ�β���SIM��
   MR_SIM_CHANGE, //�û�����SIM��
   MR_SIM_SAME    //δ���л�������
};

enum {
   MR_DIALOG_OK,                   //�Ի�����"ȷ��"����
   MR_DIALOG_OK_CANCEL,    //�Ի�����"ȷ��" "ȡ��"����
   MR_DIALOG_CANCEL           //�Ի�����"����"����
};

enum {
   MR_DIALOG_KEY_OK,         //�Ի���/�ı���ȵ�"ȷ��"�������(ѡ��)
   MR_DIALOG_KEY_CANCEL  //�Ի���/�ı���ȵ�"ȡ��"("����")�������(ѡ��)
};

enum {
   MR_LOCALUI_KEY_OK,       //���ؿؼ���"ȷ��"�������(ѡ��)
   MR_LOCALUI_KEY_CANCEL//���ؿؼ���"ȡ��"("����")�������(ѡ��)
};


enum {
   MR_KEY_PRESS,           //���������¼�
   MR_KEY_RELEASE,        //�����ͷ��¼�
   MR_MOUSE_DOWN,       //����������꣩�����¼�
   MR_MOUSE_UP,            //����������̧꣩��/�ͷ��¼�
   MR_MENU_SELECT,       //�˵�ѡ���¼�
   MR_MENU_RETURN,       //�˵������¼�
   MR_DIALOG_EVENT,      // �Ի���/�༭��/�ı����¼�
   MR_EVENT01,                //VM�������벻Ҫʹ��
   MR_EXIT_EVENT,           //Ӧ���˳��¼�
   MR_EVENT02,                 //VM�������벻Ҫʹ��
   MR_LOCALUI_EVENT,         //���ػ��ӿ��¼�
   MR_OSD_EVENT,            	//11
   MR_MOUSE_MOVE,          //12	ע�⣬ֻ�к��µĻ��Ͳ�֧�ָ��¼���
   MR_ERROR_EVENT,        	//13ִ���쳣ͨ������¼���֪ͨ   
   MR_TIMER_EVENT = 1001,
   MR_NET_EVENT

};

typedef enum 
{
   MR_SOUND_MIDI,
   MR_SOUND_WAV,
   MR_SOUND_MP3,
   MR_SOUND_PCM, //8K 16bit
   MR_SOUND_M4A,
   MR_SOUND_AMR,
   MR_SOUND_AMR_WB
}MR_SOUND_TYPE;

typedef enum 
{
   MR_FONT_SMALL,
   MR_FONT_MEDIUM,
   MR_FONT_BIG
}MR_FONT_TYPE;

enum
{
   MR_SEEK_SET,             //���ļ���ʼ��ʼ
   MR_SEEK_CUR,             //�ӵ�ǰλ�ÿ�ʼ
   MR_SEEK_END             //���ļ�ĩβ��ʼ
};

enum
{
   MR_SOCK_STREAM,
   MR_SOCK_DGRAM
};

enum
{
   MR_IPPROTO_TCP,
   MR_IPPROTO_UDP
};

enum
{
   MR_ENCODE_ASCII,
   MR_ENCODE_UNICODE
};

enum {
   MR_SOCKET_BLOCK,          //������ʽ��ͬ����ʽ��
   MR_SOCKET_NONBLOCK       //��������ʽ���첽��ʽ��
};

enum {
   BM_OR,         //SRC .OR. DST*   ��͸��Ч��
   BM_XOR,        //SRC .XOR. DST*
   BM_COPY,       //DST = SRC*      ����
   BM_NOT,        //DST = (!SRC)*
   BM_MERGENOT,   //DST .OR. (!SRC)
   BM_ANDNOT,     //DST .AND. (!SRC)
   BM_TRANSPARENT, //͸��ɫ����ʾ��ͼƬ�ĵ�һ�����أ����Ͻǵ����أ���͸��ɫ
   BM_AND,
   BM_GRAY,
   BM_REVERSE
};

#define MR_IS_FILE     1      //�ļ�
#define MR_IS_DIR      2      //Ŀ¼
#define MR_IS_INVALID  8  //��Ч(���ļ�����Ŀ¼)

#define MR_FILE_RDONLY         1//��ֻ���ķ�ʽ���ļ���
#define MR_FILE_WRONLY        2//��ֻд�ķ�ʽ���ļ���
#define MR_FILE_RDWR             4//�Զ�д�ķ�ʽ���ļ���
#define MR_FILE_CREATE          8//����ļ������ڣ��������ļ���
#define MR_FILE_RECREATE      16//�����ļ��治���ڣ������´������ļ���

#define DRAW_TEXT_EX_IS_UNICODE          1 //�Ƿ�ʹ��UNICODE��, �����ֽ���
#define DRAW_TEXT_EX_IS_AUTO_NEWLINE    2 //�Ƿ��Զ�����

#define MR_PLAT_VALUE_BASE 1000    //����ĳЩ����ֵ�Ļ���ֵ


typedef struct
{
   int32 socket;
   int32 port;
}mr_bind_st;

typedef struct
{
   uint16 year;                 //��
   uint8  month;                //��
   uint8  day;                  //��
   uint8  hour;                 //ʱ��24Сʱ��
   uint8  minute;               //��
   uint8  second;               //��
}mr_datetime;

typedef struct
{
   uint32 width;                  //��Ļ��
   uint32 height;                 //��Ļ��
   uint32 bit;                    //��Ļ������ȣ���λbit
}mr_screeninfo;


typedef struct {
   uint16            w;           //ͼƬ��
   uint16            h;           //ͼƬ��
   uint32            buflen;  //ͼƬ���峤��
   uint32            type;     //ͼƬ��������
   uint16*            p;        //ͼƬ����ָ��
}mr_bitmapSt;

typedef struct {
   uint16*            p;        //ͼƬ����ָ��
   uint16            w;           //ͼƬ��
   uint16            h;           //ͼƬ��
   uint16            x;
   uint16            y;
}mr_bitmapDrawSt;

typedef struct {
   uint16            x;
   uint16            y;
   uint16            w;
   uint16            h;
}mr_screenRectSt;

typedef struct {
   uint8            r;
   uint8            g;
   uint8            b;
}mr_colourSt;

typedef struct {
   uint16            h;
}mr_spriteSt;

typedef struct  {
   int16            x;
   int16            y;
   uint16            w;
   uint16            h;
   int16            x1;
   int16            y1;
   int16            x2;
   int16            y2;
   uint16            tilew;
   uint16            tileh;
}mr_tileSt;


/********************************C�⺯��********************************/
/*
һ�㲻�Ƽ���mythroad������ʹ��C��׼�Ŀ⺯����
һЩC��׼�Ŀ⺯���ᵼ��mythroad���������ʧ
�ܡ���Ȼʹ��C��׼�⺯���ǲ��Ƽ��ģ�������
�������ʹ��C��׼�⺯����Ӧ��Ҳ�ǿ�������
�ģ���ʹ��δ����֤��C��׼�⺯�������ܻ���
�ڲ����ֻ�֧�ֶ��������������⡣mythroadƽ̨
�ṩһЩ��Ϊ���õ�C�⺯�����뾡��ʹ����Щ
������
*/

/*�ú���������printf�������ƣ������Ǳ����������
��Ϣ����ӡ���ֻ���trace��*/
extern void (*mrc_printf)(const char *format,...);

/*
��κ���Խ�Դ�����е�C��׼�Ŀ⺯���滻Ϊ
mythroadƽ̨֧�ֵĶ�Ӧ������
*/

//#define MEM_LEAK_DEBUG
#if defined SDK_MOD &&  defined MEM_LEAK_DEBUG
void *mrc_mallocEx(int size, char* file, int line);
#define malloc(size) mrc_mallocEx(size, __FILE__, __LINE__)
#define free(p) {\
	mrc_free(p);\
	mrc_printf("free,%lu,FILE:%s,LINE:%d", p, __FILE__, __LINE__);\
}
#else	

#define malloc   mrc_malloc   
#define free     mrc_free     
#endif /* defined SDK_MOD &&  defined MEM_LEAK_DEBUG */


#define strchr   mrc_strchr   
#define memcpy   mrc_memcpy   
#define memmove  mrc_memmove  
#define strcpy   mrc_strcpy   
#define strncpy  mrc_strncpy  
#define strcat   mrc_strcat   
#define strncat  mrc_strncat  
#define memcmp   mrc_memcmp   
#define strcmp   mrc_strcmp   
#define strncmp  mrc_strncmp  
#define strcoll  mrc_strcoll  
#define memchr   mrc_memchr   
#define memset   mrc_memset   
#define strlen   mrc_strlen   
#define strstr   mrc_strstr   
#define sprintf  mrc_sprintf             
#define atoi     mrc_atoi     
#define strtoul  mrc_strtoul  

extern void *(*MR_MEMCPY)(void * s1, const void * s2, int n);
extern void *(*MR_MEMMOVE)(void * s1, const void * s2, int n);
extern char *(*MR_STRCPY)(char * s1, const char * s2);
extern char *(*MR_STRNCPY)(char * s1, const char * s2, int n);
extern char *(*MR_STRCAT)(char * s1, const char * s2);
extern char *(*MR_STRNCAT)(char * s1, const char * s2, int n);
extern int (*MR_MEMCMP)(const void * s1, const void * s2, int n);
extern int (*MR_STRCMP)(const char * s1, const char * s2);
extern int (*MR_STRNCMP)(const char * s1, const char * s2, int n);
extern int (*MR_STRCOLL)(const char * s1, const char * s2);
extern void *(*MR_MEMCHR)(const void * s, int c, int n);
extern void *(*MR_MEMSET)(void * s, int c, int n);
extern int (*MR_STRLEN)(const char * s);
extern char *(*MR_STRSTR)(const char * s1, const char * s2);
extern int (*MR_SPRINTF)(char * s, const char * format, ...);
extern int (*MR_ATOI)(const char * nptr);
extern unsigned long int (*MR_STRTOUL)(const char * nptr, char ** endptr, int base);

extern void* mrc_malloc(int size);
extern void mrc_free(void *address);
extern void mrc_freeEx(void *address);//ר������ʹ�õĺ���������memset
extern const char *mrc_strchr(const char *src,int c);
extern int32 mrc_wstrlen(char * txt);

#define mrc_memcpy(s1, s2, n)       MR_MEMCPY(s1, s2, n)
#define mrc_memmove(s1, s2, n)   MR_MEMMOVE(s1, s2, n)
#define mrc_strcpy(s1, s2)              MR_STRCPY(s1, s2)
#define mrc_strncpy(s1, s2, n)        MR_STRNCPY(s1, s2, n)
#define mrc_strcat(s1, s2)               MR_STRCAT(s1, s2)
#define mrc_strncat(s1, s2, n)         MR_STRNCAT(s1, s2, n)
#define mrc_memcmp(s1, s2, n)      MR_MEMCMP(s1, s2, n)
#define mrc_strcmp(s1, s2)              MR_STRCMP(s1, s2)
#define mrc_strncmp(s1, s2, n)         MR_STRNCMP(s1, s2, n)
#define mrc_strcoll(s1, s2)               MR_STRCOLL(s1, s2)

#define mrc_memchr(s1, c, n)          MR_MEMCHR(s1, c, n)
#define mrc_memset(s1, c, n)          MR_MEMSET(s1, c, n)
#define mrc_strlen(s)                       MR_STRLEN(s)
#define mrc_strstr(s1, s2)               MR_STRSTR(s1, s2)
#define mrc_sprintf                         MR_SPRINTF
#define mrc_atoi(s1)                       MR_ATOI(s1)
#define mrc_strtoul(s1, s2, n)         MR_STRTOUL(s1, s2, n)

#define MR_MALLOC(size) mrc_malloc(size)
#define MR_FREE(p, size) mrc_free(p)
/********************************C�⺯������********************************/

/*ȡ�û�ȡunicode��chָ�������ĵ�����Ϣ������֮
������Ŀ�͸ߣ���ȡ���ĵ�����Ϣÿһ��bit��ʾ
�����һ�����أ�����ÿ�е����ر��밴�ֽڶ��䣬
Ҳ����˵���һ�������Ϊ12������Ҫ�������ֽ�
����ʾ����Ϣ���ڶ����ֽڵĺ��ĸ�bitΪ0���ӵ���
���ֽڿ�ʼ�ű�ʾ��һ�еĵ�������*/
char *mrc_getCharBitmap(uint16 ch, uint16 fontSize, int *width, int *height);

/********************************�ļ��ӿ�********************************/
/*
�ú������ڵ���ʹ�ã����ص������һ�β����ļ�
ʧ�ܵĴ�����Ϣ�����صĴ�����Ϣ���庬����ƽ̨
��ʹ�õ��ļ�ϵͳ�йء�
�ú������ܱ�ʵ��Ϊ���Ƿ���MR_SUCCESS��
����:
      ���һ�β����ļ�ʧ�ܵĴ�����Ϣ
*/
int32 mrc_ferrno(void);

/*
��mode��ʽ���ļ�������ļ������ڣ�����modeֵ
�ж��Ƿ񴴽�֮��
�������
����	˵��
����˵��
����״̬	˵�� 
�� NULL	�ļ����
NULL	ʧ�ܣ�ע�⣬�����������ӿڲ�һ����

����:
filename	�ļ���
mode	�ļ��򿪷�ʽ
         modeȡֵ
                MR_FILE_RDONLY   //��ֻ���ķ�ʽ���ļ���
                MR_FILE_WRONLY   //��ֻд�ķ�ʽ���ļ���
                                    �������ʽ���ܱ�ʵ��Ϊ��
                                    MR_FILE_RDWR��ͬ�Ĳ�����
                MR_FILE_RDWR      //�Զ�д�ķ�ʽ���ļ���
                MR_FILE_CREATE     //����ļ������ڣ�����
                                    ���ļ����ò������ᵥ������
                                    ��ֻ��������ֵһͬ���֣�ʹ
                                    ��"��"���㣩
               mode���ܵ�ȡֵ��
               a��	ǰ��������������һ��
               b��	ǰ��������������һ����MR_FILE_CREATE��"��"ֵ
����:
�� NULL	       �ļ����
NULL	            ʧ�ܣ�ע�⣬�����������ӿڲ�һ����
*/
int32 mrc_open(const char* filename,  uint32 mode);

/*
�ر��ļ���
����:
f	�ļ����
����:
MR_SUCCESS	�ɹ�
MR_FAILED	ʧ��
*/
int32 mrc_close(int32 f);

/*
ȡ���ļ�������Ϣ��
����:
filename	�ļ���
����:
      MR_IS_FILE     1//���ļ�
      MR_IS_DIR      2//��Ŀ¼
      MR_IS_INVALID  8//�ļ������ڣ���Ȳ����ļ�Ҳ����Ŀ¼
*/
int32 mrc_fileState(const char* filename);

/*
д�ļ�
����:
f	�ļ����
p	��д�����ݴ�ŵ�ַ
l	��д�����ݳ���
����:
      >0                   ȷ��д����ֽ���
      MR_FAILED      ʧ��
*/
int32 mrc_write(int32 f,void *p,uint32 l);

/*
��ȡ�ļ������ݵ�ָ���Ļ��塣
����:
f	�ļ����
p	�ļ������ַ
l	���峤��
����:
      >=0                ȷ�ж�ȡ���ֽ���
      MR_FAILED      ʧ��
*/
int32 mrc_read(int32 f,void *p,uint32 l);

/*
��ȡ�ļ����������ݵ�������ڴ��С�
����:
filename	�ļ���
���:
len           ��ȡ�������ݳ���
����:
      ��NULL         ָ���ȡ�������ݵ�ָ�룬���ڴ���Ҫ
                              �������ͷ�
      NULL              ʧ��
*/
void* mrc_readAll(const char* filename, uint32 *len);


/*
�����ļ�ָ�롣
����:
f	�ļ����
pos	�ļ�ָ��λ��
method	���ܵ�ȡֵΪ��
   MR_SEEK_SET, 
   MR_SEEK_CUR, 
   MR_SEEK_END
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_seek(int32 f, int32 pos, int method);

/*
ȡ���ļ����ȡ�
����:
filename	�ļ��� 
����:
      >=0   �ļ�����
      MR_FAILED   ʧ��/�ļ�������
*/
int32 mrc_getLen(const char* filename);

/*
ɾ���ļ���
����:
filename	�ļ���
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_remove(const char* filename);

/*
�ļ���������
����:
oldname	���ļ���
newname	���ļ���
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_rename(const char* oldname, const char* newname);

/*
����Ŀ¼��
����:
name	Ŀ¼��
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_mkDir(const char* name);

/*
ɾ��Ŀ¼�Լ�Ŀ¼������ļ�����Ŀ¼��
����:
name	Ŀ¼��
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_rmDir(const char* name);

/*
׼������nameָ����Ŀ¼����dsm���øú�����ϵͳ
��ʼ��һ��Ŀ¼�����������ص�һ��Ŀ¼�����Ľ��
��ÿ��dsm����һ��mr_c_findGetNext������ϵͳ������һ��
��Ŀ¼�µ��ļ���һ����Ŀ¼�����ú���ֻ���ز���
�������nameΪ���ַ���""ʱ��ע��nameָ��մ�����
name����NULL��������Mythroadƽ̨������ļ���ǰĿ¼��
�磺���ֻ���"/dsmdata/"��ΪMythroadƽ̨������ļ���ǰ
Ŀ¼����nameΪ���ַ���ʱ������Ŀ¼"/dsmdata"��
����һ��Ŀ¼�����ļ���"a.bmp"��"b.mrp"��Ŀ¼"data"����
mr_c_findStart���ز��Ҿ����"a.bmp"/handle�������ŵ�mr_c_findGetNext
����"b.mrp"/MR_SUCCESS��"data"/MR_SUCCESS��XX(��Ч)/MR_FAILED��
����:
name	Ŀ¼��
len	��������С
���:
buffer  �����������ڴ�Ų��ҳɹ�ʱ��һ���ļ�����һ��
            ��Ŀ¼��
����:
      >0                  ���Ҿ������mr_c_findGetNext��mr_c_findStop����ʹ��
      MR_FAILED      ʧ��
*/
int32 mrc_findStart(const char* name, char* buffer, uint32 len);

/*
ȡ��һ��Ŀ¼�����Ľ���������������buffer�С���
Ŀ¼�еĽ�����������󣬷���MR_FAILED��
������Ҫע����ǣ�ʹ��mr_c_findGetNext��õ���Ŀ¼��
����"."��".."��
����:
   search_handle	����mr_c_findStartʱ���صĲ��Ҿ��
   len	��������С
���:
   buffer  �����������ڴ�Ų��ҳɹ�ʱ�ļ�����һ����Ŀ¼��
����:
      MR_SUCCESS  �����ɹ�
      MR_FAILED   ��������������ʧ��
*/
int32 mrc_findGetNext(int32 search_handle, char* buffer, uint32 len);

/*
Ŀ¼������������ֹһ��mr_c_findStart������Ŀ¼������
����:
search_handle        ����mr_findStartʱ���صĲ��Ҿ��
����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_findStop(int32 search_handle);


/********************************��ͼ�ӿ�********************************/


/*
��ָ���ַ�����֧��unicode����������Ļָ����������
��Ĳ��ֲ���ʾ��
����:
chr:            ����ʾ���ַ�unicodeָ��(���)
x, y:             ����ʾ���ַ����Ͻ�x, y
rect:             ��ʾ���ַ����Ʒ�Χ
colorst:          ������ɫ
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
����ֵ:
   MR_SUCCESS  �����ɹ����ַ�Ϊ\00\00ʱҲ���سɹ�����û��
                         ʵ����ʾ������
   MR_FAILED      ����ʧ�ܣ��ַ����ֿ���δ�ҵ��᷵�ظ�ֵ��
*/
int32 mrc_drawChar(uint8* chr, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, uint16 font);


/*
��ָ���ı���������Ļָ��λ�á�
����:
pcText:         ����ʾ���ַ���
x, y:             ����ʾ���ı����Ͻ�x, y
r, g, b:          ������ɫr,g,b��r,g,b��ȡֵ��Χ��0~255����ͬ��
is_unicode:    �Ƿ���unicode��TRUE(1)��ʾʹ��unicode���룬FALSE(0)��
                     ʾʹ��GB2312���롣
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
����ֵ:
   MR_SUCCESS  �����ɹ�
   MR_FAILED      ����ʧ��
*/
int32 mrc_drawText(char* pcText, int16 x, int16 y, uint8 r, uint8 g, uint8 b, int is_unicode, uint16 font);

/*
�뺯��mrc_drawText�������ƣ���ͬ������mrc_drawText��
��ʾ���ַ����������Ͻ�Ϊ��x, y�������Ϊ��w, h��
�ľ��η�Χ֮�ڡ�
��������mythroad�汾��Ӧ��ʹ�øú���ʱ��Ҫ����
����ת����ʹ�øú�����ʹĿ���������Լ16K��
1936����֮��汾��:���Զ�����ʱ������ʾ�����
����
1935�汾�޷���ʾ����ַ���
����:
pcText:         ����ʾ���ַ���
x, y:             ����ʾ���ı����Ͻ�x, y
rect:             ��ʾ���ַ����Ʒ�Χ
colorst:          ������ɫ
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
flag������ȡ���µ�ֵ��Ҳ��������Щֵ����ӣ�
          DRAW_TEXT_EX_IS_UNICODE          1 //�Ƿ�ʹ��UNICODE��, �����ֽ���
          DRAW_TEXT_EX_IS_AUTO_NEWLINE    2 //�Ƿ��Զ�����
����ֵ:
    ָʾ������Ļ�ϵ�һ��δ������ʾ�ַ���������
��������Text��unicode����ֵ����ʹ����ʹ��gb������
�������������ص�����ֵҲ�Ǹ��ݸ��ַ���ת��Ϊ
unicode���������ֵ���������ַ�����������ʾ����
���ظ��ִ�ת��Ϊunicode����ĳ��ȡ�
*/
int32 mrc_drawTextEx(char* pcText, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, int flag, uint16 font);

/*
�뺯��mrc_drawText�������ƣ���ͬ������mrc_drawTextLeft
������֧��GB�����ԱȽϽ�ʡ�ڴ档
����:
pcText:         ����ʾ���ַ���
x, y:             ����ʾ���ı����Ͻ�x, y
rect:             ��ʾ���ַ����Ʒ�Χ
colorst:          ������ɫ
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
flag������ȡ���µ�ֵ��Ҳ��������Щֵ����ӣ�
          DRAW_TEXT_EX_IS_AUTO_NEWLINE    2 //�Ƿ��Զ�����
����ֵ:
    ָʾ������Ļ�ϵ�һ��δ������ʾ�ַ�������(�ֽ�)��
��������Text��unicode����ֵ���������ַ���������
��ʾ���򷵻ظ��ִ�ת��Ϊunicode����ĳ��ȡ�
*/
int32 mrc_drawTextLeft(char* pcText, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, int flag, uint16 font);

/*
�뺯��mrc_drawTextLeft�������ƣ���ͬ������mrc_drawTextLeft
��������������ʾ�ı�����Ӧ�����ұ���ʾ���ı���
��һ���ַ������ң��ú�����֧���Զ����С�
����:
pcText:         ����ʾ���ַ���
x, y:             ����ʾ���ı����Ͻ�x, y
rect:             ��ʾ���ַ����Ʒ�Χ
colorst:          ������ɫ
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
flag��          ��Ч�������ò�����Ϊ��ͳһ
����ֵ:
    ָʾ������Ļ�ϵ�һ��δ������ʾ�ַ�������(�ֽ�)��
��������Text��unicode����ֵ���������ַ���������
��ʾ���򷵻ظ��ִ�ת��Ϊ0��
*/
int32 mrc_drawTextRight(char* pcText, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, int flag, uint16 font);

/*
��gb�ַ���ת��ΪUnicode�ַ�����������һƬ�ڴ汣
��Unicode�ַ�������Unicode�ַ�����ָ�뷵�ء�
��������mythroad�汾��Ӧ��ʹ�øú���ʱ��Ҫ����
����ת����ʹ�øú�����ʹĿ���������Լ16K��
����:
cp: �����gb�ַ���
err����NULL����errΪ��NULL������ת������ʱerr���س�
          ���ַ�������
���:
err����errΪ��NULL������ת������ʱerr���س����ַ�
             ������
size�������Unicode�ַ�������
����:
    NULL        ת������
    ����    Unicode�ַ���ָ��
*/
uint16* mrc_c2u(char *cp, int32 *err, int32 *size);

/*
��mrc_c2u����������ͬ��
��ͬ���ڸú���ʹ��VM�е������б任��
����ʹ�������15K���ң�
ʹ�øú����õ����ڴ棬��Ҫʹ��mrc_freeFileData�����ͷš�
V1939�����ʹ�ã�V1939֮ǰ�İ汾��������
*/
uint16* mrc_c2uVM(char *cp, int32 *err, int32 *size);

/*
��ȡ�ַ�������ʾ��Ⱥ͸߶ȡ�
����:
pcText:         ����ʾ���ַ���
is_unicode:    �Ƿ���unicode��TRUE(1)��ʾʹ��unicode���룬FALSE(0)��
                     ʾʹ��GB2312���롣
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
���:
w���ַ�������ʾ���
h���ַ�������ʾ�߶�
����:
    MR_SUCCESS  �����ɹ�
    MR_FAILED      ����ʧ��
*/
int32 mrc_textWidthHeight(char* pcText, int is_unicode, uint16 font, int32* w, int32* h);

/*
��mrc_textWidthHeight���ƣ���ͬ��Ϊmrc_unicodeTextWidthHeight������
Unicode�ַ�������������GBת���������ռ���
mrc_textWidthHeight��ʡ15K���ҡ�
����:
pcText:         ����ʾ���ַ���
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
���:
w���ַ�������ʾ���
h���ַ�������ʾ�߶�
����:
    MR_SUCCESS  �����ɹ�
    MR_FAILED      ����ʧ��
*/
int32 mrc_unicodeTextWidthHeight(uint16* pcText, uint16 font, int32* w, int32* h);



/*
������Unicode�ַ�������
���ش���ʾ�ַ�������ʾ�ڿ�Ϊw�������
��Ҫ��������
pcText:         ����ʾ���ַ���
font:              �����С�����ܵ�ֵ��   
                        MR_FONT_SMALL
                        MR_FONT_MEDIUM
                        MR_FONT_BIG
w                  ����ʾ���
 ����:
    MR_FAILED      ����ʧ��
    ����           �ַ�������
*/
int32 mrc_unicodeTextRow(uint16* pcText, uint16 font, int32 w);


/*
��ȡ��Ļ���ߡ�������ȵ���Ϣ��
mr_screeninfo��ʽ���£�
typedef struct
{
   uint32 width;                  //��Ļ��
   uint32 height;                 //��Ļ��
   uint32 bit;                    //��Ļ������ȣ���λbit��
                                      �磺6��5ǧɫ��16bitɫ�Ӧ�÷���16��
}mr_screeninfo;

���:
screeninfo	��Ļ��Ϣ

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_getScreenInfo(mr_screeninfo * screeninfo);


/*
���ƾ�����ָ������
����:
x,y,w,h:	λ��
r,g,b	     ������ɫ
*/
void mrc_drawRect(int16 x, int16 y, int16 w, int16 h, uint8 r, uint8 g, uint8 b);

/*
�����߶Ρ�
����:
x1,y1,x2,y2:	��ĩ��λ��
r,g,b	          ������ɫ
*/
void mrc_drawLine(int16 x1, int16 y1, int16 x2, int16 y2, uint8 r, uint8 g, uint8 b);

/*
����Ļ��ָ��λ�û��Ƶ㡣
����:
x, y	           ���Ƶ��λ��
nativecolor	�����ɫ����R:G:B = 5:6:5��
*/
void mrc_drawPoint(int16 x, int16 y, uint16 nativecolor);

/*
����Ļ��ָ��λ�û��Ƶ㡣
����:
x, y	           ���Ƶ��λ��
r,g,b	          ������ɫ
*/
void mrc_drawPointEx(int16 x, int16 y, int32 r, int32 g, int32 b);

/*
ʹ��ָ������ɫ�����Ļ��
����:
r,g,b	          ������ɫ
*/
void mrc_clearScreen(int32 r, int32 g, int32 b);

/*
ˢ����Ļָ�������򡣸ú����Ĺ����ǽ�mythroad��Ļ
����ָ��������ˢ�µ���Ļ�ϡ�
����:
x, y, w, h	       ��Ļָ�����������Ͻ�Ϊ��x,y�������
                        Ϊ��w,h����
*/
void mrc_refreshScreen(int16 x, int16 y, uint16 w, uint16 h);

/*
����Ļ�����Ͻ�x,y�����Ϊw,h�ľ��������ڵ�r,g,b�ֱ�
��ǿperr/256, perg/256, perb/256����
��perr=256, perg=0, perb=0����ֻ�������������ڵĺ�ɫ����
perr=perg= perb=128����ʹ���������ڲ���һ�ְ�͸����Ч
����
����:
x,y,w,h	��Ļλ�á�
perr, perg, perb	r,g,b�仯����ֵ��
*/
void mrc_EffSetCon(int16 x, int16 y, int16 w, int16 h, int16 perr, int16 perg, int16 perb);

/*
��mrp����Ϊfilename��ͼƬ����(x, y)��ʼ�Ŀ��Ϊw, h������
���ص����Ϊi��bmp�����С�max_wΪ��Ϊfilename��ͼƬ��ͼ
Ƭ��ȡ�

mythroad�й���30��ͼƬ����(���0~29)�����Խ�mrp�е�bmpͼƬ
���ص������У�����̵Ļ�ͼ�Ȳ���

������(x==0)&&(y==0)&&(w==max_w)����ʱ��mrc_bitmapLoad����������
ͼƬ,������һ���֡�

����:
i                  ͼƬ�������
filename      �ļ��������ļ���Ϊ"*"ʱ���ͷŸû���
x,y              ԴͼƬ����ʼλ��
w,h             ������ͼƬ�Ŀ��
max_w        ������ͼƬ��ԭʼ���

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bitmapLoad(uint16 i, char* filename, int16 x, int16 y, uint16 w, uint16 h, uint16 max_w);

/*
	�����Ϊi��bmp�����е�ͼƬ���ӻ����е�ͼƬ��(sx, sy)
	��ʼ�Ŀ��Ϊw, h�����򣬻��Ƶ�(x, y)��ʼ����Ļ�����С�

����:
i                  ͼƬ�������
x,y              ��Ļλ��
rop              ѡ�����£�
   BM_OR,         //SRC .OR. DST*   ��͸��Ч��
   BM_XOR,        //SRC .XOR. DST*
   BM_COPY,       //DST = SRC*      ����
   BM_NOT,        //DST = (!SRC)*
   BM_MERGENOT,   //DST .OR. (!SRC)
   BM_ANDNOT,     //DST .AND. (!SRC)
   BM_TRANSPARENT,//͸��ɫ����ʾ��ͼƬ�ĵ�һ�����أ����Ͻ�
                                 �����أ���͸��ɫ
   BM_AND,        //DST AND SRC
   BM_GRAY,        //�ҶȻ�ͼ�� �൱��BM_TRANSPARENT���ҶȻ�ͼ��
                              DST�Ҷ� �� 30%R + 59%G + 11%BͼƬ���
   BM_REVERSE     //�����ͼ���൱��BM_TRANSPARENT�������ͼ��V1939��

sx,sy              ԴͼƬ����ʼλ��
w,h             ������ͼƬ�Ŀ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bitmapShow(uint16 i, int16 x, int16 y, uint16 rop, int16 sx, int16 sy, int16 w, int16 h);

/*
����ͬmrc_bitmapShow��Ψһ��ͬ����:ԴͼƬ����λ��ͼƬ
�������ڣ������ɲ���������

����:
p        ԴͼƬָ��
mw     ԴͼƬ��ԭʼ���
sx,sy  ��ԴͼƬ��(sx,sy)���꿪ʼ
����ͬmrc_bitmapShow

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int mrc_bitmapShowEx(uint16* p,
   int16 x,
   int16 y,
   int16 mw,
   int16 w,
   int16 h,
   uint16 rop,
   int16 sx,
   int16 sy
);


int mrc_bitmapShowExTrans(uint16* p,
   int16 x,
   int16 y,
   int16 mw,
   int16 w,
   int16 h,
   uint16 rop,
   int16 sx,
   int16 sy,
   uint16 transcolor
);

/*
�˽�һ�����Ϊi��bmp���壬����ͼƬ�Ŀ��Ϊw, h��

����:
i                  ͼƬ�������
w,h             ͼƬ�Ŀ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int mrc_bitmapNew(
   uint16 i,
   uint16 w,
   uint16 h
);

/*
����ǿ�ķ�ʽ��bmpͼƬ������ָ��ͼƬ�С�
�����si ��bmp�����е�ͼƬ���ӻ����е�ͼƬ��(sx, sy)��
ʼ�Ŀ��Ϊw, h�����򣬻��Ƶ����di �Ĵ�(dx,dy)��ʼ��bmp
�����С�

ģʽropѡ�����£�
   BM_COPY,               //DST = SRC*      ����
   BM_TRANSPARENT,  //͸��ɫ����ʾ��ͼƬ�ĵ�һ�����أ�����
                                  �ǵ����أ���͸��ɫ
                                  
A��B��C��D����ͼ��仯�����ڸñ仯�ı任����Ϊ��
x = A0*x0 + B0*y0
y = C0*x0 + D0*y0
����Ϊ�˱�ʾС����A, B, C, D����������256������
A = A0*256
B = B0*256
C = C0*256
D = D0*256
���ݱ任��ʽ�����Ի����ͬЧ����ͼ�񣬱��磺
��תͼ��
A = 256 * cos���Ƕȣ�
B = 256 * sin���Ƕȣ�
C = 256 * -sin���Ƕȣ�
D = 256 * cos���Ƕȣ�
�Ŵ���Сͼ��
A = 256 * �Ŵ���
B = 0
C = 0
D = 256 * �Ŵ���

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int mrc_bitmapDraw(
   uint16 di,
   int16 dx,
   int16 dy,
   uint16 si,
   int16 sx,
   int16 sy,
   uint16 w,
   uint16 h,
   int16 A,
   int16 B,
   int16 C,
   int16 D,
   uint16 rop
);

/*
����Ļ�����������Ϊi��bmp�����С�

����:
i                  ͼƬ�������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int mrc_bitmapGetScreen(
   uint16 i
);

/*
������:
��������Ϸ�˶������壬֧����ײ��⣬ͬʱ���Լ���
10�����У�����������������ͼƬ���Ͻǵ�����
��͸��ɫ��
*/

/*
���þ���߶�

����:
i                  ͼƬ�������
h                 ����߶�

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_spriteSet(
   uint16 i,
   uint16 h);

/*
���ƾ���

����:
i                  ͼƬ�������
spriteindex   ������
x,y              ��Ļλ��
mod              ѡ�����£�
   BM_OR,         //SRC .OR. DST*   ��͸��Ч��
   BM_XOR,        //SRC .XOR. DST*
   BM_COPY,       //DST = SRC*      ����
   BM_NOT,        //DST = (!SRC)*
   BM_MERGENOT,   //DST .OR. (!SRC)
   BM_ANDNOT,     //DST .AND. (!SRC)
   BM_TRANSPARENT,//͸��ɫ����ʾ��ͼƬ�ĵ�һ�����أ����Ͻ�
                                 �����أ���͸��ɫ
   BM_AND,        //DST AND SRC
   BM_GRAY,        //�ҶȻ�ͼ�� �൱��BM_TRANSPARENT���ҶȻ�ͼ��
                              DST�Ҷ� �� 30%R + 59%G + 11%BͼƬ���
   BM_REVERSE     //�����ͼ���൱��BM_TRANSPARENT�������ͼ��V1939��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_spriteDraw(
   uint16 i,
   uint16 spriteindex,
   int16 x,
   int16 y,
   uint16 mod
);

/*
���ƾ���(��ǿ)

����:
i                  ͼƬ�������
spriteindex   ������
x,y              ��Ļλ��
A,B,C,D       �μ�mrc_bitmapDraw˵��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_spriteDrawEx(
   uint16 i,
   uint16 spriteindex,
   int16 x,
   int16 y,
   int16 A,
   int16 B,
   int16 C,
   int16 D
);

/*
 �ж���ײ�Ļ����麯��������ֵ�ǻ�����ʱ��������λ��
 ��r,g,b�����ص���Ŀ��

����:
i                  ͼƬ�������
spriteindex   ������
x,y              ��Ļλ��
r,g,b           �����ɫ

����:
      >=0                   ��r,g,b�����ص���Ŀ
      MR_FAILED         ʧ��
*/
int32 mrc_spriteCheck(uint16 i, uint16 spriteindex, int16 x, int16 y,uint8 r, uint8 g, uint8 b);


/*
��ש���:
��ש�������͹ؿ���ƵĻ�ʯ��ͼƬ�����mrc_bitmapLoad�е�
ͼƬ��Ŷ�Ӧ��ͬʱ������3����ש��ͼƬ���0��2��
*/
/*
���õ�ש

����:
i                  ͼƬ������ţ���ש�ţ�
x,y              ��Ļλ��
w,h              ��ש����, ��ש����
tileh             ��שͼƬ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileInit(
   uint16 i,
   int16 x,
   int16 y,
   uint16 w,
   uint16 h,
   uint16 tileh
   );

/*
���õ�שi�Ŀ��ӷ�Χ��

����:
i                  ͼƬ������ţ���ש�ţ�
x1,y1,x2,y2  ���ӷ�Χ�����Ϻ����½�(����)
����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileSetRect(
   uint16 i,
   int16 x1,
   int16 y1,
   int16 x2,
   int16 y2
);

/*
����ש

����:
i                  ͼƬ������ţ���ש�ţ�

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileDraw(
   uint16 i
);

/*
��שi��

����:
i                  ͼƬ������ţ���ש�ţ�
mode:   0 up , 1 down, 2 left, 3 right

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileShift(
   uint16 i,
   uint16 mode
);

/*
���ļ�filename�ж�ȡ��ͼ����שi

����:
i                  ͼƬ������ţ���ש�ţ�
filename      ��ͼ�ļ���

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileLoad(
   uint16 i,
   char* filename
);

int32 mrc_tileLoadEx(
   uint16 i,
   uint8* buf,
   int32 len
);

/*
��ȡ��שֵ

����:
i                  ͼƬ������ţ���ש�ţ�
x,y              ��ש��, ��ש��

����:
      >=0                   ��שֵ
      MR_FAILED         ʧ��
*/
int32 mrc_tileGetTile(
   uint16 i,
   uint16 x,
   uint16 y
);

/*
���õ�שֵ

����:
i                  ͼƬ������ţ���ש�ţ�
x,y              ��ש��, ��ש��
v                 ��שֵ

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_tileSetTile(
   uint16 i,
   uint16 x,
   uint16 y,
   uint16 v
);





/********************************���ػ�UI�ӿ�********************************/

/*
����һ���˵��������ز˵������title�ǲ˵��ı��⡣

����:
title	�˵��ı��⣬unicode���룬�����ֽ���
num	�˵������Ŀ

����:
      ������   �˵����
      MR_FAILED   ʧ��
*/
int32 mrc_menuCreate(const char* title, int16 num);

/*
	�ڲ˵�������һ���˵������index�Ǹò˵����
	��ţ����û�ѡ��ĳ���˵���ʱ����index��ͨ��
	mrc_event�������͵�Ӧ���С�

����:
menu  �˵��ľ��
text �˵�������֣�ʹ��unicode���룬�����ֽ���
index    �˵����index��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_menuSetItem(int32 menu, const char *text, int32 index);

/*
��ʾ�˵������˵���ʾʱ������û�ѡ���˲˵���
��ĳһ�ϵͳ������MythroadӦ����Ϣ��ͨ��
mrc_event�������͸�MythroadӦ�ã���Ϣ����Ϊ
MR_MENU_SELECT������Ϊ�ò˵����index������û�ѡ��
���˳��ò˵���ϵͳ������MythroadӦ����Ϣ��ͨ��
mrc_event�������͸�MythroadӦ�ã���Ϣ����Ϊ
MR_MENU_RETURN��

����:
menu �˵��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_menuShow(int32 menu);

/*
�ͷŲ˵���

����:
menu �˵��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_menuRelease(int32 menu);

/*
ˢ�²˵���ʾ��

����:
menu �˵��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_menuRefresh(int32 menu);

/*
����һ���Ի��򣬲����ضԻ����������Ի�����
ʾʱ������û����˶Ի����ϵ�ĳ������ϵͳ����
��MythroadӦ����Ϣ��ͨ��mrc_event�������͸�MythroadӦ
�ã���Ϣ����ΪMR_DIALOG_EVENT������Ϊ�ð�����ID��
"ȷ��"��IDΪ��MR_DIALOG_KEY_OK��"ȡ��"��IDΪ��
MR_DIALOG_KEY_CANCEL��

����:
title	�Ի���ı��⣬unicode���룬�����ֽ���
text	�Ի������ݣ�unicode���룬�����ֽ���
type	�Ի������ͣ�
      MR_DIALOG_OK���Ի�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���Ի�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���Ի����� "����"����

����:
      ������   �Ի�����
      MR_FAILED   ʧ��
*/
int32 mrc_dialogCreate(const char * title, const char * text, int32 type);

/*
�ͷŶԻ���

����:
dialog  �Ի���ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_dialogRelease(int32 dialog);

/*
ˢ�¶Ի������ʾ��


����:
dialog	�Ի���ľ��
title	�Ի���ı��⣬unicode���룬�����ֽ���
text	�Ի������ݣ�unicode���룬�����ֽ���
type	��typeΪ-1����ʾtype���䡣
�Ի������ͣ�
      MR_DIALOG_OK���Ի�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���Ի�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���Ի����� "����"����

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_dialogRefresh(int32 dialog, const char * title, const char * text, int32 type);

/*
����һ���ı��򣬲������ı��������ı�������
��ʾֻ����������Ϣ���ı���ͶԻ���û�б���
�����𣬽�������ʾ��ʽ�ϵĲ�ͬ����ʹ��������
����Ҫ�����ǣ��Ի��������һ��϶̣��ı����
����һ��ϳ����Ի���һ��ʵ��Ϊ����ʽ�Ĵ��ڣ�
�ı���һ��ʵ��Ϊȫ��ʽ�Ĵ��ڡ�Ҳ�������ֻ���
�Ի�����ı���ʹ������ͬ�ķ�ʽʵ�֡�
�ı���ͶԻ������Ϣ������һ���ġ����ı�����
ʾʱ������û�ѡ�����ı����ϵ�ĳ������ϵͳ��
����MythroadӦ����Ϣ��ͨ��mrc_event�������͸�Mythroad
ƽ̨����Ϣ����ΪMR_DIALOG_EVENT������Ϊ�ð�����ID��
"ȷ��"��IDΪ��MR_DIALOG_KEY_OK��"ȡ��"��IDΪ��
MR_DIALOG_KEY_CANCEL��

����:
title	�ı���ı��⣬unicode���룬�����ֽ���
text	�ı������ݣ�unicode���룬�����ֽ���
type	�ı������ͣ�
      MR_DIALOG_OK���ı�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���ı�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���ı����� "ȡ��/����"����

����:
      ������   �ı�����
      MR_FAILED   ʧ��
*/
int32 mrc_textCreate(const char * title, const char * text, int32 type);

/*
�ͷ��ı���

����:
text �ı���ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_textRelease(int32 text);

/*
ˢ���ı�����ʾ��

����:
handle	�ı���ľ��
title	�ı���ı��⣬unicode���룬�����ֽ���
text	�ı������ݣ�unicode���룬�����ֽ���

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_textRefresh(int32 handle, const char * title, const char * text);

/*
����һ���༭�򣬲����ر༭�������༭������
��ʾ���ṩ�û��༭������Ϣ��text�Ǳ༭����ʾ��
��ʼ���ݡ�
���༭����ʾʱ������û�ѡ���˱༭���ϵ�ĳ��
����ϵͳ������MythroadӦ����Ϣ��ͨ��mrc_event����
���͸�MythroadӦ�ã���Ϣ����ΪMR_DIALOG_EVENT������
Ϊ�ð�����ID��"ȷ��"��IDΪ��MR_DIALOG_KEY_OK��"ȡ��
"��IDΪ��MR_DIALOG_KEY_CANCEL��

����:
title	�༭��ı��⣬unicode���룬�����ֽ���
text	�༭��ĳ�ʼ���ݣ�unicode���룬�����ֽ���
type	���뷨���ͣ�
      MR_EDIT_ANY��     �κ��ַ�
      MR_EDIT_NUMERIC�� ����
      MR_EDIT_PASSWORD�� ���룬��"*"��ʾ
max_size	������������ַ���unicode������������ÿһ
                �����ġ���ĸ�����֡����Ŷ���һ���ַ���
����:
      ������   �༭����
      MR_FAILED   ʧ��
*/
int32 mrc_editCreate(const char * title, const char * text, int32 type, int32 max_size);

/*
�ͷű༭��

����:
edit �༭��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_editRelease(int32 edit);

/*
��ȡ�༭�����ݣ�unicode���롣�����������ڱ༭��
�ͷź���Ȼʹ�ñ༭������ݣ���Ҫ���б������
�ݡ��ú�����Ҫ�ڱ༭���ͷ�֮ǰ���á�

����:
edit �༭��ľ��

����:
      ��NULL       �༭�������ָ�룬unicode���롣
      NULL            ʧ��
*/
const char* mrc_editGetText(int32 edit);

/*
����һ������չ���壬�����ؿ���չ��������
����չ���崴��֮���û��İ����ʹ������¼�
�ᱻ�����MythroadӦ����Ϣ��ͨ��mrc_event��������
��MythroadӦ�ã������¼�����Ϣ����ΪMR_KEY_PRESS��
MR_KEY_RELEASE���������¼�����Ϣ����Ϊ
MR_MOUSE_DOWN��MR_MOUSE_UP��
��Ϊ�ڶԻ��򡢲˵��ȴ���״̬�£�Ӧ�ý��ܽ�
�յ��˵����Ի�����¼�������Ҫ����һ����Ӧ
�����л��Ʋ��������¼��Ĵ���ʱ������Ҫ��
������չ���塣

����:
      ������   ����չ������
      MR_FAILED   ʧ��
*/
int32 mrc_winCreate(void);

/*
�ͷſ���չ���塣

����:
win  �Ի���ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_winRelease(int32 win);




/********************************����ӿ�********************************/

/*
ȡ������ID��

����:
      MR_NET_ID_MOBILE  �ƶ�GSM
      MR_NET_ID_CN   ��ͨGSM
      MR_NET_ID_CDMA ��ͨCDMA
      MR_NET_ID_NONE δ�忨���������
*/
int32 mrc_getNetworkID(void);

/*
�����ʼ���ص�����
����:
result:
   MR_SUCCESS  ��ʼ���ɹ�
   MR_FAILED      ��ʼ��ʧ��
����ֵ:
   MR_SUCCESS  �����ɹ�
   MR_FAILED      ����ʧ��
�����ķ���ֵ����Ϊ���������汾������Ŀǰmythroad
�����ĺ����ķ���ֵ��
*/
typedef int32 (*MR_INIT_NETWORK_CB)(int32 result);

/*
�����ʼ�������û�в��ţ����в��Ų�����
������Ҫע����ǣ����ĵ���������������ӿں�
����ʵ��ʱ�������ȿ��ǲ��÷�������ʽ��
�������ʼ��ʹ���첽ģʽ��ʹ�ûص�����֪ͨ��
���ʼ�������

����:
cb	�������ʼ��ʹ���첽ģʽʱ��ʹ�øûص�����
֪ͨӦ�ó�ʼ�����
mode	���ŷ�ʽ��"CMNET"��" CMWAP"�Ĳ��ŷ�ʽ��

����:
      MR_SUCCESS  ͬ��ģʽ����ʼ���ɹ������ٵ���cb
      MR_FAILED   ��������֪�ģ�ʧ�ܣ����ٵ���cb
      MR_WAITING  ʹ�ûص�����֪ͨ�����ʼ�����
*/
int32 mrc_initNetwork(MR_INIT_NETWORK_CB cb, const char *mode);

/*
�Ͽ��������ӡ�

����:

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_closeNetwork(void);

/*
��ȡ����IP�ص�����
����:
ip: 
   MR_FAILED       ��ȡIPʧ��
   ����ֵ      IP��ַ
����ֵ:
   MR_SUCCESS  �����ɹ�
   MR_FAILED      ����ʧ��
�����ķ���ֵ����Ϊ���������汾������Ŀǰmythroad
�����ĺ����ķ���ֵ��
*/
typedef int32 (*MR_GET_HOST_CB)(int32 ip);

/*
	ͨ����������ø�������IP��ֵַ�����һ������
	��IP��ַΪ218.18.95.203����ֵΪ218<<24 + 18<<16 + 95<<8 + 203
	= 0xda125fcb��
      ����ȡ����IPʹ���첽ģʽ��ʹ�ûص�����֪ͨ��
      ���ȡIP�Ľ����

����:
name  ������
cb      �ص�����


����:
      MR_FAILED   ��������֪�ģ�ʧ�ܣ����ٵ���cb
      MR_WAITING  ʹ�ûص�����֪ͨ�����ȡIP�Ľ��
      ����ֵ   ͬ��ģʽ���������ص�IP��ַ�����ٵ���cb
*/
int32 mrc_getHostByName(const char *name, MR_GET_HOST_CB cb);

/*
	����һ��socket��

����:
 type	 Socket���ͣ�
      MR_SOCK_STREAM
      MR_SOCK_DGRAM
 protocol	����Э������:
      MR_IPPROTO_TCP��
      MR_IPPROTO_UDP

����:
      >=0              ���ص�Socket���
      MR_FAILED    ʧ��
*/
int32 mrc_socket(int32 type, int32 protocol);

/*
	����TCP���ӡ�

����:
 s       �򿪵�socket�����
 ip      IP��ַ
 port    �˿ں�
 type:
            MR_SOCKET_BLOCK          //������ʽ��ͬ����ʽ��
            MR_SOCKET_NONBLOCK       //��������ʽ���첽��ʽ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED      ʧ��
      MR_WAITING   ʹ���첽��ʽ�������ӣ�Ӧ����Ҫ��ѯ
                            ��socket��״̬�Ի�֪����״��
*/
int32 mrc_connect(int32 s, int32 ip, uint16 port, int32 type);


/*
��ȡsocket connect ״̬����Ҫ����TCP���첽���ӣ�
���أ�

����:
Socket���

����:
      MR_SUCCESS ��  ���ӳɹ�
      MR_FAILED  ������ʧ��
      MR_WAITING ��������
      MR_IGNORE  ����֧�ָù���
*/
int32 mrc_getSocketState(int32 s);

/*
 	�ر�һ��socket���ӡ�

����:
s  �򿪵�socket���

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_closeSocket(int32 s);

/*
 	������������ݡ�

����:
s  �򿪵�socket�����
len   ��������С��

���:
buf   ����������Ž��յ������ݡ�

����:
      >=0������   ʵ�ʽ��յ������ֽڸ���
      MR_FAILED          Socket�Ѿ����رջ��������޷��޸��Ĵ���
*/
int32 mrc_recv(int32 s, char *buf, int len);

/*
 	��ָ����ַ�������ݡ�

����:
s  �򿪵�socket�����
len   ��������С��
ip   �Զ�IP��ַ
port �Զ˶˿ں�

���:
buf   ����������Ž��յ������ݡ�


����:
      >=0������   ʵ�ʽ��յ������ֽڸ���
      MR_FAILED   Socket�Ѿ����رջ��������޷��޸��Ĵ���
*/
int32 mrc_recvfrom(int32 s, char *buf, int len, int32 *ip, uint16 *port);

/*
 	�������ݡ�

����:
s  �򿪵�socket���
len   ��������С

���:
buf   Ҫ�������ݵĻ�����

����:
      >=0             ʵ�ʷ��͵������ֽڸ���
      MR_FAILED   Socket�Ѿ����رջ��������޷��޸��Ĵ���
*/
int32 mrc_send(int32 s, const char *buf, int len);

/*
 	��ָ����ַ�������ݡ�

����:
s  �򿪵�socket���
len   ��������С
ip   �Զ�IP��ַ
port �Զ˶˿ں�

���:
buf   Ҫ�������ݵĻ�����

����:
      >=0               ʵ�ʷ��͵������ֽڸ���
      MR_FAILED     Socket�Ѿ����رջ��������޷��޸��Ĵ���
*/
int32 mrc_sendto(int32 s, const char *buf, int len, int32 ip, uint16 port);



/********************************�����ӿ�********************************/

/*
Mythroad�����ͬʱ֧�� 5���������壬 index = 0~4����Ҫע
�������ȻMythroad�����ͬʱ֧��5��Sound�ļ����� 
Mythroad ��������ļ�������ͬʱ���ţ����ҽ������ŵ�
�������Ͳ�ͬ��������ƽ̨֧��ͬʱ�������Ͳ�ͬ��
����ʱ������ͬʱ���Ų�ͬ�������� 
*/
/*
������������

����:
i                 �����������
filename     �����ļ���
type��ȡֵ���£� 
        MR_SOUND_MIDI       0 
        MR_SOUND_WAV       1 
        MR_SOUND_MP3       2 
����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_soundSet(uint16 i, char * filename, int32 type);

/*
������������

����:
i                 �����������
loop            0:���β���, 1:ѭ������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_soundPlay(
   uint16 i,
   int32 loop
);

/*
ֹͣ������������

����:
i                 �����������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_soundStop(
   uint16 i
);

/*
������������

����:
type       ������������:
        MR_SOUND_MIDI       0 
        MR_SOUND_WAV       1 
        MR_SOUND_MP3       2 
data        ��������ָ��
dataLen   �������ݳ���
loop            0:���β���, 1:ѭ������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mr_playSoundEx(int type, const void* data, uint32 dataLen, int32 loop);


/*
ֹͣ������������

����:
type       ������������:
        MR_SOUND_MIDI       0 
        MR_SOUND_WAV       1 
        MR_SOUND_MP3       2 

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mr_stopSoundEx(int type);


/********************************��ʱ���ӿ�********************************/

/*
������ʱ��

����:
      ��NULL     ��ʱ�����
      NULL          ʧ��
*/
int32 mrc_timerCreate (void);

/*
ɾ����ʱ��

����:
t           ��ʱ�����
*/
void mrc_timerDelete (int32 t);

/*
ֹͣ��ʱ��

����:
t           ��ʱ�����
*/
void mrc_timerStop (int32 t);

/*
��ʱ���ص�����
����:
data:
   ������ʱ��ʱ�����data������
*/
typedef void (*mrc_timerCB)(int32 data);

/*
������ʱ��

����:
t           ��ʱ�����
time      ��ʱ��ʱ������λ����
data      ��ʱ������
f           ��ʱ���ص�����
loop      �Ƿ�ѭ����0:��ѭ����1:ѭ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_timerStart (int32 t, int32 time, int32 data, mrc_timerCB f, int32 loop);


/*
���Ķ�ʱ��ʱ����

����:
t           ��ʱ�����
time      ��ʱ��ʱ������λ����

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_timerSetTimeEx (int32 t, int32 time);



/********************************�����ӿ�********************************/
/*
�˳�Ӧ�ã�Ӧ�õ��øú���֪ͨmythroad��Ӧ�ý�Ҫ��
����
*/
void mrc_exit(void);

/*
��ȡϵͳʱ�䣬��λ���롣ϵͳʱ�������Mythroadƽ
̨��������֮ǰ������ʱ��Ϊ��ʼʱ�䣬���ش���
ʼʱ�䵽Ŀǰ�����ĺ���������������������ܷ�
�ص���ϵͳ�����󾭹��ĺ�������
����:
     ��λ�����ϵͳʱ��
*/
int32 mrc_getUptime(void);


/*
��ȡϵͳ����ʱ�䡣
mr_datetime��ʽ���£�
typedef struct
{
   uint16 year;                 //��
   uint8  month;                //��
   uint8  day;                  //��
   uint8  hour;                 //ʱ��24Сʱ��
   uint8  minute;               //��
   uint8  second;               //��
}mr_datetime;

���:
datetime	����ʱ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_getDatetime(mr_datetime* datetime);

/*
��ȡϵͳ��ʣ����ڴ���

����:
      ϵͳ��ʣ����ڴ�������λ�ֽ�
*/
uint32 mrc_getMemoryRemain(void);

/*
�����ֻ��𶯡�

����:
ms             �𶯳�����ʱ�䣬��λ����

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_startShake(int32 ms);

/*
ȡ��mythroadƽ̨�汾��

����:
      mythroadƽ̨�汾��
*/
int32 mrc_getVersion(void);

/*
��ȡ��ǰ�������е�mrp���ļ�����
mythroad��֧�ֵ�����ļ�����Ϊ127�ֽ�

����:
      ��ǰ�������е�mrp���ļ�����
*/
char* mrc_getPackName(void);

/*
��name����Ϊ��ǰmrp
mythroad��֧�ֵ�����ļ�����Ϊ127�ֽ�

����:
name         mrp�ļ���

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_setPackName(char * name);

/*
ȡ��ϵͳ���ܹ��ڴ��С
*/
int32 mrc_getSysMem(void);

/*******************************��ں���**********************************/
/*
Ӧ�ó�ʼ������
�ú�����Ӧ�ó�ʼ���ڼ䱻mythroadƽ̨���ã����������
�����н���ȫ�ֱ����ĳ�ʼ���ȹ�����
����ֵ:
MR_SUCCESS  Ӧ�ó�ʼ���ɹ�
MR_FAILED      Ӧ�ó�ʼ��ʧ��
*/
extern int32 mrc_init(void);

/*
Ӧ���¼�����
�ú�����Ӧ�������ڼ䣬ÿ��mythroadƽ̨�յ��¼�ʱ
������
����:
code:
      code�Ŀ���ȡֵ����:
enum {
   MR_KEY_PRESS,           //���������¼�
   MR_KEY_RELEASE,        //�����ͷ��¼�
   MR_MOUSE_DOWN,       //����������꣩�����¼�
   MR_MOUSE_UP,            //����������̧꣩��/�ͷ��¼�
   MR_MENU_SELECT,       //�˵�ѡ���¼�
   MR_MENU_RETURN,       //�˵������¼�
   MR_DIALOG_EVENT,      // �Ի���/�༭��/�ı����¼�
   MR_EVENT01,                //VM�������벻Ҫʹ��
   MR_EXIT_EVENT,           //Ӧ���˳��¼�
   MR_EVENT02,                 //VM�������벻Ҫʹ��
   MR_LOCALUI_EVENT         //���ػ��ӿ��¼�
};
code��
��ֲ��codeȡֵ��ΧΪ��0��999���Ѿ�ʹ�õĳ��⣩������
������VM��Ӧ�á�
��    0��999�� ��ֲ��ʹ�ã�VM�Ѿ�ʹ�õĳ��⣩��
    1000��1999��VMʹ�ã�
    10000~99999:Ӧ��ʹ�ã�
�������������2007-11-20��ӹ淶��

param0:
   ��codeΪMR_KEY_PRESS��MR_KEY_RELEASEʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_KEY_0,               //���� 0
   MR_KEY_1,               //���� 1
   MR_KEY_2,               //���� 2
   MR_KEY_3,               //���� 3
   MR_KEY_4,               //���� 4
   MR_KEY_5,               //���� 5
   MR_KEY_6,               //���� 6
   MR_KEY_7,               //���� 7
   MR_KEY_8,               //���� 8
   MR_KEY_9,               //���� 9
   MR_KEY_STAR,            //���� *
   MR_KEY_POUND,           //���� #
   MR_KEY_UP,              //���� ��
   MR_KEY_DOWN,            //���� ��
   MR_KEY_LEFT,            //���� ��
   MR_KEY_RIGHT,           //���� ��
   MR_KEY_POWER,           //���� �һ���
   MR_KEY_SOFTLEFT,        //���� �����
   MR_KEY_SOFTRIGHT,       //���� �����
   MR_KEY_SEND,            //���� ������
   MR_KEY_SELECT,          //���� ȷ��/ѡ����������м���ȷ�ϼ���������Ϊ�ü���
   MR_KEY_VOLUME_UP,          //���� �����
   MR_KEY_VOLUME_DOWN,          //���� �����
   MR_KEY_NONE             //���� ����
};
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param0Ϊ��Ļ��x���ꣻ
��codeΪMR_MENU_SELECTʱ��param0Ϊ�˵�index��
��codeΪMR_DIALOG_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_DIALOG_KEY_OK,         //�Ի���/�ı���ȵ�"ȷ��"�������(ѡ��)
   MR_DIALOG_KEY_CANCEL  //�Ի���/�ı���ȵ�"ȡ��"("����")�������(ѡ��)
};
��codeΪMR_LOCALUI_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_LOCALUI_KEY_OK,       //���ؿؼ���"ȷ��"�������(ѡ��)
   MR_LOCALUI_KEY_CANCEL//���ؿؼ���"ȡ��"("����")�������(ѡ��)
};

param1:
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param1Ϊ��Ļ��y���ꣻ

����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
extern int32 mrc_event(int32 code, int32 param0, int32 param1);

/*
Ӧ����ͣ����
�ú�����Ӧ�ñ���ͣʱ���е绰���¼���ͣӦ�ã�
��mythroadƽ̨���á�

ע:��MTK��һЩ��ֲ�汾�У�suspend (pause)�� resume �в���
��������UI���ڡ�

����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
extern int32 mrc_pause(void);

/*
�ú�����Ӧ�ûָ�����ʱ��mythroadƽ̨���á�

ע:��MTK��һЩ��ֲ�汾�У�suspend (pause)�� resume �в���
��������UI���ڡ�

����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
extern int32 mrc_resume(void);

/*
�ú�����Ӧ���˳�ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
extern int32 mrc_exitApp(void);  



/*
�ú������յ������¼�ʱ(���������sms_indication==1ʱ��Ч)
������
����:
code:
      code��ֵΪMR_SMS_INDICATION == 7

param0:
      ��Ϣ����ָ��
      
param1:
      Ϊ����ָ��
      
param2:
      Ϊ��Ϣ��ʽ��
   MR_ENCODE_ASCII,
   MR_ENCODE_UNICODE
   
param3:
      ��Ϣ���ݳ���

      
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
extern int32 mrc_eventEx(int32 code, int32 param0, int32 param1, int32 param2, int32 param3);



/*
��ָ����mrp�ļ��ж�ȡָ�����ļ����ú�����mrc_readFileFromMrp
�������������������ͬ�⣬��������һ����ͬ:
mrc_readFileFromMrp����������ȡ��mrp�е��ļ��������ļ��Լ���ȡ
����������飻mrc_readFileFromMrpEx�Զ�ȡ������ǿ��飬���ļ�
��ѹ����ʽ��ţ�������ļ��������ݵ�ǿ��顣�ú����ʺ�
ʹ���ڼ��ش������Ҫ�ϸ���ȷ�Ա�֤�Ļ�����
����:
packname     mrp�ļ���
filename        ����ȡ�ļ����ļ���
*filebuf          ��ȡ�ļ����������
                    ���ļ���ѹ����ʽ���ʱ����:
                    *filebuf==NULL����������һƬ�ռ��ŷ��ص��ļ�
                    *filebuf!=NULL����ʱ����ʹ��*filebufָ��Ŀռ���
                           ���ص��ļ�����
*filelen          ��*filebuf!=NULL���ļ���ѹ����ʽ���ʱ��ָ��
                    *filebufָ��Ŀռ��С�����ÿռ��С������
                    ��Ž�ѹ�Ժ���ļ�����������ʧ��
lookfor          ָ�������Ĳ�����ʽ:
                    0:    ��ȡmrp���ļ������ݣ���ͨ��*filebuf��*filelen
                               ���ظ����ݣ���*filebuf==NULLʱ�����ص��ڴ�
                               ��Ҫ�������ͷţ�
                    1:    ��������mrp���Ƿ���ڸ��ļ���������ȡ
                               �ļ�����
                    2:    ��mrp�ļ�λ��ROM��RAM��ʱ����ȡ����ȡ��
                                ����ԭʼ���ݣ���ʹ�ļ�������ѹ��Ҳ
                                �����н�ѹ�����ص��ڴ治��Ҫ�ͷţ�
                                ��mrp�ļ�λ���ļ�ϵͳ��ʱ����ͬ��
                                lookfor==0
                    3:    ��ǿ���ķ�ʽ��ȡmrp���ļ������ݣ�����
                               lookfor==0�ķ�ʽ��ȡ�ļ�ʱ���ļ��Ƿ�ѹ��
                               ���ж�������Ӧ�ģ����Բ�����ȫ��֤�ļ�
                               ����ȷ�ԣ�lookfor==3ʱ��ǿ��Լ���ļ�������
                               ѹ����������ǿ��顣��*filebuf==NULLʱ������
                               ���ڴ���Ҫ�������ͷţ�
                     4:��3��ͬ����ͬ����ʹ��mrc_malloc8�����ڴ棻
                     5:��ͨ��filelen�����ļ����ȣ�

���:
*filebuf         ��lookfor==0��2��3ʱ�����ļ�����ָ��
*filelen         ��lookfor==0��2��3ʱ�����ļ����ݳ���

����:
      MR_SUCCESS   �ɹ�����lookfor==1ʱ��ʾ�ļ�����
      MR_FAILED       ʧ��

(      
���շ����в��ִ�����ʹ��mrc_readFileFromMrpEx����ʱ��
�Խ�����жϽ�ʹ����filebuf���ж��Ƿ�ΪNULL����������
�˺����ķ���ֵ��
      ���������ѣ�mrc_readFileFromMrpEx�����ڲ���ʧ��ʱ������
      ֵ��ʧ�ܣ���filebuf��ֵ��δ���壨Ҳ����˵��������
      NULL��Ҳ���ܲ���NULL�����������ʹ�ú�������ֵ��
      �н���жϣ�ʹ��filebuf�����ж��ǲ����յġ�
)
*/
int32 mrc_readFileFromMrpEx(char* packname, const char* filename, 
               uint8 ** filebuf, int32 *filelen, int32 lookfor);

/*
�ú�����mrc_readFileFromMrpEx�������ƣ���������:
1��lookfor������Ч���ڴ˱�����Ϊ���ݣ�
2����֧�����ڴ��л�̻���mrp��
3��mrp�е��ļ���ѹʱ�����ᱻ���嵽�ڴ��У�ռ���ڴ���٣�
*/
int32 mrc_readFileFromMrpExA(char* packname, const char* filename, 
               uint8** filebuf, int32 *filelen, int32 lookfor);


/*
�ú�����mrc_readFileFromMrpEx�������ƣ���������:
1��û��lookfor������mrc_readFileFromMrpExPart�����������ļ���ȡ��
2��mrc_readFileFromMrpExPart��������ȡԭʼ���ݣ�����ѹ���ļ�����
��ѹ��
3������offset:���ļ�offset��ʼ��ȡ���ݣ�
4������read_len:��ȡ�����ݳ��ȣ�
*/
int32 mrc_readFileFromMrpExPart(char* packname, const char* filename, 
               uint8 ** filebuf, int32 *filelen, int32 offset, int32 read_len);

/*
��mrp�ж�ȡ�ļ����������ݵ�������ڴ��С�
ʹ�øú����õ����ڴ棬��Ҫʹ��mrc_freeFileData�����ͷš�

����:
filename     mrp�ļ���
lookfor          ָ�������Ĳ�����ʽ:
                    0:    ��ȡmrp���ļ�������
                    1:    ��������mrp���Ƿ���ڸ��ļ���������ȡ
                               �ļ�����

���:
*filelen         ��lookfor==0ʱ�����ļ����ݳ���

����:
      ��NULL         ָ���ȡ�������ݵ�ָ�룬���ڴ���Ҫ
                              �������ͷ�
      NULL         ʧ��
*/
void * mrc_readFileFromMrp(const char* filename, int32 *filelen, int32 lookfor);

/*
�ͷ���mrc_readFileFromMrp������ȡ���ļ����ݿռ䡣
����:
data     �ļ�����ָ��
filelen          �ļ����ݳ���
*/
void mrc_freeFileData(void* data, int32 filelen);

/*
�ͷ���ԭʼ�ڴ����뷽ʽ����Ŀռ䡣
����:
add     ָ��
size   ����
*/
void mrc_freeOrigin(void* add, int32 size);

/*
����:
s     ��������ָ�룬��ΪNULL������г�ʼ����
n    �������ݳ��ȣ���sΪ��NULL��nΪ0�����ؼ�������
ʹ�÷���:
   mrc_updcrc(NULL, 0);          
   mrc_updcrc(s, n);
   return mrc_updcrc(s, 0);

*/
uint32 mrc_updcrc(uint8 *s, uint32 n);


void mrc_refreshScreenTrigger(int16 x, int16 y, uint16 w, uint16 h);
void mrc_refreshScreenUnTrigger(void);


typedef unsigned char md5_byte_t; /* 8-bit byte */
typedef unsigned int md5_word_t; /* 32-bit word */

typedef struct md5_state_s {
    md5_word_t count[2];	/* message length in bits, lsw first */
    md5_word_t abcd[4];		/* digest buffer */
    md5_byte_t buf[64];		/* accumulate block */
} md5_state_t;

extern void mrc_md5_init(md5_state_t *pms);

extern void mrc_md5_append(md5_state_t *pms, const md5_byte_t *data, int nbytes);

extern void mrc_md5_finish(md5_state_t *pms, md5_byte_t digest[16]);

extern int32 mrc_platDrawTextFlag;

extern void mrc_platDrawChar(uint16 ch, int32 x, int32 y, int32 color);


/*
  ��ʼ��ƽ̨��Second Screen Buffer ��չ�ڴ棺
  ���أ�
        MR_SUCCESS   �ɹ��� �����MTKƽ̨�Ϳ϶���ɹ���
        MR_FAILED    ʧ��   ��MTKƽ̨ʧ�ܡ�
*/
extern int32 mrc_exRamSSBInit(void);


/*
��ʼ��ƽ̨��Screen Based Application Shared Memory ��չ�ڴ棻
����:
      MR_SUCCESS   �ɹ�
      MR_FAILED       ʧ��
*/
extern int32 mrc_exRamInit(void);

/*
����ʼ��ƽ̨��SBASM��չ�ڴ棻
�������������mrc_exRamMalloc��ֻ��ʹ�����ڴ棬
mrc_exRamFree�����������ͷŵ��ڴ�ռ䣬�����ͷŵ�
�ռ�λ�����ڴ棬���ͷŸ��ڴ棬�����ͷŵĿռ�
λ����չ�ڴ棬�������κβ�����
����:
      MR_SUCCESS   �ɹ�
      MR_FAILED       ʧ��
*/
extern int32 mrc_exRamRelease(void);

extern int32 mrc_exRamSSBRelease(void);
/*
������չ�ڴ��������ڴ棬����չ�ڴ治�㣬�����ڴ�
�������ڴ棻
*/
extern void* mrc_exRamMalloc(int size);

/*
�����ͷŵĿռ�λ�����ڴ棬�������ڴ����ͷŸ��ڴ棬
�����ͷŵĿռ�λ����չ�ڴ棬������չ�ڴ����ͷŸ���
�棻
*/
extern void mrc_exRamFree(void *address);

/*
��������չ�ڴ棻
*/
extern void* mrc_exRamMallocOnly(int size);

/*
���ͷ���չ�ڴ棻
*/
extern void mrc_exRamFreeOnly(void *address);

/*
����չ�ڴ汣�浽�ļ���
#define MRC_EXRAM_FILE "cache/exr.cac"
����:
      MR_SUCCESS   �ɹ�
      MR_FAILED       ʧ��
*/
extern int32 mrc_exRamStore(void);

/*
���ļ�������չ�ڴ棻
����:
      MR_SUCCESS   �ɹ�
      MR_FAILED       ʧ��
*/
extern int32 mrc_exRamLoad(void);


/*
 *  ��ȡ�ڴ�ʹ�õ�״̬��[��λ Byte]
 *     mainUsed -  ���!=NULL, ��ô���Ϊ���ڴ汻ʹ�õ�����
 *     mainLeft -  ��� !=NULL, ��ô���Ϊ���ڴ�ʣ�������
 *     ssbUsed  -  ��� !=NULL�� ��ô���Ϊssbʹ�õ�������δ�����������-1
 *     ssbLeft  -  ��� !=NULL�� ��ô���Ϊssbʣ���������δ�����������-1
 *
 *     sbasmUsed  -  ��� !=NULL�� ��ô���Ϊsbasmʹ�õ�������δ�����������-1
 *     sbasmUsed  -  ��� !=NULL�� ��ô���Ϊsbasmʣ���������δ�����������-1
 *
 *  ����ֵ��
 *      ���ڴ�ķ�ֵ��
 */

extern int mrc_getMemStatus(int * mainUsed, int * mainLeft, 
					 int * ssbUsed, int * ssbLeft,  
					 int * sbasmUsed, int * sbasmLeft);


#endif
