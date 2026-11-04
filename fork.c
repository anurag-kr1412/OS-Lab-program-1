#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        printf("fork failed\n");
    }
    else if (pid > 0)
    {
        int status;
        printf("Parent id: %d\n", getpid());
        printf("Parent waiting for child...\n");

        waitpid(pid, &status, 0);
    }
    else
    {
        printf("Child process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());

        execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *)0);

        _exit(EXIT_FAILURE);
    }

    return 0;
}