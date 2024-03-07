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
 * ��ȡ��ǰʱ��
 * ��6λ��ʾ��ǰʱ�䣬����ÿλ�ĺ�����������ڵ�ע��
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
	regTime[0] = temptm->tm_year;	/// ��1900�����ݣ�����2013����Ϊ113.һ��char�����Ա�ʾ��255,���Կɷ���ʹ��
	regTime[1] = temptm->tm_yday % 100 + 10;	/// �Դ�1��1���������tm_yday�İ�λ+10�����Ϊ13
	regTime[2] = temptm->tm_yday / 100 + 100;	/// tm_yday��ʮλ�͸�λ + 100�����Ϊ199
	regTime[3] = temptm->tm_mon * 3 + 30;		/// �·� * 3 + 30, ���Ϊ11*3+30=63
	regTime[4] = temptm->tm_mday % 10 + 80;		/// tm_mday�ĸ�λ + 80
	regTime[5] = temptm->tm_mday / 10 + 90;		/// tm_mday��ʮλ + 90
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

	// ��ע�������Ϊ���ģ�����16������תΪһ��char
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
 * ע��Ϊ���ð�
 */
void RegIDToTrial(char regID[21], char trialRegID[21])
{
	//��ע����ÿλ��1
	for(int i = 0; i < 20; ++i)
		trialRegID[i] = regID[i] + 1;
	trialRegID[20] = '\0';
/*	printf("%s", trialRegID);*/
}

void RegIDToLimited(char regID[21], char limitedRegID[21])
{
	//��ע��������λ�ŵ�ǰ10λ��ż��λ�ŵ���10λ��ÿλ��2
	for(int i = 0; i < 10; ++i) {
		limitedRegID[i]      = regID[i * 2]     + 2;
		limitedRegID[10 + i] = regID[i * 2 + 1] + 2;
	}
	limitedRegID[20] = '\0';
}

void RegIDToFull(char regID[21], char fullRegID[21])
{
	//��ȡ10������λ��Ȼ��10��ż��λ��Ȼ��ѭ������7λ��ÿλ��3
	for(int i = 0; i < 10; ++i) {
		fullRegID[(i + 7) % 20]  = regID[i * 2 ]    + 3; //ǰ��10��������λ
		fullRegID[(i + 17) % 20] = regID[i * 2 + 1] + 3; //����10����ż��λ
	}
	fullRegID[20] = '\0';
	//printf("%s", fullRegID);
}

/**
 * ���ݻ������ע����������ע����
 * Ŀǰ֧���������͵�ע�᣺ע��Ϊ��ʽ�桢ע��Ϊ���ð�
 * ע�����ǰ20λΪ���ݻ������ע���������ɵ�ע���룬��21λ����REG_TIME_LENGTHλ����ע��ʱ��
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
		printf("%s : ע�����ʹ���!\n", regCode);
	}
}

int main(int argc, char **argv)
{
	printf("��������������������������������������������������������������\n");
	printf("������%sע�������\n", APP_NAME);
	printf("������1.ע�����ð�(��2016-5-9)\t\t\n");
	printf("������2.ע�����ð�(����30��)  \t\t\n");
	printf("������3.ע����ʽ�桡����������\t\t\n");
	printf("��������������������������������������������������������������\n");
	printf("> ������ѡ����Ų����س���ȷ��:\n");
	int s;
	scanf_s("%d", &s);
	printf("> �������ע��Ļ����벢���س���ȷ��:\n");
	char machineCode[ARRAY_SIZE];
	char regCode[ARRAY_SIZE];
	memset(machineCode, 0, ARRAY_SIZE);
	memset(regCode, 0, ARRAY_SIZE);
	scanf("%s", machineCode);
	reg(machineCode, regCode, s);
	// ���ע����
	printf("---------------------------------\n");
	switch (s) {
		case 1:
			printf("> ע�����ð����(������2016-5-9)\n");
			break;
		case 2:
			printf("> ע�����ð����(����30��)\n");
			break;
		case 3:
			printf("> ע����ʽ�����\n");
			break;
		default:
			break;
	}
	printf("> �����룺%s\n", machineCode);
	printf("> ע���룺%s\n", regCode);
	printf("---------------------------------\n");	
	FILE* f = fopen("emxRegCode.txt", "a");
	if (f != NULL)
	{
		fprintf(f, "---------------------------------\n");
		switch(s) {
			case 1:
				fprintf(f, "> ע�����ð����(������2016-5-9)\n");
				break;
			case 2:
				fprintf(f, "> ע�����ð����(����30��)\n");
				break;
			case 3:
				fprintf(f, "> ע����ʽ�����\n");
				break;
			default:
				break;
		}
		fprintf(f, "> �����룺%s\n", machineCode);
		fprintf(f, "> ע���룺%s\n", regCode);

		time_t temptime= time(0);
		fprintf(f, "> ����ʱ�䣺%s", ctime(&temptime));
		fprintf(f, "---------------------------------\n");
		fclose(f);
		printf("ע�����ѱ��浽emxRegCode.txt\n");
	}
	system("pause");
	return 0;
}