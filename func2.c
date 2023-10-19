#include "monty.h"

/**
 * nop - nop
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void nop(stack_t **stack, unsigned int line_nbr)
{
	(void)stack;
	(void)line_nbr;
}

/**
 * swap_nodes - Swaps the top two elements
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void swap_nodes(stack_t **stack, unsigned int line_nbr)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nbr, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add_nodes - Adds the top two elements
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void add_nodes(stack_t **stack, unsigned int line_nbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nbr, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_nodes - Adds the top two elements
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void sub_nodes(stack_t **stack, unsigned int line_nbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_nbr, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_nbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nbr, "div");

	if ((*stack)->n == 0)
		more_err(9, line_nbr);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
