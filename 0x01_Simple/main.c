#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info;
    int fd = 2;
    
    memset(&info, 0, sizeof(info_t));
    __asm__(
        "mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
            {
                exit(126);
            }
            if (errno == ENOENT)
            {
                write_stderr(av[0]);
                write_stderr(": 0: Can't open ");
                write_stderr(av[1]);
                write_stderr(": No such file or directory\n");
                write_stderr_char(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info.readfd = fd;
    }

    populate_env_list(&info);
    read_history(&info);
    hsh(&info, av);

    return (EXIT_SUCCESS);
}
