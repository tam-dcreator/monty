#include "monty.h"
/**
*push - Function that pushes to stack
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized line
*
*/
void push(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file), exit(EXIT_FAILURE);
	}

	if (newnode == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	newnode->n = atoi(temp);
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*stack)
	{
		newnode->prev = *stack;
		(*stack)->next = newnode;
	}
	*stack = newnode;
}

/**
*pall - Function to print all the values on the stack starting from the top
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*
*/
void pall(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *pointer = *stack;

	(void)line_number;
	(void)temp;

	if (pointer == NULL)
		return;
	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->prev;
	}
}
