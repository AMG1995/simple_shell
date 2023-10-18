#include "shell.h"

/**
 * _forexit - Exits the shell.
 * @info: Structure containing potential arguments.
 *
 * Return: Exits with a given exit status.
 *         (0) if info->argv[0] != "exit".
 */
int _forexit(info_t *info)
{
	int exit_status;

	if (info->argv[1])  /* If there is an exit argument */
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _cd - Changes the current directory of the process.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _cd(info_t *info)
{
	char *current_dir, *target_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		target_dir = _getenv(info, "HOME=");
		if (!target_dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((target_dir = _getenv(info, "PWD=")) ? target_dir : "/");
		else
			chdir_ret = chdir(target_dir);
	}
	else if (stringCompare(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((target_dir = _getenv(info, "OLDPWD=")) ? target_dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
	}
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_puts(info->argv[1]);
		_putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - Displays help information.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* Temporarily unused workaround */
	return (0);
}
