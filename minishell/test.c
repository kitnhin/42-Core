#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char *argv[] = { "./test", NULL };
    char *envp[] = { NULL };

    execve("./test", argv, envp);

    // If execve returns, it means an error occurred
    // perror("execve");
    return 1;
}