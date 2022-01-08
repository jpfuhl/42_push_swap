/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:02:42 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/10 20:31:03 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_in_end(t_vars *vars, int shift, int max)
{
	if (*vars->a->list[0 + shift] == max)
	{
		rotate_a(vars);
		swap_a(vars);
	}
	else if (*vars->a->list[1 + shift] == max)
	{
		reverse_rotate_a(vars);
	}
}

void	first_in_middle(t_vars *vars, int shift, int max)
{
	if (*vars->a->list[0 + shift] == max)
	{
		rotate_a(vars);
	}
	else if (*vars->a->list[2 + shift] == max)
	{
		swap_a(vars);
	}
}

void	first_in_start(t_vars *vars, int shift, int max)
{
	if (*vars->a->list[2 + shift] == max)
	{
		return ;
	}
	else
	{
		reverse_rotate_a(vars);
		swap_a(vars);
	}
}

void	sort_three(t_vars *vars, int shift, int min, int max)
{
	if (*vars->a->list[0 + shift] == min)
	{
		first_in_start(vars, shift, max);
	}
	else if (*vars->a->list[1 + shift] == min)
	{
		first_in_middle(vars, shift, max);
	}
	else if (*vars->a->list[2 + shift] == min)
	{
		first_in_end(vars, shift, max);
	}
}
