#ifndef LOGLIB_H
#define LOGLIB_H

#include <iostream>
#include <fstream>
#include "userlog.h"
#include "Ifile.h"
#define MAX_SEVERITIES 4															// Severity 개수


//////////////////////////////////// User Log Format ///////////////////////////////////////////

#define LOG_INFO(message)		logprint(INFO	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_WARNING(message)	logprint(WARNING,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_ERROR(message)		logprint(ERROR	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_FATAL(message)		logprint(FATAL	,__FILE__,__FUNCTION__,__LINE__, message)

////////////////////////////////////////////////////////////////////////////////////////////////

enum Severity {
	INFO	= 0,
	WARNING = 1,
	ERROR	= 2,
	FATAL	= 3,
	DEBUG   = 4
};


class log {
public:
	// 초기화 Interface와 연결
	// 출력 Interface와 연결

};


void logprint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes);

#endif