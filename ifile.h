#ifndef IFILE_H
#define IFILE_H
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

// file Interface �Է�
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

		// ���� ���� / ������ Ȯ��
		if (fsize_check())
			std::cout << "�뷮 �ʰ�" << std::endl;
		// ���� �̸� �����

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