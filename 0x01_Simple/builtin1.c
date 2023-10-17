#include "shell.h"

/**
 * display_history - Displays the history list, one command per line, preceded
 *                  with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int display_history(info_t *info)
{
    print_linked_list(info->history);
    return (0);
}

/**
 * unset_alias_variable - Unsets an alias variable.
 * @info: Parameter struct.
 * @str: The alias variable to unset.
 * Return: Always 0 on success, 1 on error.
 */
int unset_alias_variable(info_t *info, char *str)
{
    char *equal_sign, saved_char;
    int ret;

    equal_sign = _strchr(str, '=');
    if (!equal_sign)
        return (1);
    saved_char = *equal_sign;
    *equal_sign = 0;
    ret = delete_point_index(&(info->alias),
                            get_index_of_node(info->alias, find_node_with_prefix(info->alias, str, -1)));
    *equal_sign = saved_char;
    return (ret);
}

/**
 * set_alias_variable - Sets an alias variable.
 * @info: Parameter struct.
 * @str: The alias variable to set.
 * Return: Always 0 on success, 1 on error.
 */
int set_alias_variable(info_t *info, char *str)
{
    char *equal_sign;

    equal_sign = _strchr(str, '=');
    if (!equal_sign)
        return (1);
    if (!*++equal_sign)
        return (unset_alias_variable(info, str));

    unset_alias_variable(info, str);
    return (add_point_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias_variable - Prints an alias variable.
 * @node: The alias variable node.
 * Return: Always 0 on success, 1 on error.
 */
int print_alias_variable(list_t *node)
{
    char *equal_sign, *alias_str;

    if (node)
    {
        equal_sign = _strchr(node->str, '=');
        alias_str = node->str;
        while (alias_str <= equal_sign)
        {
            _putchar(*alias_str);
            alias_str++;
        }
        _putchar('\'');
        _puts(equal_sign + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * manage_alias - Mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int manage_alias(info_t *info)
{
    int i = 0;
    char *equal_sign;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias_variable(node);
            node = node->next;
        }
        return (0);
    }
    while (info->argv[i])
    {
        equal_sign = _strchr(info->argv[i], '=');
        if (equal_sign)
            set_alias_variable(info, info->argv[i]);
        else
            print_alias_variable(find_node_with_prefix(info->alias, info->argv[i], '='));
        i++;
    }

    return (0);
}
