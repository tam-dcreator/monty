#include "monty.h"
/**
*main - Entry function
*@ac: Argument count
*@argv: Argument vector
*
*Return: On success 0.
*/
int main(int ac, char *argv[])
{
	FILE *file;
	stack_t *stk;
	char *token, *lineptr = NULL, *filename = argv[1];
	function_pointer fp;
	int line_no = 0;
	size_t len = 0;
	ssize_t read;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
		fprintf(stderr, "Can't open file <%s>\n", filename),
			exit(EXIT_FAILURE);
	/*Read lines from the open file*/
	while ((read = getline(&lineptr, &len, file)) != -1)
	{
		line_no++;
		/*Check if a blank line was encountered*/
		if (read <= 1)
			continue;
		else
		{
			/*tokenize lineptr and find the corresponding func*/
			token = strtok(lineptr, " \n");
			fp = find_app_func(token, line_no);
			token = strtok(NULL, " \n");
			/*Call the function passing the variables*/
			if (token != NULL)
				fp(&stk, atoi(token));
			else
				fp(&stk, 0);
		}
	}
	free(lineptr);
	fclose(file);
	return (0);
}
