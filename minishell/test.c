#include <unistd.h> // for chdir()
#include "minishell.h"

int main() {
    // Change to the /tmp directory
    if (chdir("/tmp") == -1) {
        perror("chdir"); // print error message
        return 1;
    }

    // Now, the current working directory is /tmp
    printf("Current directory: %s\n", getcwd(NULL, 0));

    return 0;
}