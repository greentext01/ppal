#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <curl/curl.h>
#include <iostream>

class Downloader {
   private:
    CURL* curlHandle;
    CURLcode curlResponse;
    FILE* outputFileDescriptor;

   public:
    Downloader(std::string url, std::string outputPath);
    void startDownload(bool showProgressBar);
};

#endif