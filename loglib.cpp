#include <iostream>
#include <string>
#include <cstdio>
#include <time.h>

#define MAX_SEVERITIES 4															// Severity ����
#define LOG(severity) LOG_##severity												// LOG ��� ����
#define LOG_INFO	logprint("INFO"		,__FILE__,__FUNCTION__,__LINE__)
#define LOG_WARNING logprint("WARNING"	,__FILE__,__FUNCTION__,__LINE__)
#define LOG_ERROR	logprint("ERROR"	,__FILE__,__FUNCTION__,__LINE__)
#define LOG_ERROR	logprint("FATAL"	,__FILE__,__FUNCTION__,__LINE__)


enum Severity {
	INFO = 0,
	WARNING = 1,
	ERROR = 2,
	FATAL = 3
};

static const char* SeverityNames[MAX_SEVERITIES] = { "INFO","WARNING","ERROR","FATAL" };


class LogMessage {
private:
	std::string severity;												// INFO, WARNING, ERROR, FATAL
	std::string fileName;
	std::string funcName;
	int line;


public:
	LogMessage(const std::string & s_, const char* fileName_,
			   const char* funcName_, const int& line_)
		: severity(s_), fileName(fileName_),
		  funcName(funcName_), line(line_) {
	}
	~LogMessage() {
	}

	std::string getSeverity() const { return severity; }
	std::string getFileName() const { return fileName; }
	std::string getFuncName() const { return funcName; }
	int getLine() const { return line; }
	
	virtual void log_print(tm& t) = 0;
	
};

class InfoMessage : public LogMessage{
public:
	InfoMessage(const std::string& s_, const char* fileName_, const char* funcName_, const int& line_)
		: LogMessage(s_, fileName_, funcName_, line_){}
	~InfoMessage() {}

	void log_print(tm& t) override {
		std::cout << "[" << t.tm_year << "-" << t.tm_mon << "-" << t.tm_mday << " ";
		std::cout << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << "] ";
		std::cout << "[" << getSeverity() << "] ";
		std::cout << "[directory : " << getFileName() << "] ";
		std::cout << "[function : " << getFuncName() << "] ";
		std::cout << "[line : "	   << getLine()		 << "]  " << std::endl;
	}
};

void logprint(const std::string& s_, const char* fileName_, const char* funcName_, const int& line_){
	
	// �ð� ����
	time_t timer = time(NULL); // time_t ������ Ÿ�� ���� timer�� ���� �ð� ����
	struct tm t;				// tm ����ü Ÿ���� ��¥
	localtime_s(&t, &timer);
	// �ð� calibration
	t.tm_year += 1900;
	t.tm_mon += 1;
	// 
	LogMessage* m = new InfoMessage(s_, fileName_, funcName_, line_);
	m->log_print(t);
}




int main() {
	LOG(INFO);
}