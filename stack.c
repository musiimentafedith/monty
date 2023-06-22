#include"monty.h"
/**
* delete_stack_node - delete node at the head/top
* Return: void
*/
void dlt_stack_node(void)
{
	stack_t *tmp;

	tmp = arguments->head;
	arguments->head = tmp->next;
	free(tmp);
}
