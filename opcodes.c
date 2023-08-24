#include "monty.h"
/**
*push - Function that pushes to stack
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	newnode->n = line_number;
	if (*stack == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}

/**
*pall - Function to print all the values on the stack starting from the top
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *pointer = *stack;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}
