#include "loglib.h"


int main() {

    loggingStart();


    LOG_INFO("Info test");
    LOG_WARNING("Warning test");
    LOG_ERROR("Error test");
    LOG_FATAL("Fatal test");


    Log::destroy();
}