#include "ifile.h"

void makeFile::log_write(const std::string buf) {
	fs << buf << std::endl;
}

bool makeFile::fsize_check() {
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


void makeFile::filenamming() {

	time_t timer = time(NULL);  // time_t ������ Ÿ�� ���� timer�� ���� �ð� ����
	struct tm t;				// tm ����ü Ÿ���� ��¥
	localtime_s(&t, &timer);
	// �ð� calibration


	std::string date = std::to_string(t.tm_year + 1900) + std::to_string(t.tm_mon + 1) + std::to_string(t.tm_mday);
	filename += "log_";
	filename += "info";
	filename += date;
}