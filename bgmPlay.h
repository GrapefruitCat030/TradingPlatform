#pragma once

#include<windows.h>
#include<stdio.h>
#pragma comment(lib,"WinMM.Lib")

#define WARMSOUND "bgm/Windows Ding.wav"
#define LOGINSOUND "bgm/Windows Logon.wav"
#define EXITSOUND "bgm/chime.wav"
#define SUCCESSSOUND "bgm/successSound.wav"
#define SEARCHSOUND "bgm/searchSound.wav"


void WarmSound();

void SuccessSound();

void LoginSound();

void ExitSound();

void SearchSound();



