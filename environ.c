#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containingbarguments.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of enviroment value
 * @info: Structure containing arguments.
 * @name: env variable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *n = info->env;
	char *p;

	while (n)
	{
		p = stringStartsWith(n->str, name);
		if (p && *p)
			return (p);
		n = n->next;
	}
	return (NULL);
}

/**
 * _setenvi - Initialize a new environment variable.
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _setenvi(info_t *info)
{
	if (info->argc != 3)
	{
		write_stderr("Incorrect number of inputs\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenvi - Remove the environment variable
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _unsetenvi(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		write_stderr("you enteren few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{

	list_t *n = NULL;
	size_t i = 0;

	while (environ[i])
	{
		add_point_end(&n, environ[i], 0);
		i++;
	}
	info->env = n;
	return (0);
}

