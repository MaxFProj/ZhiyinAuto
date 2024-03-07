#ifndef EMXCODEREGISTER_H
#define EMXCODEREGISTER_H
#include <QString>
#include <QObject>
#include <QDateTime>
#include "emxMessageHandler.h"
#include <ctime>
#include <cstdio>
#define REG_TIME_LENGTH 6


// typedef unsigned long       DWORD;
// typedef const char*        LPCSTR; 
struct tm;
class QSettings;
class emxRegisterDialog;
class emxCodeRegister:public QObject
{
	Q_OBJECT
public:
	emxCodeRegister(emxMessageHandler * handle = nullptr, emxRegisterDialog * dialog = nullptr);
	~emxCodeRegister();
	bool RegisterAndValidate();
	void setRegisterDialog(emxRegisterDialog * dialog);
	bool GenerateVolumeInfo(QString& RegID, QString& TrialRegID, QString& LimitedRegID, QString& FullRegID);
// 	bool FullRegisterAndValidate(QSettings& setting, QString& RegID, QString& TrialRegID, QString& LimitedRegID, QString& FullRegID);
// 	bool FullRegisterAndValidate(QSettings& setting, QString& RegID, QString& LimitedRegID, QString& FullRegID);
	bool FullRegisterAndValidate(QString& RegID, QString& TrialRegID,QString& LimitedRegID, QString& FullRegID);
	QString GetRegID(QString& RegID, QString& TrialRegID, QString& LimitedRegID, QString& FullRegID);
private:
	char SumToChar(unsigned char a, unsigned char b);
	void RegIDToTrial(char regID[21], char trialRegID[21]);
	void RegIDToLimited(char regID[21], char limitedRegID[21]);
	void RegIDToFull(char regID[21], char fullRegID[21]);
	bool DecodeRegCode(char regCode[255], char codeGenID[255], time_t& codeGenTime);
	unsigned char CharToHex(unsigned char ch);
	void GetCurrentRegTime(char regTime[255]);
	struct tm regTimeStr2TM(char regTime[REG_TIME_LENGTH]);
	bool isCodeGenTimeValid(time_t regTime);
	void getCurrentDateTime(char regTime[255]);
	bool IsValidTime(QString& RegTime);
	time_t getLicenseEndTime(time_t regTime);
	bool timeCheatCheck(QSettings& setting);
	time_t decodeCurrentDateTime(char regTime[255]);
	bool isValidRunTime(time_t t);
	time_t buildTimestamp();
private:
	FILE* regFile;
	emxMessageHandler *m_handle;
	int regType;
	emxRegisterDialog* m_registerDialog;
	static const time_t EMX_BUILD_TIME = 1401033500;//2014-05-26 = 1357401600; //±‡“Î»’∆⁄2013-01-06
// 	bool GetAdapterInfo(int adapter_num, QString &mac_addr);
// 	char SumToChar(unsigned char a, unsigned char b);
// 	QString GenerateRegId(QString mac);
// 	unsigned char CharToHex(unsigned char ch);
// 	void RegIDToTrial(char regID[21], char trialRegID[21]);
// 	void RegIDToLimited(char regID[21], char limitedRegID[21]);
// 	void RegIDToFull(char regID[21], char fullRegID[21]);
// 	
// 	void GetCurrentRegTime(char regTime[255]);
// 	bool IsValidTime(QString& RegTime);
// 	
// 	bool FullRegisterAndValidate(CRegKey& processReg, CRegKey& timeReg, QString& RegID, QString& TrialRegID, QString& LimitedRegID, QString& FullRegID);
// 	bool FullRegisterAndValidate(CRegKey& processReg, CRegKey& timeReg, QString& RegID, QString& LimitedRegID, QString& FullRegID);
// //////////////////////////////////////////////////////////////////////////
// 	void getCurrentDateTime(char regTime[255]);
// 	time_t decodeCurrentDateTime(char regTime[255]);
// 	bool registerLicense();
// 	time_t getLicenseEndTime(time_t regTime);
// 	bool isValidRunTime(time_t t);
// 	bool timeCheatCheck(CRegKey &timeReg);
// 	bool DecodeRegCode(char regCode[255], char codeGenID[255], time_t& codeGenTime);
};
#endif // !EMXCODEREGISTER_H
