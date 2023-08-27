#include "monty.h"

/**
*add - Function that adds the top two data in a stack, saves it to the second
* top element, point the stack to this entry and then deletes the top stack
*entry.
*
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void add(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer_a, *pointer_b;
	int temp_n;

	(void)temp;

	if (stk_len(stack) >= 2)
	{
		pointer_a = *stack;
		pointer_b = (*stack)->prev;
		temp_n = pointer_b->n;
		pointer_b->n = (pointer_a->n) + temp_n;
		*stack = pointer_b;
		free(pointer_a);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clean(stack, file, p);
	}
}

/**
*sub - Function that subtracts the top two data in a stack, saves it to the
*second top element, point the stack to this entry and then deletes the
*top stack entry.
*
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void sub(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer_a, *pointer_b;
	int temp_n;

	(void)temp;

	if (stk_len(stack) >= 2)
	{
		pointer_a = *stack;
		pointer_b = (*stack)->prev;
		temp_n = pointer_b->n;
		pointer_b->n = temp_n - (pointer_a->n);
		*stack = pointer_b;
		free(pointer_a);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean(stack, file, p);
	}
}
