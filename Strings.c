#include "monty.h"

/**
 * print_char -the Ascii value
 * @stack: Pointer to a pointer pointing to top node
 * @line_nbr: Interger representing the line number
 */
void print_char(stack_t **stack, unsigned int line_nbr)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_nbr);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_nbr);
	printf("%c\n", ascii);
}
/**
 * print_str - string
 * @stack: Pointer to a pointer pointing to top node
 * @ln: Interger representing the line number
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * rotl - Rotates the first node to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - Rotates the last node to the top.
 * @stack: Pointer to a pointer pointing to top
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
