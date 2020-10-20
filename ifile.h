#ifndef IFILE_H
#define IFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

#define MAX_SEVERITIES 4

// file Interface �Է�
// message, level

enum Option {
	NEW = 0,
	APPEND = 1,
};

class ifile {
private:
	int option;
protected:
	std::string filename[MAX_SEVERITIES];	// �ֽ� �����̸����� �ٲ������
	std::ofstream fs[MAX_SEVERITIES];		// �� fs�� �ֽ� �����̸��� ��Ī�ؿ���� ��
public:
	ifile() : option() {}
	virtual ~ifile() {}
	void filenamming();
	void make_file();
	bool fsize_check();
	void log_write(const std::string& buf);
};
#endif





#if 0
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