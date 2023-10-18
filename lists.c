#include "shell.h"

/**
 * add_point - adds  point to start of list.
 * @h: address of pointer to head point
 * @s: str field of point
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_point(list_t **h, const char *s, int num)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	fillMemory((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (s)
	{
		new_head->str = stringDuplicate(s);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * add_point_end - adds a point at the end
 * @h: address of pointer to head point
 * @s: str field of point
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_point_end(list_t **h, const char *s, int num)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	fillMemory((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (s)
	{
		new_node->str = stringDuplicate(s);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * print_list_str - pring str element.
 * @h: pointer to first point
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_point_index - deletes point at given index
 * @h: address of pointer to first point
 * @id: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_point_index(list_t **h, unsigned int id)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!id)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == id)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all point.
 * @head_ptr: address of the pointer.
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
