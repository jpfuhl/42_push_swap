/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:29:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 16:15:51 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_push_to_b(t_vars *vars, int pos, int value)
{
	while (*vars->a->list[pos] != value)
	{
		if (*vars->a->list[1] == value || *vars->a->list[2] == value)
		{
			rotate_a(vars);
		}
		else
		{
			reverse_rotate_a(vars);
		}
	}
	push_b(vars);
	return (1);
}

void	sort_five(t_vars *vars)
{
	sort_push_to_b(vars, 0, 0);
	sort_push_to_b(vars, 1, 1);
	sort_three(vars, 2, 2, 4);
	push_a(vars);
	push_a(vars);
}
