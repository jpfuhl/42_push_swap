/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:23:12 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 16:20:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_bits(t_vars *vars)
{
	int	bits;
	int	max;

	bits = 0;
	max = vars->size - 1;
	while ((max >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

void	sort_radix(t_vars *vars)
{
	int	i;
	int	j;
	int	bits;
	int	first;

	i = 0;
	bits = count_bits(vars);
	while (i < bits)
	{
		j = 0;
		while (j++ < vars->size)
		{
			first = *vars->a->list[vars->a->first];
			if (((first >> i) & 1) == 1)
				rotate_a(vars);
			else
				push_b(vars);
		}
		while (vars->b->list[vars->b->last] != NULL)
		{
			push_a(vars);
		}
		i++;
	}
}
