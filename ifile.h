#ifndef IFILE_H
#define IFILE_H
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
	virtual void log_write(const std::string& buf) = 0 ;
};

class makeFile : public ifile {
private:
	std::string filename;
	std::ofstream fs;
public:
	makeFile() {}
	makeFile(const int& o_option) {

		// 파일 유무 / 사이즈 확인
		if (fsize_check())
			std::cout << "용량 초과" << std::endl;
		// 파일 이름 만들기

		filenamming();

		switch (o_option)
		{
			case(NEW)	:	fs.open(filename, std::ios_base::trunc);
			case(APPEND):	fs.open(filename, std::ios_base::app);
		}		
	}
	void log_write(const std::string buf);
	bool fsize_check();
	void filenamming();
};

#endif