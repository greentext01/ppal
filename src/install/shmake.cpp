#include "shmake.h"

Shmake::Shmake(string fileName) {
    srand(time(NULL));
    outputFileName = "/tmp/.shmake-" + to_string(rand()) + ".sh";
    inputFileStream = ifstream(fileName);
    outputFileStream = ofstream(outputFileName);
    if (!inputFileStream.good()) {
        throw runtime_error("Error: no such file");
    }
    chmod(outputFileName.c_str(), S_IRWXU);
}

Shmake::~Shmake() {
    contents.clear();
    buffer.clear();
    inputFileStream.close();
    outputFileStream.close();
    remove(outputFileName.c_str());
}

void Shmake::readFile() {
    while (getline(inputFileStream, buffer)) {
        int index = buffer.find_first_not_of(' ');
        if (index != string::npos) {
            buffer = buffer.substr(index);
        }
        contents.push_back(buffer);
    }
    outputFileStream.close();
}

int Shmake::findTarget(string target) {
    for (int line = 0; line < contents.size(); line++) {
        string currentLine = contents[line];
        if (currentLine == ":" + target) {
            return line;
        }
    }
    throw runtime_error("Error: no such target");
}

void Shmake::execute(string target) {
    int targetLine = findTarget(target);
    for (int i = targetLine + 1; i < contents.size(); i++) {
        string currentLine = contents[i];
        switch (currentLine[0]) {
            case ';':
                outputFileStream << "echo \"--" << currentLine.substr(1)
                                 << "--\"\n";
                break;

            case ':':
                return;
                break;

            default:
                outputFileStream << currentLine.c_str() + string("\n");
                break;
        }
    }

    system(outputFileName.c_str());
}