#include "loglib.h"
#include "Ifile.h"


class Log {

	IFile iFileInterface;

	Log() {		
		iFileInterface.initIfile();
		std::cout << "File Interface Initialized !!!" << std::endl;

		
	}

	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;

	static Log* instance;

protected:
	std::vector<std::string> seve = { "INFO", "WARNING", "ERROR", "FATAL", "DEBUG" };
public:
	static Log& getInstance() {
		if (instance == nullptr)
			instance = new Log;
		return *instance;
	}

	void sumPrint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes)
	{
		time_t timer = time(NULL);
		struct tm* t = localtime(&timer);
		char tBuf[512];
		char buf[512];

		sprintf(tBuf, "%d-%d-%d %d:%d:%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
		sprintf(buf, "[%s] [%s] [Location(function, line) : (%s, %d)]  << %s", tBuf, seve[s].c_str(),  funcName_, line_, mes.c_str());
		std::cout << buf << std::endl;
		std::string sum = std::string(buf);
		iFileInterface.log_write(s, sum);
	}
};
Log* Log::instance = nullptr;

void logPrint(const int& s, const char* fileName_,
	const char* funcName_, const int& line_, std::string mes)	
{	
	auto& c1 = Log::getInstance();
	c1.sumPrint(s, fileName_, funcName_, line_, mes);
}