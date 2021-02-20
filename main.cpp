#include <ppal.h>

int main() {
    Downloader dwn("https://www.angio.net/pi/digits/pi1000000.txt",
                   "pi1million.txt");
    dwn.startDownload(false);
    return 0;
}