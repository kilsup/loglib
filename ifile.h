#ifndef IFILE_H
#define IFILE_H



#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>

enum Option {
	NEW,
	APPEND
};

class Ifile {
private:
	std::vector<std::string>	severity;
	std::vector<std::string>	filename;
	std::vector<std::ofstream>	fs;		// 각 fs를 최신 파일이름에 매칭해여줘야 함
public:
	Ifile(){}
	virtual ~Ifile() {}
	void initIfile();
	std::string filenamming(const int& severity);
	std::ofstream make_file(const int& severity, const int& option);
	void log_write(const int& severity, const std::string& buf);
	int fline_check();
};

#endif





#if 0
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

// file Interface 입력
// message, level

enum Option {
	NEW = 0,
	APPEND = 1,
};

class ifile {
public:
	virtual ~ifile() {}
	virtual void log_write(const std::string& buf) = 0;

};

class file : public ifile {
private:
	int severity;
	std::string filename;
	std::ofstream fs;
public:

	file(const int& level) : severity(level) {}
	bool fsize_check();
	void filenamming(const int& severity);
	void make_file(const int& o_option);
	void log_write(const std::string& buf) override;
};
#endif