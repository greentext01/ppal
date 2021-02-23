#include <downloader.h>
#include <error.h>
#include <stdio.h>

#include <iostream>

/**
 * @brief Construct a new Downloader:: Downloader object
 *
 * @param url The URL to download from
 * @param outputPath The file path to output to
 */
Downloader::Downloader(std::string url, std::string outputPath) {
    // Open output file
    outputFileDescriptor = fopen(outputPath.c_str(), "w");

    curlHandle = curl_easy_init();

    // Error catching
    throwErrorIf(!curlHandle, "ERROR: Opening CURL handle failed");

    curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());

    // Set output to the output file instead of stdout
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, outputFileDescriptor);
}

/**
 * @brief Start downloading from the url specified in constructor
 *
 * @param showProgressBar if true, show a terminal pregress bar; if false, don't
 * show a progress bar
 */
void Downloader::startDownload(bool showProgressBar) {
    curl_easy_perform(curlHandle);

    // TODO add progress bar
}