/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:25:09 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 15:15:30 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_vars *vars)
{
	if (vars->b->list[vars->b->first])
	{
		vars->b->first -= 1;
	}
	vars->b->list[vars->b->first] = vars->a->list[vars->a->first];
	vars->a->list[vars->a->first] = NULL;
	if (vars->a->list[vars->a->first + 1])
		vars->a->first += 1;
	write(1, "pb\n", 3);
}

void	push_a(t_vars *vars)
{
	if (vars->a->list[vars->a->first])
	{
		vars->a->first -= 1;
	}
	vars->a->list[vars->a->first] = vars->b->list[vars->b->first];
	vars->b->list[vars->b->first] = NULL;
	if (vars->b->list[vars->b->first + 1])
		vars->b->first += 1;
	write(1, "pa\n", 3);
}
