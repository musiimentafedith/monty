#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node1, *temp_node2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n",
				line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp_node1 = arguments->head;
	temp_node2 = temp_node1->next;

	temp_node2->n = temp_node1->n + temp_node2->n;
	dlt_stack_node();

	arguments->stack_length -= 1;
}
