#ifndef ERROR_H
#define ERROR_H

#include <iostream>

void error(std::string message, int exitStatus = 0);
void throwErrorIf(bool condition, std::string errorMessage);

#endif