#include "setting.h"
// STL에는 범용 함수 포인터 클래스가 타입이 존재합니다.
std::vector<int> sev;
std::string dir;

void readMe() {

    std::cout << "\n[1. How to use Log Library README!!!] " << std::endl;
    std::cout << " - https://github.com/kilsup/loglib/ 접속. " << std::endl;
    std::cout << " - Code Down" << std::endl;
    std::cout << " - Zip 파일 해제 하여 6개 파일 " << std::endl;
    std::cout << "< ifile.cpp, ifile.h, loglib.cpp, loglib.h, setting.cpp, setting.h>을 프로젝트 경로에 추가" << std::endl;
    std::cout << " - loglib.h headerfile 추가 " << std::endl;
    std::cout << " - 원하는 위치에 아래와 같은 방법으로 로깅 " << std::endl;
    std::cout << "    LOG_INFO(“message”);" << std::endl;
    std::cout << "    LOG_WARNING(“message”);" << std::endl;
    std::cout << "    LOG_ERROR(“message”);" << std::endl;
    std::cout << "    LOG_FATAL(“message”);" << std::endl;
    getchar();
    getchar();
}

void severitySetting() {
    int cmd;
    std::cout << "\n[2.1 Severity Setting] " << std::endl;
    std::cout << " - 0. INFO" << std::endl;
    std::cout << " - 1. WARNING" << std::endl;
    std::cout << " - 2. ERROR" << std::endl;
    std::cout << " - 3. FATAL" << std::endl;
    std::cout << "<<";

    do {
        std::cin >> cmd;
        sev.push_back(cmd);
    } while (getc(stdin) == ' ');
}

void fDirSetting() {
    std::cout << "Input the directory address : ";
    std::cout << "<<";
    std::cin >> dir;
    std::cout << dir << std::endl;
}