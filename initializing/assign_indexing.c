/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:18:52 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 18:56:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	update_minimum(t_vars *vars)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	while (vars->numbers[i]->checked == 1)
	{
		i++;
	}
	min = vars->numbers[i]->input;
	pos = i;
	while (i < vars->size)
	{
		if (vars->numbers[i]->input < min && vars->numbers[i]->checked == 0)
		{
			min = vars->numbers[i]->input;
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	assign_indexing(t_vars *vars)
{
	int	n;
	int	pos;

	n = 0;
	while (n < vars->size)
	{
		pos = update_minimum(vars);
		vars->numbers[pos]->assigned = n;
		vars->numbers[pos]->checked = 1;
		n++;
	}
}
