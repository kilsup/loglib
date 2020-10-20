#include "ifile.h"

// File Interface »Æ¿Œ
#if 1
class lllllog {
public:
	lllllog() {}

	void print(std::string mes) {
		std::cout << "print in" << std::endl;
		file f(1);
		f.make_file(1);
		f.log_write(mes);
		std::cout << "print out" << std::endl;
	}

};

int main() {
	lllllog m;
	
	m.print("Warning message");
}

#endif