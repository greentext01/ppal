#include <iostream>

void error(std::string message, int exitStatus = 0) {
    std::cerr << message;
    exit(exitStatus);
}

void throwErrorIf(std::string errorMessage, bool condition) {
    if (condition) {
        error(errorMessage);
    }
}