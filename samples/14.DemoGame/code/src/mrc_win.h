#ifndef __MR_HELPER_WIN_H__
#define  __MR_HELPER_WIN_H__

/*
���ļ��Լ���Ӧ��C�����ļ�����mythroad�ṩ�Ļ�������
�����˷�װ���ṩһ�ֻ����Ĵ���ܹ���
*/



#define MAX_WIN_NO       30

typedef enum
{
	WIN_EVENT_SHOW,                  //���ڴ�����֮��ͻ��յ�����¼�������������¼��л����ڵĽ���
	WIN_EVENT_PAUSE,                 //������һ���µĴ��ں󣬸����ڻ��յ�����¼�
	WIN_EVENT_REFRESH,               //���Ӵ������ٵ��󣬸����ڻ��յ�����¼�
	WIN_EVENT_UPDATE,               //�ⲿ�����޸Ĵ�����Ҫ��ʾ�Ĺ��ܣ�Ȼ����ô��巢������¼�ʹ���彫���µ����ݻ�����Ļ��
	WIN_EVENT_EXIT                     //����winDelete��ϵͳ����Ҫ���ٵĴ��ڷ�������¼����Ѵ�����������˳�����
}T_WIN_EVENT;


/*
�����¼��ص�

����:
data          ��������
eventId     �����¼�
      WIN_EVENT_SHOW,                  //���ڴ�����֮��ͻ��յ�����¼���
                                                        ����������¼��л����ڵĽ���
      WIN_EVENT_PAUSE,                 //������һ���µĴ��ں󣬸����ڻ���
                                                         ������¼�
      WIN_EVENT_REFRESH,               //���Ӵ������ٵ��󣬸����ڻ��յ���
                                                         ���¼�
      WIN_EVENT_UPDATE,               //�ⲿ�����޸Ĵ�����Ҫ��ʾ�Ĺ��ܣ�
                                                         Ȼ����ô��巢������¼�ʹ���彫
                                                         ���µ����ݻ�����Ļ��
      WIN_EVENT_EXIT                     //����winDelete��ϵͳ����Ҫ���ٵĴ�
                                                         �ڷ�������¼����Ѵ����������
                                                         �˳�����
*/
typedef void (*PtrWinEvent)(int32 data,int32 eventId); 

/*
���尴���¼��ص�

����:
data                                 ��������
code, param0, param1       ��mrc_event������code, param0, param1����������ͬ

*/
typedef void (*PtrKeyEvent)(int32 data, int32 code,int32 param0,int32 param1);


typedef struct
{
	int32 id;
	PtrKeyEvent keyCb;
	PtrWinEvent winCb;
	int32 data;
}T_FRAME_WIN;

/*
����ܹ���ʼ��
*/
void mrc_winInit(void);

/*
����Ϊ�������ܵ��¼��������������ⲿ���յ��¼�ʱ
���ã�һ����mrc_event�е��øú��������������ܡ�

�����Զ��崰��ʱ��ע�����������ں�����һ���Ǽ����¼�
��������һ���Ǵ����¼����������������ṩ����������
mrc_winKeyEvent��mrc_winWinEvent�ֱ����ڴ��������¼��������ʹ���
�¼���������
	mrc_winEvent()�������ʱֻʵ����mrc_winKeyEvent�Ĺ��ܣ��պ󽫱�ɾ����
	�������ټ���ʹ�ã�������Ҫ���ڱ������д���ļ����ԡ�

����:
type,p1,p2     ��mrc_event������code, param0, param1����������ͬ
eventId ����Чȡֵ��Χ�Ǹô���Ĵ��崦�����ж��塣

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_winEvent(int32 type, int32 p1, int32 p2);
int32 mrc_winKeyEvent(int32 type, int32 p1, int32 p2);
int32 mrc_winWinEvent(int32 eventId);
/*
����Ϊ�������ܵĻָ�(����ͣ��Ӧ�õ�)��������������
�����յ��ָ��¼�ʱ���ã�һ����mrc_resume�е��øú�����
����������
*/
void mrc_winResume(void);

/*
�½�����

����:
data          ��������
winEvent   �����¼�������
keyEvent   �����¼�������

����:
      >=0                   ����id
      MR_FAILED         ʧ��
*/
int32 mrc_winNew(int32 data,PtrWinEvent winEvent,PtrKeyEvent keyEvent);

/*
�ر����ϲ�Ĵ���

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_winClose(void);


/*
�ر����ϲ�Ĵ��壬��ˢ���丸����(����һ�㴰��)

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_winCloseNotShow(void);

/*
ͨ������id�رմ���

����:
id                  ����id

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_winCloseById(int32 id);

/*
ͨ������idȡ�ô�������

����:
id                  ����id

���:
data              ��������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_getWinDataById(int32 id, int32* data);

/*
ȡ�����ϲ㴰��(��Ծ����)�Ĵ���id

����:
      >=0                   ����id
      MR_FAILED         ʧ��
*/
int32 mrc_getActiveWinId(void);

/*
ȡ�����ϲ㴰��(��Ծ����)�Ĵ�������

���:
data              ��������

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_winGetActiveWinData(int32* data);

/*
���巢�ʹ����¼�

����:
winId                  ����id
eventId              �����¼�

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_sendEventTo(int32 winId,int32 eventId);

/*
��鴰���Ƿ��Ѿ�����

����:
winId                  ����id

����:
      TRUE          �����Ѿ�����
      FALSE         ������δ����
*/
int32 mrc_isTheWinCreated(int32 winId);


int32 getVMStat(void);
int32 setVMStat(int32 stat);
int32 isVMIn(void);

#endif

