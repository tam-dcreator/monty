#include "monty.h"
/**
*push - Function that pushes to stack
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized line
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*
*/
void push(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *newnode;

	if (temp == NULL || !(is_int(temp)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		clean(stack, file, p);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		fprintf(stderr, "Error: malloc failed\n"),
			clean(stack, file, p);
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
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*
*/
void pall(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer = *stack;

	(void)line_number;
	(void)temp;
	(void)p;

	if (pointer == NULL)
		return;
	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->prev;
	}
}

/**
*pint - Function that prints the values at the top of the stack.
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void pint(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	(void)temp;

	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clean(stack, file, p);
	}
}

/**
*pop - Function that removes the top element of the stack.
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void pop(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer = *stack;

	(void)temp;

	if (*stack)
	{
		*stack = (*stack)->prev;
		free(pointer);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clean(stack, file, p);
	}
}

/**
*swap - Function that removes the top element of the stack.
*@stack: Stack data would be stored in
*@line_number: Integer to be added
*@temp: Tokenized input
*@p: Lineptr var, sent for freeing incase of an error and the program exits
*/
void swap(stack_t **stack, unsigned int line_number, char *temp, char *p)
{
	stack_t *pointer_a, *pointer_b;
	int temp_n;

	(void)temp;

	if (stk_len(stack) >= 2)
	{
		pointer_a = *stack;
		pointer_b = (*stack)->prev;
		temp_n = pointer_a->n;
		pointer_a->n = pointer_b->n;
		pointer_b->n = temp_n;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clean(stack, file, p);
	}
}
