#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer.
 * @prev: Points to the previous element of the stack (or queue).
 * @next: Points to the next element of the stack (or queue).
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcoode and its function.
 * @opcode: The opcode.
 * @f: Function to handle the opcode.
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct {
    char *arg;
    int SQ;
    char *input_str;
    FILE *file;
} arg_holder_t;

arg_holder_t arg_holder;

/* Global Variables */

/**
 * struct arg_holder_s - Structure to hold program arguments and input data
 * @input_str: Input string from the file
 * @arg: Argument associated with the current command
 * @file: Pointer to the current file being read
 * @SQ: Flag indicating the current mode: stack (1) or queue (0)
 *
 * Description: Global structure to hold program arguments and input data
 */
typedef struct arg_holder_s
{
	char *input_str;
	char *arg;
	FILE *file;
	int SQ;
} arg_holder_t;

extern arg_holder_t arg_holder;

/* Function Prototypes */

int main(int argc, char **argv);
void opcode(char *command, unsigned int line_number, stack_t **stack);
void free_stack(stack_t **head);
void runByteCode(char *filename);
int is_number(char *str);
void push_stack(stack_t **stack, stack_t *new_node);
void push_queue(stack_t **stack, stack_t *new_node);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);

#endif
