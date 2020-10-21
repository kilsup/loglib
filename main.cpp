#include "ifile.h"
#include "loglib.h"
#include "setting.h"
#include <vector>
#include <string>



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

	for (int i = 0; i < 100; i++) {
		LOG_INFO("Info test");
		LOG_WARNING("Warning test");
		LOG_ERROR("Error test");
		LOG_FATAL("Fatal test");
	}
}