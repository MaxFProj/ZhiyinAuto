#include <stdio.h>
#include <Windows.h>
#include "DESEncrypter.h"
#include <time.h>

#define ARRAY_SIZE 100
#define REG_TIME_LENGTH 6
unsigned char CharToHex(unsigned char ch)
{
	//convert	A----P to 0---15
	if ( ch >= 'A' && ch <= ('A'+15))
		return (ch - 'A');		
	return -1;
}

char HexToChar(unsigned char hex)
{
	//convert 0---15 to A----P(A+15)
	if (hex > 15)
	{
		return -1;
	}
	else 
		return hex + 'A';	 
}

/**
 * 获取当前时间
 * 用6位表示当前时间，具体每位的含义见函数体内的注释
 */
void getCurrentTime(char regTime[10])
{
	time_t temptime= time(0);
	tm *temptm = localtime(&temptime);
// 	errno_t err;
// 	tm t;
// 	tm *temptm = &t;
// 	err = localtime_s(temptm, &temptime);
	printf("regTime: %d-%d-%d %d:%d:%d\n", temptm->tm_year, temptm->tm_mon, temptm->tm_mday);

	if(temptm->tm_year <  107)
		temptm->tm_year = 107;
	regTime[0] = temptm->tm_year;	/// 自1900起的年份，例如2013年则为113.一个char最大可以表示到255,所以可放心使用
	regTime[1] = temptm->tm_yday % 100 + 10;	/// 自从1月1日起的天数tm_yday的百位+10，最大为13
	regTime[2] = temptm->tm_yday / 100 + 100;	/// tm_yday的十位和个位 + 100，最大为199
	regTime[3] = temptm->tm_mon * 3 + 30;		/// 月份 * 3 + 30, 最大为11*3+30=63
	regTime[4] = temptm->tm_mday % 10 + 80;		/// tm_mday的个位 + 80
	regTime[5] = temptm->tm_mday / 10 + 90;		/// tm_mday的十位 + 90
	regTime[6] = '\0';
}

void Encrypt(char regCode[255])
{
	printf(">> [%s]\n", regCode);

	char key[] = {'b', 'F', 'd', 'E', 'G', '/', '!', 'T', '5', '~', '#', 'p', 'U', 'W', 'r', 'e'};
	char buf[255], outbuf[255];
	memset(buf, 0, sizeof(buf));
	memset(outbuf, 0, 255);

	int regCodeLength = strlen(regCode);
	memcpy(buf, regCode, regCodeLength);
	memset(regCode, 0, regCodeLength);
	CDESEncrypter des;
	des.Des_Go(outbuf, buf, regCodeLength, key, sizeof(key), CDESEncrypter::ENCRYPT);
	//des.Des_Go(outbuf, buf, regCodeLength, key, sizeof(key), CDESEncrypter::DECRYPT);
// 	printf(">> [%s]\n", outbuf);
// 	printf(">> [%d]\n", strlen(outbuf));

	// 将注册码加密为明文，两个16进制数转为一个char
	//regCodeLength = static_cast<int>(regCodeLength) / 2;;
	regCodeLength = 32; //strlen(outbuf);
	for(int j = 0; j < regCodeLength; ++j){
		char ch8 = outbuf[j];
		unsigned char high4 = (ch8 >> 4) & 0x0F;//CharToHex(regCode[j * 2]);
		unsigned char low4  =  ch8 & 0x0F;      //CharToHex(regCode[j * 2 + 1]);
		//ch8 = ch8 | (high4 << 4) | low4 ;
		regCode[j * 2] = HexToChar(high4);
		regCode[j * 2 + 1] = HexToChar(low4);
	}

	for (int i = 0; i < 64; i++)
	{
		printf("%d ", regCode[i]);
	}
}

/**
 * 注册为试用版
 */
void RegIDToTrial(char regID[21], char trialRegID[21])
{
	//将注册码每位加1
	for(int i = 0; i < 20; ++i)
		trialRegID[i] = regID[i] + 1;
	trialRegID[20] = '\0';
/*	printf("%s", trialRegID);*/
}

void RegIDToLimited(char regID[21], char limitedRegID[21])
{
	//将注册码奇数位放到前10位，偶数位放到后10位，每位加2
	for(int i = 0; i < 10; ++i) {
		limitedRegID[i]      = regID[i * 2]     + 2;
		limitedRegID[10 + i] = regID[i * 2 + 1] + 2;
	}
	limitedRegID[20] = '\0';
}

void RegIDToFull(char regID[21], char fullRegID[21])
{
	//先取10个奇数位，然后10个偶数位，然后循环右移7位。每位加3
	for(int i = 0; i < 10; ++i) {
		fullRegID[(i + 7) % 20]  = regID[i * 2 ]    + 3; //前面10个放奇数位
		fullRegID[(i + 17) % 20] = regID[i * 2 + 1] + 3; //后面10个放偶数位
	}
	fullRegID[20] = '\0';
	//printf("%s", fullRegID);
}

/**
 * 根据机器码和注册类型生成注册码
 * 目前支持两种类型的注册：注册为正式版、注册为试用版
 * 注册码的前20位为根据机器码和注册类型生成的注册码，第21位起用REG_TIME_LENGTH位保存注册时间
 */
void reg(char machineCode[21], char regCode[ARRAY_SIZE], int regType)
{
	if (regType == 1)
	{
		RegIDToTrial(machineCode, regCode);
		char curTime[10];
		getCurrentTime(curTime);
		memcpy(regCode + 20, curTime, REG_TIME_LENGTH);
		regCode[20 + REG_TIME_LENGTH + 1] = 0;
		Encrypt(regCode);
	}
	else if (regType == 2)
	{
		RegIDToLimited(machineCode, regCode);
		char curTime[10];
		getCurrentTime(curTime);

		memcpy(regCode + 20, curTime, REG_TIME_LENGTH);
		regCode[20 + REG_TIME_LENGTH + 1] = 0;
		Encrypt(regCode);
	}
	else if (regType == 3)
	{
		RegIDToFull(machineCode, regCode);
		char curTime[10];
		getCurrentTime(curTime);
		memcpy(regCode + 20, curTime, REG_TIME_LENGTH);
		regCode[20 + REG_TIME_LENGTH + 1] = 0;
// 		for (int i =0; i < 26; i++)
// 		{
// 			printf("%c ", regCode[i]);
// 		}
		Encrypt(regCode);
	}
// 	else if (regType == 3)
// 	{
// 		RegIDToTrial(machineCode, regCode);
// 	}
	else
	{
		printf("%s : 注册类型错误!\n", regCode);
	}
}

int main(int argc, char **argv)
{
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("◆　　%s注册机　　\n", APP_NAME);
	printf("◆　　1.注册试用版(至2016-5-9)\t\t\n");
	printf("◆　　2.注册试用版(试用30天)  \t\t\n");
	printf("◆　　3.注册正式版　　　　　　\t\t\n");
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("> 请输入选项序号并按回车键确认:\n");
	int s;
	scanf_s("%d", &s);
	printf("> 请输入待注册的机器码并按回车键确认:\n");
	char machineCode[ARRAY_SIZE];
	char regCode[ARRAY_SIZE];
	memset(machineCode, 0, ARRAY_SIZE);
	memset(regCode, 0, ARRAY_SIZE);
	scanf("%s", machineCode);
	reg(machineCode, regCode, s);
	// 输出注册结果
	printf("---------------------------------\n");
	switch (s) {
		case 1:
			printf("> 注册试用版软件(试用至2016-5-9)\n");
			break;
		case 2:
			printf("> 注册试用版软件(试用30天)\n");
			break;
		case 3:
			printf("> 注册正式版软件\n");
			break;
		default:
			break;
	}
	printf("> 机器码：%s\n", machineCode);
	printf("> 注册码：%s\n", regCode);
	printf("---------------------------------\n");	
	FILE* f = fopen("emxRegCode.txt", "a");
	if (f != NULL)
	{
		fprintf(f, "---------------------------------\n");
		switch(s) {
			case 1:
				fprintf(f, "> 注册试用版软件(试用至2016-5-9)\n");
				break;
			case 2:
				fprintf(f, "> 注册试用版软件(试用30天)\n");
				break;
			case 3:
				fprintf(f, "> 注册正式版软件\n");
				break;
			default:
				break;
		}
		fprintf(f, "> 机器码：%s\n", machineCode);
		fprintf(f, "> 注册码：%s\n", regCode);

		time_t temptime= time(0);
		fprintf(f, "> 生成时间：%s", ctime(&temptime));
		fprintf(f, "---------------------------------\n");
		fclose(f);
		printf("注册码已保存到emxRegCode.txt\n");
	}
	system("pause");
	return 0;
}