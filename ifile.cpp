#include "ifile.h"

void makeFile::log_write(const std::string buf) {
	fs << buf << std::endl;
}

bool makeFile::fsize_check() {
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


void makeFile::filenamming() {

	time_t timer = time(NULL);  // time_t 데이터 타입 변수 timer에 현재 시각 저장
	struct tm t;				// tm 구조체 타입의 날짜
	localtime_s(&t, &timer);
	// 시간 calibration


	std::string date = std::to_string(t.tm_year + 1900) + std::to_string(t.tm_mon + 1) + std::to_string(t.tm_mday);
	filename += "log_";
	filename += "info";
	filename += date;
}