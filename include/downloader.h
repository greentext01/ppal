#include <curl/curl.h>
#include <error.h>

#include <iostream>

class Downloader {
   private:
    CURL *curlHandle;
    CURLcode curlResponse;

   public:
    Downloader(std::string url, std::string outputPath);
    void startDownload(bool showProgressBar);
    ~Downloader();
};