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
	int temp_n;

	(void)temp;

	if (*stack)
	{
		temp_n = (*stack)->n;
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

/**
*pstr - Function that prints the char of all the data in a stack as a string.
*
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void pstr(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer = *stack;
	int temp_n;

	(void)temp;
	(void)p;
	(void)line_number;

	if (pointer)
	{
		while (pointer && pointer->n > 31 && pointer->n < 126)
		{
			temp_n = pointer->n;
			printf("%c", temp_n);
			pointer = pointer->prev;
		}
	}
	putchar('\n');
}

/**
*rotl - Function that rotates the stack to the top. The top element becomes
*the last one and the second top element of the stack becomes the first one.
*
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void rotl(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *ptr1, *ptr2;
	int temp_n;

	(void)temp;
	(void)p;
	(void)line_number;

	if (stk_len(stack) >= 2)
	{
		ptr1 = *stack;
		ptr2 = (*stack)->prev;
		temp_n = ptr1->n;
		while (ptr2)
		{
			ptr1->n = ptr2->n;
			ptr2->n = temp_n;
			ptr1 = ptr2;
			ptr2 = ptr2->prev;
		}
	}
}
