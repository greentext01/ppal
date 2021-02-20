#ifndef SHMAKE_H
#define SHMAKE_H

#include <stdio.h>
#include <sys/stat.h>

#include <fstream>
#include <iostream>
#include <vector>

class Shmake {
   private:
    std::string buffer;
    std::string outputFileName;
    std::vector<std::string> contents;
    std::ifstream inputFileStream;
    std::ofstream outputFileStream;
    int findTarget(std::string target);

   public:
    Shmake(std::string fileName);
    ~Shmake();
    void readFile();
    void execute(std::string target);
};

#endif