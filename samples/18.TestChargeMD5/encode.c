#include "..\..\modules\mrc_base.h"
#include "encode.h"


#define MAX_MD5_LEN 16
#define BUF_SIZE 1024

int32 fd;
SAVE_RECORD_T *g_record;

void md5Init(void);
void md5ToString(uint8* in, uint8* out);
void md5Make(uint8* in , int32 len, uint8* out);
void destroyMd5(void);

void md5Init(void)
{
	g_record = malloc(sizeof(SAVE_RECORD_T));
	memset(g_record, 0, sizeof(SAVE_RECORD_T));

	fd = 0;
}

void md5Make(uint8* in , int32 len, uint8* out)
{
	md5_state_t md5;
	
	memset(&md5, 0, sizeof(md5_state_t));	
	mrc_md5_init(&md5);
	mrc_md5_append(&md5, (const md5_byte_t *)in, len);
	mrc_md5_finish(&md5, out);
}


//该段代码为检验计算出的MD5值与MD5工具的值是否一致
void md5ToString(uint8* in, uint8* out)
{
	int32 i = 0;
	for(i=0; i<MAX_MD5_LEN;i++)
	{
		out[2*i] = in[i]>>4 & 0x0f;
		out[2*i+1] = in[i] & 0x0f;
	}

	for (i=0;i<2*MAX_MD5_LEN;i++)
	{
		switch ((int32)out[i])
		{
		case 0:
			out[i] = '0';
			break;
		case 1:
			out[i] = '1';
			break;
		case 2:
			out[i] = '2';
			break;
		case 3:
			out[i] = '3';
			break;
		case 4:
			out[i] = '4';
			break;
		case 5:
			out[i] = '5';
			break;
		case 6:
			out[i] = '6';
			break;
		case 7:
			out[i] = '7';
			break;
		case 8:
			out[i] = '8';
			break;
		case 9:
			out[i] = '9';
			break;
		case 10:
			out[i] = 'A';
			break;
		case 11:
			out[i] = 'B';
			break;
		case 12:
			out[i] = 'C';
			break;
		case 13:
			out[i] = 'D';
			break;
		case 14:
			out[i] = 'E';
			break;
		case 15:
			out[i] = 'F';
			break;
		}
	}
}


void destroyMd5(void)
{
	if (!g_record)
	{
		mrc_free(g_record), g_record = NULL;
	}
	if (!fd)
	{
		mrc_close(fd), fd = 0;
	}
}
