
#include "ifile.h"
#include "loglib.h"

void Ifile::initIfile()
{
	severity.push_back("INFO");
	severity.push_back("WARNING");
	severity.push_back("ERROR");
	severity.push_back("FATAL");
	severity.push_back("DEBUG");
	
	filename.push_back(filenamming(0));
	//filename.push_back(filenamming(1));
	//filename.push_back(filenamming(2));
	//filename.push_back(filenamming(3));
	//filename.push_back(filenamming(4));

	fs.push_back(make_file(0, 0));	
	//fs.push_back(make_file(1, 0));
	//fs.push_back(make_file(2, 0));
	//fs.push_back(make_file(3, 0));
	//fs.push_back(make_file(4, 0));


}


std::string Ifile::filenamming(const int& severity) {

	std::string name;

	std::cout << "file namming..." << std::endl;

	time_t timer = time(NULL);  // time_t 데이터 타입 변수 timer에 현재 시각 저장
	struct tm* t = localtime(&timer);				// tm 구조체 타입의 날짜

	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);

	name += "log_";
	switch (severity)
	{
	case(INFO): name += "info";		break;
	case(WARNING): name += "WARNING";	break;
	case(ERROR): name += "ERROR";		break;
	case(FATAL): name += "FATAL";		break;
	case(DEBUG): name += "DEBUG";		break;
	default:
		std::cout << "filenameing error" << std::endl;
		break;
	}

	name += date;
	name += ".log";

	return name;

	std::cout << "filename" << std::endl;
}

std::ofstream Ifile::make_file(const int& severity, const int& option) {
	std::cout << "make_file..." << std::endl;
	// 파일 유무 / 사이즈 확인
	std::ofstream fp;
	/*
	switch (option)
	{
		case(NEW):		fp.open(filename[severity]);
		case(APPEND):	fp.open(filename[severity], std::ios_base::app);
	}*/
	fp.open(filename[severity]);
	std::cout << "make_file_exit" << std::endl;
	
	return fp;
}

void Ifile::log_write(const int& severity, const std::string& buf) {
	std::cout << "log_write In" << std::endl;
	fs[severity] << buf << std::endl;
	if (fline_check() > 100) {
		
		filename[severity] = filenamming(severity);
		fs[severity] = make_file(severity, 0);
	}
		
	std::cout << "log_write Out" << std::endl;
}

int Ifile::fline_check() {	
	int c = 0;
	std::string s;
	std::cout << "1" << std::endl;
	std::ifstream input(filename[0]);
	std::cout << "2" << std::endl;
	while (std::getline(input, s))
		c++;
	std::cout << "c : " << c << std::endl;
	return c;
}





#if 0
#include "ifile.h"
#include "loglib.h"
#include <fstream>

void file::make_file(const int& o_option) {
	std::cout << "make_file..." << std::endl;
	// 파일 유무 / 사이즈 확인
	if (fsize_check())
		std::cout << "용량 초과" << std::endl;
	else
		std::cout << "파일 생성" << std::endl;
	// 파일 이름 만들기

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
		printf("\n\n파일이 존재하지 않습니다.n\n");
	ifs.seekg(0, std::ios::end);
	size = ifs.tellg();

	return over;		// 파일이 없거나 용량이 작으면 0
						// 파일이 있는데 용량이 크면   1
}


void file::filenamming(const int& severity) {
	std::cout << "file namming..." << std::endl;
	time_t timer = time(NULL);  // time_t 데이터 타입 변수 timer에 현재 시각 저장
	struct tm *t = localtime(&timer);				// tm 구조체 타입의 날짜
	//localtime_s(&t, &timer);
	// 시간 calibration


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