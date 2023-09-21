#include "monty.h"

/**
 * err - Handles and prints appropriate error messages based on error codes.
 * @error_code: The error codes and their meanings are as follows:
 * (1) => No file provided or more than one file given to the program.
 * (2) => The provided file is not accessible or readable.
 * (3) => The provided file contains an invalid instruction.
 * (4) => The program is unable to allocate more memory (malloc failed).
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list args;
	char *op;
	int line_number;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Handles additional errors and prints appropriate messages.
 * @error_code: The error codes and their meanings are as follows:
 * (6) => The stack is empty when trying to execute "pint".
 * (7) => The stack is empty when trying to execute "pop".
 * (8) => The stack is too short to perform the operation.
 * (9) => Division by zero. 
*/
void more_err(int error_code, ...)
{
	va_list args;
	char *op;
	int line_number;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_number = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * strg_err - Handles string-related errors and prints appropriate messages.
 * @error_code: The error codes and their meanings are as follows:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void strg_err(int error_code, ...)
{
	va_list args;
	int line_number;

	va_start(args, error_code);
	line_number = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
