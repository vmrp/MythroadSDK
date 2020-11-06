#ifndef __MRC_MENU_H__
#define __MRC_MENU_H__

/*
���ļ��Լ���Ӧ��C�����ļ�����mythroad�ṩ�Ļ�������
�����˷�װ��ʹ��mrc_win�ṩ�Ļ�������ܹ����ṩ��
�˵�����ķ�װ��
*/


/*
�˵��ѡ��ʱ�Ļص�����
����:
data        �˵�������
*/
typedef void (*PtrHilight)(int32 data);

typedef struct
{
	PtrHilight hCb;
	int32 data;              
}T_MENU_ITEM;

typedef struct
{
	int32 handle;  
	int32 itemNum;  
	T_MENU_ITEM EscMenu[1];//�û������κ�ѡ��ֱ��ѡ�񡰷��ء���ʱ�Ļص������ĺ���ָ��Ͳ���ָ�롣	
	T_MENU_ITEM subMenu[1];//�����˵���Ļص�����ָ��Ͳ���ָ��
}T_MENU;

/*
�½�һ���˵�

����:
title:       �˵�����
num:         �˵������Ŀ

����:
      ����              ������
      MR_FAILED         ʧ��
*/
int32 mrc_platMenuNew(char* title, int32 num);

/*
	�ڲ˵�������һ���˵������index�Ǹò˵����
	��š�

����:
menu   �˵��ľ��
text      �˵�������֣�ʹ��unicode���룬�����ֽ��򡣵�����numʱ�����������塣
index    �˵����index�š�indexȡֵ��ΧΪ[0��num](num����mrc_platMenuNew����
�˵�ʱָ���Ĳ˵�����Ŀ)��������numʱ���ǰ������ء����Ļص�������
SDK�ڴ����û����"����"��ʱ��Ĭ�ϲ����κβ�����ֱ�ӹرմ��ڣ�
���û��Զ����˻ص�����ʱ����Ҫ�û��ڻص������и���رմ��ڡ�


cb         ���û�ѡ��ò˵���ʱ�Ļص�
data      �˵�������

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_platMenuSetItem(int32 menu, const char *text, int32 index, PtrHilight cb, int32 data);

/*
��ʾ�˵���

����:
menu �˵��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_platMenuShow(int32 menu);

/*
ˢ�²˵���ʾ��

����:
menu �˵��ľ��

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_platMenuRefresh(int32 menu);

#endif

