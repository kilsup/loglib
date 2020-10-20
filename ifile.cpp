#include "ifile.h"

void log_write(const std::string buf) override
{
	info << buf << std::endl;
}