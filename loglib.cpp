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

		// �ڡڡڡڡ� ��Ī �ʿ� ! sum�� ���ڰ� �ؾ���.....

		


		iff.log_write(s, sum);
	}
};

log_init m;		// �ڡڡڡڡ� ��Ī �ʿ� !������ ���־���
				// ���� �� ���� ! �����ڴ� �ѹ��� ȣ��ǵ��� �ϰ� sum_print

// �ڡڡڡڡ� ��Ī �ʿ� ! �Լ��� �����ϳ�........

void logprint(const int& s, const char* fileName_,
	const char* funcName_, const int& line_, std::string mes)	
{
	std::cout << "const int& s : " << s << std::endl;
	m.sum_print(s, fileName_, funcName_, line_, mes);
}

