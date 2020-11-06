#ifndef __MRC_TEXT_H__
#define __MRC_TEXT_H__

/*
���ļ��Լ���Ӧ��C�����ļ�����mythroad�ṩ�Ļ�������
�����˷�װ��ʹ��mrc_win�ṩ�Ļ�������ܹ����ṩ��
�ı��򡢶Ի����Լ�����չ����ķ�װ��
*/

/*
�ı��򡢶Ի�����İ����ص�����
����:
data        ��������
*/
typedef void (*PtrHilight)(int32 data);

typedef struct
{
	int32 handle;
	int32 data;              
	PtrHilight hOk;
	PtrHilight hCancel;
}T_PLAT_TEXT;

typedef struct
{
	int32 handle; 
	int32 data;              
	int32 type;
	PtrWinEvent winEvent;
     PtrKeyEvent keyEvent;
}T_PLAT_WIN;



/*
�½�һ���ı���

����:
title:          �ı������
texttext:    �ı�������
type:         �ı�������
      MR_DIALOG_OK���ı�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���ı�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���ı����� "ȡ��/����"����
textdata    ��������
hOk          �û�ѡ��"ȷ��"ʱ�Ļص�
hCancel    �û�ѡ��"ȡ��/����"ʱ�Ļص�

����:
      ����              ������
      MR_FAILED         ʧ��
*/
int32 mrc_platTextNew(char* title, char* texttext, int32 type, int32 textdata, PtrHilight hOk, PtrHilight hCancel);

/*
ˢ���ı���

����:
title:          �ı������
texttext:    �ı�������
text:         �ı�����

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_platTextRefresh(int32 text, char * title, char * texttext);

/*
�½�һ������չ����

����:
data            ��������
winEvent      �����¼�������
keyEvent     �����¼�������

����:
      ����              ������
      MR_FAILED         ʧ��
*/
int32 mrc_platWinNew(int32 data, PtrWinEvent winEvent, PtrKeyEvent keyEvent);

/*
�����½�һ����������

����:
data            ��������
winEvent      �����¼�������
keyEvent     �����¼�������

����:
      ����              ������
      MR_FAILED         ʧ��
*/
int32 mrc_platBaseWinNew(int32 data, PtrWinEvent winEvent, PtrKeyEvent keyEvent);

/*
�½�һ���Ի���

����:
title:          �Ի������
texttext:    �Ի�������
type:         �Ի�������
      MR_DIALOG_OK���Ի�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���Ի�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���Ի����� "ȡ��/����"����
textdata    ��������
hOk          �û�ѡ��"ȷ��"ʱ�Ļص�
hCancel    �û�ѡ��"ȡ��/����"ʱ�Ļص�

����:
      ����              ������
      MR_FAILED         ʧ��
*/
int32 mrc_platDialogNew(char* title, char* texttext, int32 type, int32 textdata, PtrHilight hOk, PtrHilight hCancel);

/*
ˢ�¶Ի���

����:
title:          �Ի������
texttext:    �Ի�������
text:         �Ի�����
type:         �Ի�������
      MR_DIALOG_OK���Ի�����"ȷ��"����
      MR_DIALOG_OK_CANCEL���Ի�����"ȷ��"��"ȡ��"����
      MR_DIALOG_CANCEL���Ի����� "ȡ��/����"����

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_platDialogRefresh(int32 text, char * title, char * texttext, int32 type);

#endif

