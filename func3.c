#include "monty.h"

/**
 * mul_nodes - Adds the top two elements
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_nbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nbr, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mod_nodes - Adds the top two elements
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void mod_nodes(stack_t **stack, unsigned int line_nbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_nbr, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_nbr);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

