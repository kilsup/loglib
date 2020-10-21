#include "ifile.h"
#include "loglib.h"
#include <vector>
#include <string>

int main() {

	for (int i = 0; i < 2; i++) {
		LOG_INFO("test");
		LOG_WARNING("test");
		LOG_ERROR("test");
		LOG_FATAL("test");
	}
}