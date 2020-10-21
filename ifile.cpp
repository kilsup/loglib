#include "ifile.h"
#include "loglib.h"

void IFile::initIfile()
{
	int num;
	
	while (1) {
		std::cout << "< LOG Initialization >" << std::endl;
		std::cout << "Severity (1.INFO, 2.WARNING, 3.ERROR, 4.FATAL, 5.DEBUG) / 9.confirm : ";
		std::cin >> num;

		if (num > 0 && num < 5) {
			severity.push_back(seveArray[num - 1]);
			filename.push_back(fNaming(num - 1));
			fs.push_back(makeFile(num - 1, 0));
		}
		else if (num == 9)
			break;
		else
			continue;
		system("cls");
	}
}

std::string IFile::fNaming(const int& severity) {

	std::string name;

	time_t timer = time(NULL); 
	struct tm* t = localtime(&timer);

	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);

	name += "log_";
	switch (severity)
	{
	case(INFO): name += "INFO";		break;
	case(WARNING): name += "WARNING";	break;
	case(ERROR): name += "ERROR";		break;
	case(FATAL): name += "FATAL";		break;
	case(DEBUG): name += "DEBUG";		break;
	default:
		std::cout << "filenameing error" << std::endl;
		break;
	}

	name += date;
	name += ".log";

	return name;	
}

std::ofstream IFile::makeFile(const int& severity, const int& option) {
	std::ofstream fp;
	fp.open(filename.back());
	return fp;
}

void IFile::logWrite(const int& index, const std::string& buf) {
	
	auto search = std::find(severity.begin(), severity.end(), seveArray[index]);
	
	if (search == severity.end())	return;
	auto findIndex = search - severity.begin();

	fs[findIndex] << buf << std::endl;

	if (fLineCheck(findIndex) > MAX_LINE || fDateCheck(findIndex)) {
		
		filename[findIndex] = fNaming(findIndex);
		fs[findIndex] = makeFile(findIndex, 0);
	}

}

int IFile::fLineCheck(const int& fIndex) {	
	int c = 0;
	std::string s;
	std::ifstream input(filename[fIndex]);
	
	while (std::getline(input, s))
		c++;
	return c;
}

bool IFile::fDateCheck(const int& fIndex) {
	


	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	std::string compare = "log_" + severity[fIndex] + std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday);

	return 	filename[fIndex] < compare ? true : false;	
}