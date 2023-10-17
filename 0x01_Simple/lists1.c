#include "shell.h"

/**
 * count_nodes - determines the number of nodes in a linked list
 * @list: pointer to the first node
 *
 * Return: the number of nodes in the list
 */
size_t count_nodes(const list_t *list)
{
    size_t count = 0;

    for (; list; list = list->next, count++) {
    }

    return count;
}

/**
 * list_to_strings - converts a linked list of strings into an array of strings
 * @head: pointer to the head of the linked list
 *
 * Return: an array of strings or NULL on failure
 */
char **convert_list_to_string_array(list_t *head)
{
    list_t *current = head;
    size_t node_count = count_nodes(head);
    size_t index;
    char **string_array;
    char *str;
    size_t j;

    if (!head || !node_count)
        return NULL;

    string_array = malloc(sizeof(char *) * (node_count + 1));

    if (!string_array)
        return NULL;

    for (index = 0; current; current = current->next, index++) {
        str = malloc(_strlen(current->str) + 1);

        if (!str) {
            for (j = 0; j < index; j++)
                free(string_array[j]);
            free(string_array);
            return NULL;
        }

        str = _strcpy(str, current->str);
        string_array[index] = str;
    }

    string_array[index] = NULL;

    return string_array;
}

/**
 * print_list - prints all elements of a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_linked_list(const list_t *head)
{
    size_t node_count = 0;

    for (; head; head = head->next, node_count++) {
        _puts(convert_number(head->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
    }

    return node_count;
}
    
/**
 * find_node_with_prefix - finds a node whose string starts with a given prefix
 * @head: pointer to the head of the linked list
 * @prefix: the prefix to match
 * @next_char: the next character after the prefix to match
 *
 * Return: the matching node or NULL if not found
 */
list_t *find_node_with_prefix(list_t *head, char *prefix, char next_char)
{
    char *str_ptr = NULL;

    for (; head; head = head->next) {
        str_ptr = starts_with(head->str, prefix);

        if (str_ptr && ((next_char == -1) || (*str_ptr == next_char)))
            return head;
    }

    return NULL;
}

/**
 * get_node_index - gets the index of a specific node within a linked list
 * @head: pointer to the head of the linked list
 * @node: pointer to the node to find the index of
 *
 * Return: the index of the node or -1 if not found
 */
ssize_t get_index_of_node(list_t *head, list_t *node)
{
    size_t index = 0;

    for (; head; head = head->next, index++) {
        if (head == node)
            return index;
    }

    return -1;
}
