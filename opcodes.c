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
		fclose(file), free(p), exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
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
*is_int - Function that checks if a string comprises of numbers
*@temp: String
*
*Return: True or False
*/
bool is_int(char *temp)
{
	int i = 0;

	while (temp[i])
	{
		if (temp[i] > 57 || temp[i] < 48)
			return (false);
		i++;
	}
	return (true);
}
