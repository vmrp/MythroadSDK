#ifndef __MRC_AUX_H__
#define __MRC_AUX_H__

/*
���ļ��Լ���Ӧ��C�����ļ�����mythroad�ṩ�Ļ�������
�����˷�װ���ṩһЩ���õĸ���������
*/


/*
��ȡmrp��һ���ļ���ָ���������ݵ�ָ���ռ䡣����
��ȡ�ļ�filename��len���ȵ����ݵ�bufָ��ĵ�ַ�ϣ���
�ļ�����С��len������ȡ�ļ����ȵ����ݣ�len����ֵ
Ϊʵ�ʶ�ȡ�ĳ��ȡ�

����:
filename          �ļ���
buf                  ��ȡ���ļ��ı���ռ�
len                  ������ȡ����

���:
len                  ʵ�ʶ�ȡ����

����:
      MR_SUCCESS  �ɹ�
      MR_FAILED   ʧ��
*/
int32 mrc_readAllEx(char* filename, char* buf, int32 *len);

#endif

