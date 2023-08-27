#include "monty.h"

FILE *file;/*Global variable*/

/**
*main - Entry function
*@ac: Argument count
*@argv: Argument vector
*
*Return: On success 0.
*/
int main(int ac, char *argv[])
{
	stack_t *stk = NULL;
	char *token, *lineptr = NULL, *filename = argv[1];
	function_pointer fp;
	int line_no = 0;
	size_t len = 0, read, flag = -1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename),
			exit(EXIT_FAILURE);
	/*Read lines from the open file*/
	while ((read = getline(&lineptr, &len, file)) != flag)
	{
		line_no++;
		/*Check if a blank line was encountered*/
		if (read <= 1)
			continue;
		else
		{
			/*tokenize lineptr and find the corresponding func*/
			token = strtok(lineptr, " \n");
			if (token)
			{
				fp = find_app_func(token, line_no);
				if (strcmp("pall", token) != 0)
					token = strtok(NULL, " \n");
			/*Call the function passing the variables*/
				fp(&stk, line_no, token, lineptr);
			}
		}
	}
	free(lineptr);
	fclose(file);
	free_stack(&stk);
	return (0);
}
