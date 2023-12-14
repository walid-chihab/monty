#include "monty.h"

/**
* execute_ - function to executes the opcode
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute_(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push_}, {"pall", f_pall_}, {"pint", f_pint_},
				{"pop", f_pop_},
				{"swap", f_swap_},
				{"add", f_add_},
				{"nop", f_nop_},
				{"sub", f_sub_},
				{"div", f_div_},
				{"mul", f_mul_},
				{"mod", f_mod_},
				{"pchar", f_pchar_},
				{"pstr", f_pstr_},
				{"rotl", f_rotl_},
				{"rotr", f_rotr_},
				{"queue", f_queue_},
				{"stack", f_stack_},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack_(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
