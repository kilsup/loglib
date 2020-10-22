#ifndef SETTING_H
#define SETTING_H
#include <functional>
#include <iostream>
#include <string>
#include <vector>

extern std::vector<int> sev;
extern std::string dir;

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
                std::cout << "  " << i + 1 << ". " << v[i]->getTitle() << std::endl;
            }
            std::cout << "  " << len + 1 << ". Upper Menu" << std::endl;

            int cmd;
            std::cout << "<<";
            std::cin >> cmd;
            if (cmd == len + 1)
                break;
            if (cmd > len + 1 || cmd < 1)
                continue;

            v[cmd - 1]->command();
        }
    }
};

void readMe();
void severitySetting();
void fDirSetting();

#endif
