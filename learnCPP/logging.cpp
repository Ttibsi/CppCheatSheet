// To run this, use the -I flag to point to a local clone of https://github.com/SergiusTheBest/plog
// pointing to the include directory
#include <iostream>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

int main() {
    plog::init(plog::debug, "log.txt"); // Initialise logger
    PLOGD << "Error msg"; // Write to logging file
}
