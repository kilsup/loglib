
#include "ifile.h"
#include "loglib.h"
#include <iostream>


void IFile::initIfile()
{
	int num;

	
	while (1) {
		std::cout << "< LOG Initialization >" << std::endl;
		std::cout << "Severity (1.INFO, 2.WARNING, 3.ERROR, 4.FATAL, 5.DEBUG) / 9.confirm : ";
		std::cin >> num;

		if (num > 0 && num < 5) {
			severity.push_back(seve[num - 1]);
			filename.push_back(filenamming(num - 1));
			fs.push_back(make_file(num - 1, 0));
		}
		else if (num == 9)
			break;
		else
			continue;
		system("cls");
	}
}


std::string IFile::filenamming(const int& severity) {

	std::string name;

	//std::cout << "file namming..." << std::endl;

	time_t timer = time(NULL); 
	struct tm* t = localtime(&timer);

	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);

	name += "log_";
	switch (severity)
	{
	case(INFO): name += "INFO";		break;
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

	//std::cout << "file namming...<done>" << std::endl;

	return name;

	
}

std::ofstream IFile::make_file(const int& severity, const int& option) {
	std::ofstream fp;
	/*
	switch (option)
	{
		case(NEW):		fp.open(filename[severity]);
		case(APPEND):	fp.open(filename[severity], std::ios_base::app);
	}*/
	fp.open(filename.back());
	
	return fp;
}

void IFile::log_write(const int& index, const std::string& buf) {
	
	auto search = std::find(severity.begin(), severity.end(), seve[index]);
	
	if (search == severity.end())
	{
		std::cout << "passssssssssssssssss" <<std::endl;
		return;
	}
	auto findIndex = search - severity.begin();


	fs[findIndex] << buf << std::endl;


	if (fline_check(findIndex) > 1) {
		
		filename[findIndex] = filenamming(findIndex);
		fs[findIndex] = make_file(findIndex, 0);
	}

}

int IFile::fline_check(const int& fIndex) {	
	int c = 0;
	std::string s;
	std::ifstream input(filename[fIndex]);

	while (std::getline(input, s))
		c++;
	std::cout << "c : " << c << std::endl;
	return c;
}