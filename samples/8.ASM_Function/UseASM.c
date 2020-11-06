#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"

#ifdef DEMO_DEBUG
#define DBG_PRINTF(a) mrc_printf a
#else
#define DBG_PRINTF(a) 
#endif

//������˵����
int32 main_menu;
extern long FixedByFrac(long a, long b);


//�˵���A:Ƕ����
void main_menuA(int32 data){
	long a=65539,b=65539,c=0;
	c=FixedByFrac(a,b);
	DBG_PRINTF(("Ƕ������%d",c));
   mrc_platTextNew("\x5d\x4c\x51\x65\x6c\x47\x7f\x16", "\x7f\x16\x8b\xd1\x90\x9\x98\x79\x4e\x3a\x4f\x7f\x75\x28\x6c\x47\x7f\x16\x5b\x9e\x73\xb0\x30\x2", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
}

//�˵���B:����
void main_menuB(int32 data){
   mrc_platTextNew("\x5e\x2e\x52\xa9", "\x8f\xd9\x66\x2f\x0\x43\x4e\x2d\x5d\x4c\x51\x65\x6c\x47\x7f\x16\x5b\x9e\x73\xb0\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x5b\x9a\x70\xb9\x5c\xf\x65\x70\x4e\x58\x6c\xd5\x76\x84\x0\x44\x0\x45\x0\x4d\x0\x4f\xff\x1", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
}

void main_menuExit(int32 data){
	mrc_winClose();
}

/*
Ӧ�ó�ʼ������
�ú�����Ӧ�ó�ʼ���ڼ䱻mythroadƽ̨���ã����������
�����н���ȫ�ֱ����ĳ�ʼ���ȹ�����
����ֵ:
MR_SUCCESS  Ӧ�ó�ʼ���ɹ�
MR_FAILED      Ӧ�ó�ʼ��ʧ��
*/
int32 mrc_init(void)
{
   mrc_winInit();
   mrc_clearScreen(0, 0, 0);

      //�������˵�
      main_menu = mrc_platMenuNew("\x5d\x4c\x51\x65\x6c\x47\x7f\x16", 2); //Ƕ����
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x5b\x9a\x70\xb9\x5c\xf\x65\x70\x4e\x58\x6c\xd5", 0, main_menuA, 0);//16bit����С���˷�
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 1, main_menuB, 0);   // ����
         mrc_platMenuSetItem(main_menu, NULL, 2, main_menuExit, 0);   // �����û�����ѡ�񡢵��"����"�¼���
         mrc_platMenuShow(main_menu);
         
      }
      else
      {
         return MR_FAILED;
      }
   return MR_SUCCESS;
}



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
   MR_EVENT02,             //VM�������벻Ҫʹ��
   MR_EXIT_EVENT,           //Ӧ���˳��¼�
   MR_EVENT03,                 //VM�������벻Ҫʹ��
   MR_LOCALUI_EVENT         //���ػ��ӿ��¼�
};

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
int32 mrc_event(int32 code, int32 param0, int32 param1)
{
   mrc_winEvent(code, param0, param1);
   return MR_SUCCESS;
}

/*
Ӧ����ͣ����
�ú�����Ӧ�ñ���ͣʱ���е绰���¼���ͣӦ�ã�
��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_pause(void)
{
   return 0;
}

/*
�ú�����Ӧ�ûָ�����ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_resume(void)
{
   mrc_winResume();
   return 0;
}

/*
�ú�����Ӧ���˳�ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_exitApp(void)
{
   return 0;
}