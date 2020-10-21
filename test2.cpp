#include <iostream>
#include <string>
// STL에는 범용 함수 포인터 클래스가 타입이 존재합니다.
#include <functional>
#include <vector>

class BaseMenu {
    std::string title;
public:
    BaseMenu(const std::string& s) : title(s) {}
    std::string getTitle() const { return title; }

    virtual void command() = 0;
};

class MenuItem : public BaseMenu {
    std::function<void()> handler;
public:
    MenuItem(const std::string& s) : handler(nullptr), BaseMenu(s) {}


    void setHandler(std::function<void()> h) {
        handler = h;
    }

    void command() override {
        handler();
        getchar();
        getchar();
    }
};

class PopupMenu : public BaseMenu {
    std::string title;
    std::vector<BaseMenu*> v;
public:
    PopupMenu(const std::string& s) : BaseMenu(s) {}

    void addMenu(BaseMenu* p) { v.push_back(p); }

    void command() override {
        while (1) {
            system("cls");
            std::cout << "============================" << std::endl;
            std::cout << "< Log library Configuraion >" << std::endl;
            std::cout << "============================" << std::endl;
            int len = v.size();
            for (int i = 0; i < len; ++i) {
                std::cout << "  "  << i + 1 << ". " << v[i]->getTitle() << std::endl;
            }
            std::cout << "  " << len + 1 << ". Upper Menu" << std::endl;

            int cmd;
            std::cout << "<<";
            std::cin >> cmd;
            if (cmd == len + 1)
                break;

            v[cmd - 1]->command();
        }
    }
};

void readMe() {

    std::cout << "[1. 로그사용 방법 확인] " << std::endl;
    std::cout << " - https://github.com/kilsup/loglib/ 접속. " << std::endl;
    std::cout << " - Code Down" << std::endl;
    std::cout << " - Zip 파일 해제 하여 4개 파일 < ifile.cpp, ifile.h, loglib.cpp, loglib.h >을 프로젝트 경로에 추가" << std::endl;
    std::cout << " - loglib.h headerfile 추가 " << std::endl;
    std::cout << " - 원하는 위치에 아래와 같은 방법으로 로깅 " << std::endl;
    std::cout << "    LOG_INFO(“message”);" << std::endl;
    std::cout << "    LOG_WARNING(“message”);" << std::endl;
    std::cout << "    LOG_ERROR(“message”);" << std::endl;
    std::cout << "    LOG_FATAL(“message”);" << std::endl;
   
}

void severitySetting() {
    std::vector<int> sev;
    int cmd;
    std::cout << "[2.1 Severity Setting] " << std::endl;
    std::cout << " - 0. INFO" << std::endl;
    std::cout << " - 1. WARNING" << std::endl;
    std::cout << " - 2. ERROR" << std::endl;
    std::cout << " - 3. FATAL" << std::endl;
    std::cout << "<<";
    std::cin >> cmd;


}

void fDirSetting() {
    std::string dir;
    std::cout << "Input the directory address : ";
    std::cout << "<<";
    std::cin >> dir;
    std::cout << dir << std::endl;
}

int main() {
    PopupMenu* root = new PopupMenu("ROOT");
     

    MenuItem m1("How to use Log Library README!!!");
    m1.setHandler(&readMe);
    root->addMenu(&m1);

    PopupMenu* p1 = new PopupMenu("Log Library Setting");
    root->addMenu(p1);

    MenuItem m2("Severity Setting");
    m2.setHandler(&severitySetting);
    p1->addMenu(&m2);
    

    MenuItem m3("File Directory Setting");
    m3.setHandler(&fDirSetting);
    p1->addMenu(&m3);

    root->command();
}