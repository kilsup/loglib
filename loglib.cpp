#include <iostream>
#include <string>
#include <cstdio>

class LogMessage {
private:
	std::string msg;												// DEBUG, INFO, WARN, ERROR, FATAL
protected:
	FILE* fp;
public:
	LogMessage(const std::string& s) : msg(s), fp(nullptr){
		std::cout << "fopen" << std::endl;
		fopen_s(&fp,"output.txt", "w");
	}
	~LogMessage() {
		fclose(fp);
	}

	std::string getMessage() const { return msg; }
	
	virtual std::string LOG(const std::string& s) = 0;
	
};

class WMessage : public LogMessage{
private:

public:
	WMessage(const std::string& s) : LogMessage(s){}
	~WMessage() {}
	std::string LOG(const std::string& s) {
		std::cout << s << std::endl;
		fprintf(fp, "%s \n",(std::string)s);
		return s;
	}
};

int main() {

	WMessage *m1 = new WMessage("LOG");
	m1->LOG("error");
}