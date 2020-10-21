#include "ifile.h"
#include "loglib.h"
#include <vector>
#include <string>

int main() {
		LOG_INFO("INFO");
		LOG_INFO("INFO");
		LOG_WARNING("WARNING");
		//LOG_ERROR("ERROR");
		//LOG_FATAL("FATAL");
}


#if 0
#define LOG(message)	logprint(INFO	,__FILE__,__FUNCTION__,__LINE__, message)	

enum Severity {
	INFO,
	WARNING,
	ERROR,
	FATAL,
	DEBUG
};


class logprintt {
	Ifile iff;
public:
	logprintt() {
		std::cout << "print in..." << std::endl;
		iff.initIfile();
		std::cout << "print out..." << std::endl;
	}

	void print(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes)
	{
		std::string sum;
		sum = "(INFO) ";
		//sum += fileName_;
		sum += "(func): ";
		sum += funcName_;
		sum += std::to_string(line_);
		sum += "      << ";
		sum += mes;

		iff.log_write(s, sum);
	}
};

logprintt m;		// 전역을 없애야함

void logprint(const int& s, const char* fileName_,
	const char* funcName_, const int& line_, std::string mes)
{	
	m.print(s, fileName_, funcName_, line_, mes);
}
/*
#if 1
// File Interface 확인
class logprint {
	Ifile iff;
public:
	logprint() {
		std::cout << "print in..." << std::endl;		
		iff.initIfile();
		std::cout << "print out..." << std::endl;
	}
	std::string sum_string(const std::string& mes) {
		//std:string s
		return "dd";
	}
	void print_f(const int& severity, const char* fileName_, const char* funcName_, const int& line_, std::string& mes) {
		
		iff.log_write(severity, sum_string(fileName_, funcName_, line_, mes));
	}

};
*/


int main() {
	
	for (int i = 0; i < 100; i++)
	{
		LOG("aaa");
	}
	

	//m.print_f(0, "Warning message");

}
#endif




#if 0
// File Interface 확인
class lllllog {
public:
	lllllog() {}

	void print(std::string mes) {
		std::cout << "print in" << std::endl;
		file f(1);
		f.make_file(1);
		f.log_write(mes);
		std::cout << "print out" << std::endl;
	}

};

int main() {
	lllllog m;
	
	m.print("Warning message");
}

#endif