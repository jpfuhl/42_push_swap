/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:29:35 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 15:01:30 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_vars *vars)
{
	int	*tmp;

	tmp = vars->b->list[vars->b->first];
	vars->b->list[vars->b->first] = vars->b->list[vars->b->first + 1];
	vars->b->list[vars->b->first + 1] = tmp;
	write(1, "sb\n", 3);
}

void	swap_a(t_vars *vars)
{
	int	*tmp;

	tmp = vars->a->list[vars->a->first];
	vars->a->list[vars->a->first] = vars->a->list[vars->a->first + 1];
	vars->a->list[vars->a->first + 1] = tmp;
	write(1, "sa\n", 3);
}
