/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:33:31 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 15:14:26 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_b(t_vars *vars)
{
	int	index;
	int	*tmp;

	index = vars->b->last;
	tmp = vars->b->list[vars->b->last];
	while (index > vars->b->first)
	{
		vars->b->list[index] = vars->b->list[index - 1];
		index--;
	}
	vars->b->list[vars->b->first] = tmp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a(t_vars *vars)
{
	int	index;
	int	*tmp;

	index = vars->a->last;
	tmp = vars->a->list[vars->a->last];
	while (index > vars->a->first)
	{
		vars->a->list[index] = vars->a->list[index - 1];
		index--;
	}
	vars->a->list[vars->a->first] = tmp;
	write(1, "rra\n", 4);
}
