#include "bgmPlay.h"

void WarmSound()
{
	PlaySound(TEXT(WARMSOUND), NULL, SND_FILENAME | SND_ASYNC);
}

void SuccessSound()
{
	PlaySound(TEXT(SUCCESSSOUND), NULL, SND_FILENAME | SND_ASYNC);
}

void LoginSound()
{
	PlaySound(TEXT(LOGINSOUND), NULL, SND_FILENAME | SND_ASYNC);
}

void ExitSound()
{
	PlaySound(TEXT(EXITSOUND), NULL, SND_FILENAME | SND_ASYNC);
}

void SearchSound()
{
	PlaySound(TEXT(SEARCHSOUND), NULL, SND_FILENAME | SND_ASYNC);
}

