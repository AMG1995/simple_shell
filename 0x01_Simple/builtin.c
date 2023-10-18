#include "shell.h"

int _forexit(info_t *info) 
{
	if (info->argv[1]) {
		int exit_status = _erratoi(info->argv[1]);
        if (exit_status != -1) {
		info->err_num = exit_status;
		return -2;
        } 
	else 
	{
		info->status = 2;
		print_error(info, "Illegal number: ");
		write_stderr(info->argv[1]);
		write_stderr_char('\n');
	}
    }
    info->err_num = -1;
    return -2;
}

int _cd(info_t *info) {
    char *target_dir = (info->argv[1]) ? info->argv[1] : _getenv(info, "HOME=");
    char *current_dir;

    if (!target_dir) {
        _puts("HOME environment variable not set\n");
        return 1;
    }

    current_dir = getcwd(NULL, 0);
    if (!current_dir) {
        _puts("getcwd failure\n");
        return 1;
    }

    if (stringCompare(target_dir, "-") == 0) {
        target_dir = _getenv(info, "OLDPWD=");
        if (!target_dir) {
            _puts(current_dir);
            _putchar('\n');
            free(current_dir);
            return 0;
        }
    }

    if (chdir(target_dir) == -1) {
        print_error(info, "can't cd to ");
        write_stderr(target_dir);
        write_stderr_char('\n');
        free(current_dir);
        return 1;
    }

    _setenv(info, "OLDPWD", current_dir);
    _setenv(info, "PWD", getcwd(NULL, 0));
    free(current_dir);
    return 0;
}

int _help(info_t *info) {
    (void)info;
    _puts("Help: This is a simple shell. Not all features are implemented yet.\n");
    return 0;
}
=======
#include "shell.h"
 
/**
 * _forexit - Handles the exit built-in command.
 * @info: Struct containing information about the shell.
 *
 * Return: -2 for exit, -1 for error.
 */
int _forexit(info_t *info)
{
	if (info->argv[1])
	{
		if (exit_status != -1)
		{
			info->err_num = exit_status;
			return (-2);
		}
		else
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			write_stderr(info->argv[1]);
			write_stderr_char('\n');
		}
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _cd - Handles the cd built-in command.
 * @info: Struct containing information about the shell.
 *
 * Return: 0 for success, 1 for error.
 */
int _cd(info_t *info)
{
	char *target_dir = (info->argv[1]) ? info->argv[1] : _getenv(info, "HOME=");
	char *current_dir;

	if (!target_dir)
	{
		_puts("HOME environment variable not set\n");
		return (1);
	}

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		_puts("getcwd failure\n");
		return (1);
	}

	if (stringCompare(target_dir, "-") == 0)
	{
		target_dir = _getenv(info, "OLDPWD=");
		if (!target_dir)
		{
			_puts(current_dir);
			_putchar('\n');
			free(current_dir);
			return (0);
		}
	}

	if (chdir(target_dir) == -1)
	{
		print_error(info, "can't cd to ");
		write_stderr(target_dir);
		write_stderr_char('\n');
		free(current_dir);
		return (1);
	}

	_setenv(info, "OLDPWD", current_dir);
	_setenv(info, "PWD", getcwd(NULL, 0));
	free(current_dir);
	return (0);
}

/**
 * _help - Handles the help built-in command.
 * @info: Struct containing information about the shell.
 *
 * Return: 0 for success.
 */
int _help(info_t *info)
{
	(void)info;
	_puts("Help: This is a simple shell. Not all features are implemented yet.\n");
	return (0);
}
>>>>>>> 2106e75212672641faea7529a8449a0f87e23e85
