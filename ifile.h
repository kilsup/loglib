#ifndef IFILE_H
#define IFILE_H
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

// file Interface ют╥б
// message, level

enum Option {
	NEW = 0,
	APPEND = 1,
};

class ifile {
public:
	virtual void log_write(const std::string& buf) = 0 ;
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