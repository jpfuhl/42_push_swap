/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:04:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:39:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_number_array(t_vars *vars, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(vars->numbers[i]);
		i++;
	}
	free(vars->numbers);
}

void	free_empty_string(t_vars *vars, int i)
{
	free_number_array(vars, vars->size);
	if (i == 1 && vars->argc == 2)
	{
		exit (4);
	}
	else
	{
		write(2, "Error\n", 6);
		exit (12);
	}
}

void	free_memory(t_vars *vars)
{
	free(vars->a->list);
	free(vars->a);
	free(vars->b->list);
	free(vars->b);
	free_number_array(vars, vars->size);
}
