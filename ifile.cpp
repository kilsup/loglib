#include "ifile.h"
#include "loglib.h"
#include "setting.h"

void IFile::initIfile()
{
	if (sev.empty()) {
		sev.push_back(INFO);
		sev.push_back(WARNING);
		sev.push_back(ERROR);
		sev.push_back(FATAL);
	}

	for (int i = 0; i < sev.size(); i++) {
		severity.push_back(seveArray[sev[i]]);
		filename.push_back(fNaming(sev[i]));
		fs.push_back(makeFile(sev[i], 0));
	}
}

std::string IFile::fNaming(const int& severity) {

	std::string name;

	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	std::string date = std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday) + std::to_string(t->tm_hour) + std::to_string(t->tm_min) + std::to_string(t->tm_sec);

	if (!dir.empty())
		name += dir;

	name += "log_";
	switch (severity)
	{
	case(INFO): name += "INFO";		break;
	case(WARNING): name += "WARNING";	break;
	case(ERROR): name += "ERROR";		break;
	case(FATAL): name += "FATAL";		break;
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
	std::string compare;
	if (!dir.empty())
		compare += dir;
	compare += "log_" + severity[fIndex] + std::to_string(t->tm_year + 1900) + std::to_string(t->tm_mon + 1)
		+ std::to_string(t->tm_mday);

	return 	filename[fIndex] < compare ? true : false;
}