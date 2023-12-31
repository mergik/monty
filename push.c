#include "monty.h"

/**
 * push - Pushes an element to the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "%u: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = (*stack)->n;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
