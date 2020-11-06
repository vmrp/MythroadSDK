
#include "gamesound.h"
#include "mrc_base.h"

static T_SOUND_MAP sound_map[GAME_SOUND_MAX_ID];
static void AddSound(int16 id, uint8 type, const char* name);
/////////////////////////////////////////////////////////
static void AddSound(int16 id, uint8 type, const char* name)
{
	sound_map[id].type = type;
	sound_map[id].pData = mrc_readFileFromMrp(name,(int32 *)&(sound_map[id].len),0);
	if( sound_map[id].pData == NULL )
	{
		int32 ret =mrc_ferrno();
		mrc_printf("AddSound,addsound file[%s],type[%d],id[%d],errno[%d] failed!!!",name,type,id,ret);
		mrc_exit();
	}
}

int32 PlaySound(int32 index, int32 loop)
{
	if(index < GAME_SOUND_MAX_ID)
	{
		return  (mr_playSoundEx(sound_map[index].type, sound_map[index].pData, sound_map[index].len, loop));
	}
	return MR_FAILED;
}

void StopSound(int32 index)
{
	if( index > GAME_SOUND_MIN_ID  &&  index < GAME_SOUND_MAX_ID)
	{
		mr_stopSoundEx(sound_map[index].type);
	}
}

void InitSound(void)
{
	AddSound(GAME_SOUND_BK, MR_SOUND_MIDI, "background.mid");
}

void DestroySound(void)
{
	uint8  i;
	for( i=0; i<GAME_SOUND_MAX_ID; i++)
	{
		if( sound_map[i].pData != NULL && sound_map[i].len != 0)
		{
			free(sound_map[i].pData);
			sound_map[i].pData = NULL;
			sound_map[i].len = 0;
		}
	}
}

