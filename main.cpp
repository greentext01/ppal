#include <unistd.h>

#include "shmake.h"
#define PATH_MAX 4096

int main(int argc, char* argv[]) {
    char cwd[PATH_MAX];
    if (argc < 2) {
        cout << "Error: specify target\n";
        return 1;
    }
    Shmake shmake(string(getcwd(cwd, sizeof(cwd))) + "/Shmfile");
    shmake.readFile();
    shmake.execute(argv[1]);
    return 0;
}