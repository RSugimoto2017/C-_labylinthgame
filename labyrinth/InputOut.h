#pragma once

#include <Windows.h>
//#include "stdafx.h"
//#include "pch.h"
#include "character.h"

#define BUFFSIZE 1024
#define DAYS	 365
#define CHARBUFF 124

int getIntFromINI(const char* section, const char* para, const char* file, int defaultValue);
void getGurrentDirectory(char *currentDirectory);

void getGurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

int getIntFromINI(const char* section, const char* para, const char* file, int defaultValue) {

	int num;

	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);

	char sect[CHARBUFF];
	sprintf_s(sect, section);
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, para);
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, file, currentDirectory);
	//fprintf(stdout, "%s , %d\n", settingFile, GetPrivateProfileInt(section, keyWord, -1, settingFile));

	num = GetPrivateProfileInt(section, keyWord, -1, settingFile);

	return num;
}

//結果の出力
void Output(const char* fileName, int playerscore) {
	FILE* fp;
	errno_t error;
	char final_score[BUFFSIZE];

	error = fopen_s(&fp, fileName, "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		sprintf_s(final_score, "スコア ： %d点", playerscore);
		fputs(final_score, fp);
		fclose(fp);
	}
}