#ifndef LOGLIB_H
#define LOGLIB_H

#include <iostream>
#include <fstream>
#include "Ifile.h"
#define MAX_SEVERITIES 5

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

class Log {
private:
	IFile iFileInterface;

	Log() {
		iFileInterface.initIfile();
		std::cout << "File Interface Initialized !!!" << std::endl;
		std::cout << "File Printed !!!" << std::endl;
	}

	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;

	static Log* instance;

protected:
	std::vector<std::string> seveArray = { "INFO", "WARNING", "ERROR", "FATAL", "DEBUG" };
public:
	static Log& getInstance() {
		if (instance == nullptr)
			instance = new Log;
		return *instance;
	}

	void sumPrint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes);
};

void logPrint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes);

#endif