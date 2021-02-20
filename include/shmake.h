#ifndef FILEREADER_H
#define FILEREADERH

#include <stdio.h>
#include <sys/stat.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Shmake {
   private:
    string buffer;
    string outputFileName;
    vector<string> contents;
    ifstream inputFileStream;
    ofstream outputFileStream;
    int findTarget(string target);

   public:
    Shmake(string fileName);
    ~Shmake();
    void readFile();
    void execute(string target);
};

#endif