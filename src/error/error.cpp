#include <iostream>

/**
 * @brief Print message to stderr
 *
 * @param message The message to print
 * @param exitStatus The exit status (defaults to 1)
 */
void error(std::string message, int exitStatus = 1) {
    std::cerr << message;
    exit(exitStatus);
}

/**
 * @brief Throw error if condtion is met
 *
 * @param condition The condition that needs to be met
 * @param errorMessage The message to be printed out to stderr
 */
void throwErrorIf(bool condition, std::string errorMessage) {
    if (condition) {
        error(errorMessage);
    }
}