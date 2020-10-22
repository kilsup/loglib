#include "loglib.h"
#include "Ifile.h"

Log* Log::instance = nullptr;

void Log::sumPrint(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	char tBuf[512];
	char buf[512];

	sprintf(tBuf, "%d-%d-%d %d:%d:%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	sprintf(buf, "[%s] [%s] [%s, %d]  << %s", tBuf, seveArray[s].c_str(), funcName_, line_, mes.c_str());
	std::string sum = std::string(buf);
	iFileInterface.logWrite(s, sum);
}


void logPrint(const int& s, const char* fileName_,
	const char* funcName_, const int& line_, std::string mes)
{
	auto& c1 = Log::getInstance();
	c1.sumPrint(s, fileName_, funcName_, line_, mes);
}



void loggingStart() {

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

	system("cls");
}