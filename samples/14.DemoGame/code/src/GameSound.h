#ifndef INCLUDE_GAME_SOUND_H_
#define INCLUDE_GAME_SOUND_H_

#include "mrc_base.h"

enum {
	GAME_SOUND_MIN_ID,
	GAME_SOUND_BK,
	GAME_SOUND_MAX_ID
};

typedef struct {
	int32 len;
	uint8 type;
	void* pData;
} T_SOUND_MAP;

int32 PlaySound(int32 index, int32 loop);
void StopSound(int32 index);
void InitSound(void);
void DestroySound(void);

#endif
