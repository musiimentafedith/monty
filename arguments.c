#include "monty.h"

/**
 * check_arguments - Checks the number of command-line arguments.
 * @argc: The number of command-line arguments.
 */

void check_arguments(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * define_arguments - Initializes a pointer to
 * arg_s structure.
 */
void define_arguments(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->stream = NULL;
	arguments->head = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
	arguments->stack_length = 0;
	arguments->stack = 1;
}
