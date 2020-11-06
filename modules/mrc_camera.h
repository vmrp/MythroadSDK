#ifndef  INCLUDE_MRC_CAMERA_H
#define INCLUDE_MRC_CAMERA_H

//#include "mrc_base.h"

typedef enum
{
	CAMERA_STATUS_UNINIT,//δ��ʼ��״̬
	CAMERA_STATUS_INIT,//��ʼ���ɹ�״̬
	CAMERA_STATUS_INIT_FAILED,//��ʼ��ʧ��״̬ 
	CAMERA_STATUS_START,//�����ɹ�״̬
	CAMERA_STATUS_START_FAILED,//����ʧ��״̬
	CAMERA_STATUS_CAPTURE,//���ճɹ�״̬
	CAMERA_STATUS_CAPTURE_FAILED,//����ʧ��״̬
	CAMERA_STATUS_PAUSE,//��ͣ״̬
	CAMERA_STATUS_RESUME_FAILED,//�ָ�ʧ��״̬
	CAMERA_STATUS_CLOSE//�ر�״̬
}CAMERA_STATUS_T;


typedef enum
{
	CAMERA_CAPTURE_MODE_MULTIPLE = 1,//��������ģʽ
	CAMERA_CAPTURE_MODE_SINGLE = 2//��������ģʽ,��������Ժ����Ҫ��������Ҫ����mrc_Camera_resume
}CAMERA_CAPTURE_MODE_T;


typedef enum
{
	CAMERA_IMG_QUALITY_LOW,//�ϲ��ͼƬ����
	CAMERA_IMG_QUALITY_NORMAL,//һ��Ч����ͼƬ����
	CAMERA_IMG_QUALITY_HIGH//��Ʒ�ʵ�ͼƬ����
}CAMERA_IMG_QUALITY_T;


typedef struct
{
	void* img_data;//���շ��ص�jpg��ʽͼƬ����ָ�� 
	int32 img_data_len;//���շ��ص�jpg��ʽͼƬ���ݳ���
}CAMERA_IMG_DATA_T;


/*
������:mrc_Camera_init
����:����ͷ�豸��ʼ��
���룺��
���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���

��ע:ʹ������ͷ֮ǰ������øýӿڣ������޷���������
*/
int32 mrc_Camera_init(void);

/*
������:mrc_Camera_creat
����:��������ͷԤ������
���룺
x:Ԥ�������x����
y:Ԥ�������y����
prevW:Ԥ������Ŀ��
prevH:Ԥ������ĸ߶�
imgW:����������Ƭ�Ŀ��
imgH:����������Ƭ�ĸ߶�
img_quality_type:��Ƭ��������
	CAMERA_IMG_QUALITY_LOW:�ϲ��ͼƬ����
	CAMERA_IMG_QUALITY_NORMAL:һ��Ч����ͼƬ����
	CAMERA_IMG_QUALITY_HIGH:��Ʒ�ʵ�ͼƬ����

���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���

ע��:prevW��prevH��󣬷ֱ�Ϊ��Ļ�Ŀ�͸ߣ������Ļ��С��240x320��
��ô���ǵ����ֵ�ֱ�Ϊ240��320��
imgW��imgH�����ֵ������ͷ�������й�ϵ�����Դ�����Ļ�Ŀ�͸ߡ�
*/
int32 mrc_Camera_creat(uint16 x, uint16 y, uint16 prevW, uint16 prevH, uint16 imgW, uint16 imgH,uint32 img_quality_type);

/*
������:mrc_Camera_capture
����:����
���룺
mode:����ģʽ�������ĺ͵�������ģʽ
	CAMERA_CAPTURE_MODE_MULTIPLE: ��������ģʽ
	CAMERA_CAPTURE_MODE_SINGLE: ��������ģʽ,��������Ժ����Ҫ��������Ҫ����mrc_Camera_resume

���:
img_data:����������յ�jpgeͼƬ���ݣ���������ָ������ݴ�С,���������Ժ�
�û���Ҫ�Լ������ڴ�ռ䣬��ͼƬ���п���
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���
*/
int32 mrc_Camera_capture(uint8 mode,CAMERA_IMG_DATA_T* img_data);

/*
������:mrc_Camera_destroy
����:�ر�����ͷ�豸
����:��
���:��
����:��
��ע:���øýӿ��Ժ�������ٴ�ʹ�ã���ô�������³�ʼ������ͷ
*/
void mrc_Camera_destroy(void);

/*
������:mrc_Camera_pause
����:��ͣ����ͷ�������ǰ����Ԥ��״̬��
��ô�����˳�Ԥ��״̬
���룺��
���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���
*/
int32 mrc_Camera_pause(void);

/*
������:mrc_Camera_resume
����:�ָ�����ͷ�������ǰ����Ԥ��״̬��
��ô����ָ���Ԥ��״̬
���룺��
���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���
*/
int32 mrc_Camera_resume(void);

/*
������:mrc_Camera_getZoom
����:��ȡ����ͷ���ŵȼ�
���룺��
���:��
���أ�����ͷ���ŵȼ�
*/
int32 mrc_Camera_getZoom(void);

/*
������:mrc_Camera_zoomOut
����:����ͷ��С����
���룺��
���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���
*/
int32 mrc_Camera_zoomOut(void);

/*
������:mrc_Camera_zoomIn
����:����ͷ�Ŵ���
���룺��
���:��
���أ�
    MR_SUCCESS  �ɹ�
    MR_FAILED   ʧ��
    MR_IGNORE ��֧�ָù���
*/
int32 mrc_Camera_zoomIn(void);

/*
������:mrc_Camera_status
����:��ȡ����ͷ��ǰ״̬
���룺��
���:��
���أ�����ͷ״ֵ̬������״ֵ̬����:
	CAMERA_STATUS_UNINIT δ��ʼ��״̬
	CAMERA_STATUS_INIT ��ʼ���ɹ�״̬
	CAMERA_STATUS_INIT_FAILED ��ʼ��ʧ��״̬ 
	CAMERA_STATUS_START �����ɹ�״̬
	CAMERA_STATUS_START_FAILED ����ʧ��״̬
	CAMERA_STATUS_CAPTURE ���ճɹ�״̬
	CAMERA_STATUS_CAPTURE_FAILED ����ʧ��״̬
	CAMERA_STATUS_PAUSE ��ͣ״̬
	CAMERA_STATUS_RESUME_FAILED �ָ�ʧ��״̬
	CAMERA_STATUS_CLOSE �ر�״̬

*/
uint8 mrc_Camera_status(void);

#endif//INCLUDE_MRC_CAMERA_H
