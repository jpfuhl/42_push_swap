/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:32:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 15:07:25 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_vars *vars)
{
	int	index;
	int	*tmp;

	index = vars->b->first;
	tmp = vars->b->list[vars->b->first];
	while (index < vars->size)
	{
		vars->b->list[index] = vars->b->list[index + 1];
		index++;
	}
	vars->b->list[vars->b->last] = tmp;
	write(1, "rb\n", 3);
}

void	rotate_a(t_vars *vars)
{
	int	index;
	int	*tmp;

	index = vars->a->first;
	tmp = vars->a->list[vars->a->first];
	while (index < vars->size)
	{
		vars->a->list[index] = vars->a->list[index + 1];
		index++;
	}
	vars->a->list[vars->a->last] = tmp;
	write(1, "ra\n", 3);
}
