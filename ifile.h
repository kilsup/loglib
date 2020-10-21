#ifndef IFILE_H
#define IFILE_H

#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>


#define MAX_LINE 100

enum Option {
	NEW,
	APPEND
};

class IFile {
private:
	std::vector<std::string>	seveArray = { "INFO", "WARNING", "ERROR", "FATAL", "DEBUG" };
	std::vector<std::string>	severity;		
	std::vector<std::string>	filename;		
	std::vector<std::ofstream>	fs;
public:
	IFile(){}
	virtual ~IFile() {}
	void initIfile();
	std::string fNaming(const int& severity);
	std::ofstream makeFile(const int& severity, const int& option);
	void logWrite(const int& severity, const std::string& buf);
	int fLineCheck(const int& fIndex);
	bool fDateCheck(const int& fIndex);
};

#endif