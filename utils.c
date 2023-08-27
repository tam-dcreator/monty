#include "monty.h"
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
		if ((temp[0] == 45 || temp[0] == 43) && temp[1] != '\0' &&
			i == 0)
			i++;
		if (temp[i] > 57 || temp[i] < 48)
			return (false);
		i++;
	}
	return (true);
}

/**
*clean - Function that closes all open files and frees malloc'ed mem on exit
*@stack: Stack to free
*@file: File to close
*@p: Lineptr variable used by getlines
*/
void clean(stack_t **stack, FILE *file, char *p)
{
	fclose(file), free_stack(stack), free(p);
	exit(EXIT_FAILURE);
}
