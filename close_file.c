#include "monty.h"

/**
 * close_file - Closes the file stream and sets it to NULL.
 */

void close_file(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}
