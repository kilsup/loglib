#ifndef LOGLIB_H
#define LOGLIB_H

#include <iostream>
#include <fstream>
#include "Ifile.h"
#define MAX_SEVERITIES 5															// Severity °³¼ö


//////////////////////////////////// User Log Format ///////////////////////////////////////////

#define LOG_INFO(message)		logPrint(INFO	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_WARNING(message)	logPrint(WARNING,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_ERROR(message)		logPrint(ERROR	,__FILE__,__FUNCTION__,__LINE__, message)
#define LOG_FATAL(message)		logPrint(FATAL	,__FILE__,__FUNCTION__,__LINE__, message)

////////////////////////////////////////////////////////////////////////////////////////////////

enum Severity {
	INFO,
	WARNING,
	ERROR,
	FATAL,
	DEBUG
};


void logPrint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes);

#endif