#include "simple_shell.h"

void print_error(int argc, char **argv, char **av)
{

    perror(argv[0]);
    perror(": 1: ");
    perror(av[0]);
    perror(": ");
    perror("not found");
}