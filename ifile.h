#ifndef IFILE_H
#define IFLIE_H
#include <string>
#include <fstream>

// file Interface ют╥б
// message, level

#define APPEND std::ios_base::app
#define OUTPUT APPEND


class ifile {
public:	
	virtual void log_write(const std::string buf) = 0 ;
};

class infoFile : public ifile {
private:
	std::ofstream info;
public:
	infoFile() {
		info.open("info.txt", OUTPUT);
	}

	virtual void log_write(const std::string buf);

};

#endif