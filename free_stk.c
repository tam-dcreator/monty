#include "monty.h"
/**
*free_stack - Function that frees the stack
*@stack: The stack that needs to be free
*
*/
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		temp = temp->prev;
		free(*stack);
		(*stack) = temp;
	}
}
