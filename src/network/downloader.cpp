#include <downloader.h>

Downloader::Downloader(std::string url, std::string outputPath) {
    curlHandle = curl_easy_init();
    throwErrorIf(!curlHandle, "ERROR: Opening CURL handle failed");
    curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_STDERR, stdout);
    curl_easy_setopt(curlHandle, CURLOPT_VERBOSE, 1L);
}

void Downloader::startDownload(bool showProgressBar) {
    curl_easy_perform(curlHandle);
}