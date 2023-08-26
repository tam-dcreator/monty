#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE *file;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
*function_pointer - Created a typedef for the function pointer
*
*Description: Typedef a function pointer
*/
typedef void (*function_pointer)(stack_t **, unsigned int, char *temp);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	function_pointer f;
} instruction_t;

function_pointer find_app_func(char *opcode, int line_no);
void pall(stack_t **stack, unsigned int line_number, char *temp);
void push(stack_t **stack, unsigned int line_number, char *temp);
void free_stack(stack_t **stack);

#endif /*MONTY_H*/
