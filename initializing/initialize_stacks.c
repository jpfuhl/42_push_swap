/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:02:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:49:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	**get_stack_b(t_vars *vars)
{
	int	i;
	int	**list;

	list = malloc(vars->size * sizeof(int *));
	if (!list)
	{
		free(vars->a->list);
		free(vars->a);
		free(vars->b);
		free_number_array(vars, vars->size);
		exit (10);
	}
	i = 0;
	while (i < vars->size)
	{
		list[i] = NULL;
		i++;
	}
	vars->b->first = vars->size - 1;
	vars->b->last = vars->size - 1;
	return (list);
}

int	**get_stack_a(t_vars *vars)
{
	int	i;
	int	**list;

	list = malloc(vars->size * sizeof(int *));
	if (!list)
	{
		free(vars->a);
		free(vars->b);
		free_number_array(vars, vars->size);
		exit (9);
	}
	i = 0;
	while (i < vars->size)
	{
		list[i] = &vars->numbers[i]->assigned;
		i++;
	}
	vars->a->first = 0;
	vars->a->last = vars->size - 1;
	return (list);
}

void	initialize_stacks(t_vars *vars)
{
	vars->a = malloc(sizeof(t_stack));
	if (!vars->a)
	{
		free_number_array(vars, vars->size);
		exit (7);
	}
	vars->b = malloc(sizeof(t_stack));
	if (!vars->b)
	{
		free(vars->a);
		free_number_array(vars, vars->size);
		exit (8);
	}
	vars->a->list = get_stack_a(vars);
	vars->b->list = get_stack_b(vars);
}
