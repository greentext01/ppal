#include <error.h>
#include <shmake.h>
#include <stdio.h>

#include <iostream>

/**
 * @brief Construct a new Shmake:: Shmake object
 *
 * @param fileName The Shmfile name (defaults to INSTALL)
 */
Shmake::Shmake(std::string fileName = "INSTALL") {
    // Create seed for random number generator
    srand(time(NULL));

    outputFileName = "/tmp/.shmake-" + std::to_string(rand()) + ".sh";
    inputFileStream = std::ifstream(fileName);
    outputFileStream = std::ofstream(outputFileName);
    if (!inputFileStream.good()) {
        throw std::runtime_error("Error: no such file");
    }
    // Make output file executable
    chmod(outputFileName.c_str(), S_IRWXU);
}

/**
 * @brief Destroy the Shmake:: Shmake object
 *
 */
Shmake::~Shmake() {
    contents.clear();
    buffer.clear();
    inputFileStream.close();
    outputFileStream.close();
    remove(outputFileName.c_str());
}

/**
 * @brief read file specified in constructor into ram
 *
 */
void Shmake::readFile() {
    // Read file line by line
    while (getline(inputFileStream, buffer)) {
        // Remove leading spaces
        int index = buffer.find_first_not_of(' ');
        if (index != std::string::npos) {
            buffer = buffer.substr(index);
        }
        contents.push_back(buffer);
    }
    outputFileStream.close();
}

/**
 * @brief Find the line a target is on
 *
 * @param target The name of the target
 * @return int The line the target is on
 */
int Shmake::findTarget(std::string target) {
    for (int line = 0; line < contents.size(); line++) {
        std::string currentLine = contents[line];
        if (currentLine == ":" + target) {
            return line;
        }
    }
    throw std::runtime_error("Error: no such target");
}

/**
 * @brief Execute the shell script under the specified target
 *
 * @param target The target to execute
 */
void Shmake::execute(std::string target) {
    int targetLine = findTarget(target);

    // Write a shell script
    for (int i = targetLine + 1; i < contents.size(); i++) {
        std::string currentLine = contents[i];

        // Wildcards
        switch (currentLine[0]) {
            case ';':
                outputFileStream << "echo \"--" << currentLine.substr(1)
                                 << "--\"\n";
                break;

            case ':':
                return;
                break;

                // End wildcards

            default:
                outputFileStream << currentLine.c_str() + std::string("\n");
                break;
        }
    }

    // Run the shell script
    system(outputFileName.c_str());
}