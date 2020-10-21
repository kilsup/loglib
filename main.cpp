#include "ifile.h"
#include "loglib.h"
#include <vector>
#include <string>

int main() {
	for (int i = 0; i < 100; i++) {
		LOG_INFO("Info test");
		LOG_WARNING("Warning test");
		LOG_ERROR("Error test");
		LOG_FATAL("Fatal test");
	}
}