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

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the sub function is called.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp1 = arguments->head;
	temp2 = temp1->next;

	temp2->n = temp2->n - temp1->n;
	dlt_stack_node();

	arguments->stack_length -= 1;
}
