
#include "ifile.h"
#include "loglib.h"
#include <fstream>

void ifile::filenamming() {
	std::cout << "file namming..." << std::endl;

	time_t timer = time(NULL);  // time_t ������ Ÿ�� ���� timer�� ���� �ð� ����
	struct tm* t = localtime(&timer);				// tm ����ü Ÿ���� ��¥
	//localtime_s(&t, &timer);
	// �ð� calibration


	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);
	filename[severity] += "log_";
	switch (severity)
	{
	case(INFO): filename[severity] += "info";		break;
	case(WARNING): filename[severity] += "WARNING";	break;
	case(ERROR): filename[severity] += "ERROR";		break;
	case(FATAL): filename[severity] += "FATAL";		break;
	case(DEBUG): filename[severity] += "DEBUG";		break;
	default:
		std::cout << "filenameing error" << std::endl;
		break;
	}

	filename[severity] += date;
	filename[severity] += ".log";
	std::cout << "filename" << std::endl;
}

void ifile::make_file() {
	std::cout << "make_file..." << std::endl;
	// ���� ���� / ������ Ȯ��

	switch (option){
	case(NEW):		fs[severity].open(filename, std::ios_base::trunc);
	case(APPEND):	fs[severity].open(filename, std::ios_base::app);
	}
	std::cout << "make_file_exit" << std::endl;
}

void ifile::log_write(const std::string& buf) {
	fs[severity] << buf << std::endl;
}


bool ifile::fsize_check() {
	char over = 0;
	int size = 0;
	std::ifstream ifs;

	if (ifs.is_open() == 0)
		printf("\n\n������ �������� �ʽ��ϴ�.n\n");
	ifs.seekg(0, std::ios::end);
	size = ifs.tellg();

	return over;		// ������ ���ų� �뷮�� ������ 0
						// ������ �ִµ� �뷮�� ũ��   1
}





#if 0
#include "ifile.h"
#include "loglib.h"
#include <fstream>

void file::make_file(const int& o_option) {
	std::cout << "make_file..." << std::endl;
	// ���� ���� / ������ Ȯ��
	if (fsize_check())
		std::cout << "�뷮 �ʰ�" << std::endl;
	else
		std::cout << "���� ����" << std::endl;
	// ���� �̸� �����

	filenamming(severity);

	switch (o_option)
	{
	case(NEW):		fs.open(filename, std::ios_base::trunc);
	case(APPEND):	fs.open(filename, std::ios_base::app);
	}
}

void file::log_write(const std::string& buf) {
	fs << buf << std::endl;
}


bool file::fsize_check() {
	char over = 0;
	int size = 0;
	std::ifstream ifs;

	if (ifs.is_open() == 0)
		printf("\n\n������ �������� �ʽ��ϴ�.n\n");
	ifs.seekg(0, std::ios::end);
	size = ifs.tellg();

	return over;		// ������ ���ų� �뷮�� ������ 0
						// ������ �ִµ� �뷮�� ũ��   1
}


void file::filenamming(const int& severity) {
	std::cout << "file namming..." << std::endl;
	time_t timer = time(NULL);  // time_t ������ Ÿ�� ���� timer�� ���� �ð� ����
	struct tm *t = localtime(&timer);				// tm ����ü Ÿ���� ��¥
	//localtime_s(&t, &timer);
	// �ð� calibration


	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
						+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);
	filename += "log_";
	switch(severity)
	{
	case(INFO)		: filename += "info";		break;
	case(WARNING)	: filename += "WARNING";	break;
	case(ERROR)		: filename += "ERROR";		break;
	case(FATAL)		: filename += "FATAL";		break;
	case(DEBUG)		: filename += "DEBUG";		break;
	default:
		std::cout << "filenameing error" << std::endl;
		break;
	}

	filename += date;
	filename += ".log";
}

#endif