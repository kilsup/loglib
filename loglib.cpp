#include "loglib.h"
#include "Ifile.h"


class log_init {
	Ifile iff;
protected:
	std::vector<std::string> seve = { "INFO", "WARNING", "ERROR", "FATAL", "DEBUG" };
public:
	log_init() {
		iff.initIfile();
		std::cout << "File Interface Initialized !!!" << std::endl;
	}

	void sum_print(const int& s, const char* fileName_, const char* funcName_, const int& line_, std::string mes)
	{
		std::string sum;
		sum = "(";
		sum += seve[s];
		sum += ") ";
		//sum += fileName_;
		sum += "(func : ";
		sum += funcName_;
		sum += ") ";
		sum += "(line : ";
		sum += std::to_string(line_);
		sum += ") ";
		sum += "      << ";
		sum += mes;

		// ★★★★★ 코칭 필요 ! sum을 예쁘게 해야함.....

		


		iff.log_write(s, sum);
	}
};

log_init m;		// ★★★★★ 코칭 필요 !전역을 없애야함
				// 전역 한 이유 ! 생성자는 한번만 호출되도록 하고 sum_print

// ★★★★★ 코칭 필요 ! 함수로 빼야하나........

void logprint(const int& s, const char* fileName_,
	const char* funcName_, const int& line_, std::string mes)	
{
	std::cout << "const int& s : " << s << std::endl;
	m.sum_print(s, fileName_, funcName_, line_, mes);
}

