#include "monty.h"

/**
*pchar - Function that prints the char at the top of the stack.
*
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void pchar(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	int temp_n = (*stack)->n;

	(void)temp;

	if (*stack)
	{
		if (temp_n > 127 || temp_n < 0)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			clean(stack, file, p);
		}
		printf("%c\n", temp_n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		clean(stack, file, p);
	}
}
