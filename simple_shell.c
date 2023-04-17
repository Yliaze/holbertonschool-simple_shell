#include "simple_shell.h"

int main(int ac, char **av)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("pid : %d ppid = %d \n", pid, ppid);
    return (0);
}