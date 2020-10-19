#include <iostream>
#include <string>
#include <cstdio>
#include <time.h>
#include <iomanip>																	// cout ����

#define MAX_SEVERITIES 4															// Severity ����
#define LOG(severity) LOG_##severity												// LOG ��� ����
#define LOG_INFO	logprint(INFO		,__FILE__,__FUNCTION__,__LINE__)
#define LOG_WARNING logprint(WARNING	,__FILE__,__FUNCTION__,__LINE__)
#define LOG_ERROR	logprint(ERROR		,__FILE__,__FUNCTION__,__LINE__)
#define LOG_FATAL	logprint(FATAL		,__FILE__,__FUNCTION__,__LINE__)


enum Severity {
	INFO = 0,
	WARNING = 1,
	ERROR = 2,
	FATAL = 3
};

static const char* SeverityNames[MAX_SEVERITIES] = { "INFO","WARNING","ERROR","FATAL" };


class LogMessage {

	// ��� ���� //////////////////////////////////////////////////////////
private:
	std::string severity;												// INFO, WARNING, ERROR, FATAL
	std::string fileName;
	std::string funcName;
	int line;

public:

	// ���� / �Ҹ��� //////////////////////////////////////////////////////
	LogMessage(const std::string& s_, const char* fileName_,
		const char* funcName_, const int& line_)
		: severity(s_), fileName(fileName_),
		funcName(funcName_), line(line_) {
	}
	~LogMessage() {
	}

	// ��� ���� ��� /////////////////////////////////////////////////////
	std::string getSeverity() const { return severity; }
	std::string getFileName() const { return fileName; }
	std::string getFuncName() const { return funcName; }
	int getLine() const { return line; }


	// ��� �Լ�///////////////////////////////////////////////////////////
	// ���� �ؼ� ���� �� �ֵ��� ����
	void log_configuration() {

	}
	// Template Method ���ø��� ������ 
	void LogMessage_print() {
		time_stamp();
		severity_stamp();
		directory_stamp();
		function_stamp();
		line_stamp();
	}

	// ���� �Լ�
	void time_stamp() {
		
		time_t timer = time(NULL); // time_t ������ Ÿ�� ���� timer�� ���� �ð� ����
		struct tm t;				// tm ����ü Ÿ���� ��¥
		localtime_s(&t, &timer);
		// �ð� calibration
		t.tm_year += 1900;
		t.tm_mon += 1;

		std::cout << "[" << t.tm_year << "-" << t.tm_mon << "-" << t.tm_mday << " ";
		std::cout << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << "] ";
	}

	void severity_stamp() {
		std::cout << "[" << getSeverity() << "] ";
	}

	void directory_stamp() {
		std::cout << "[directory : " << getFileName() << "] ";
	}

	void function_stamp() {
		std::cout << "[function : " << getFuncName() << "] ";
	}

	void line_stamp() {
		std::cout << "[line : " << getLine() << "]  " << std::endl;
	}
	// log_comment ���ʹ� severity ���� �ٸ���
	virtual void log_comment() = 0;
	
};

class InfoMessage : public LogMessage{
	// ��� ���� //////////////////////////////////////////////////////////

public:
	// ���� / �Ҹ��� //////////////////////////////////////////////////////
	InfoMessage(const std::string& s_, const char* fileName_, const char* funcName_, const int& line_)
		: LogMessage(s_, fileName_, funcName_, line_){}
	~InfoMessage() {}
	
	// ��� ���� ��� /////////////////////////////////////////////////////
	
	// ��� �Լ�///////////////////////////////////////////////////////////
	void log_comment() override {

	}
};



void logprint(const int& s, const char* fileName_, const char* funcName_, const int& line_){
	LogMessage* m = new InfoMessage(SeverityNames[s], fileName_, funcName_, line_);
	m->LogMessage_print();
}




int main() {

	while(1)
	{
		LOG(INFO);			getchar();
		LOG(WARNING);		getchar();
		LOG(ERROR);			getchar();
		LOG(FATAL);			getchar();
	}	
}