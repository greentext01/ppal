#include <iostream>

void error(std::string message, int exitStatus = 0) {
    std::cerr << message;
    exit(exitStatus);
}

void throwErrorIf(bool condition, std::string errorMessage) {
    if (condition) {
        error(errorMessage);
    }
}