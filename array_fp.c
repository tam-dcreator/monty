#include "monty.h"
/**
*find_app_func - Function that finds the appropriate functions from an array of
*functions.
*
*@stk: Stack to be freed
*@opcode: Key word used to check for the desired function
*@line_no: Current line no.
*@p: Lineptr var from getlines
*
*Return: The appropriate function or NULL
*/
function_pointer find_app_func(stack_t **stk, char *opcode, int line_no,
			       char *p)
{
	int i;

	/*Create an array of struture of type instruction_t*/
	instruction_t func_x[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"0", NULL},
	};
	/*Iterate through the array to get the desired function and return it*/
	for (i = 0; strcmp(func_x[i].opcode, "0") != 0; i++)
	{
		if (strcmp(opcode, func_x[i].opcode) == 0)
			return (func_x[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_no, opcode);
	clean(stk, file, p);
	return (NULL);
}
