#ifndef LOGLIB_H
#define LOGLIB_H

#include <iostream>
#include <fstream>
#include "Ifile.h"
#define MAX_SEVERITIES 5															// Severity ����


//////////////////////////////////// User Log Format ///////////////////////////////////////////

#define LOG_INFO(message)		logprint(INFO	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_WARNING(message)	logprint(WARNING,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_ERROR(message)		logprint(ERROR	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_FATAL(message)		logprint(FATAL	,__FILE__,__FUNCTION__,__LINE__, message)

////////////////////////////////////////////////////////////////////////////////////////////////

enum Severity {
	INFO,
	WARNING,
	ERROR,
	FATAL,
	DEBUG
};


class log {
public:
	// �ʱ�ȭ Interface�� ����
	// ��� Interface�� ����

};


void logprint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes);

#endif