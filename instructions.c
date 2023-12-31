#include "monty.h"

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (arguments->head == NULL)
		return;

	(void) line_number;
	(void) stack;

	tmp = arguments->head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->n_tokens <= 1 || !(is_digit(arguments->tokens[1])))
	{
		free_arguments();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(arguments->tokens[1]);
	if (arguments->head == NULL)
		arguments->head = *stack;
	else
	{
		if (arguments->stack)
		{
			(*stack)->next = arguments->head;
			arguments->head->prev = *stack;
			arguments->head = *stack;
		}
		else
		{
			stack_t *tmp = arguments->head;

			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	arguments->stack_length += 1;
}

/**
 * _pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}


/**
 * _pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	dlt_stack_node();
	arguments->stack_length -= 1;
}


/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp1 = arguments->head;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	arguments->head = temp2;
}
