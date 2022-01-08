/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:24:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 15:36:01 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_numbers(t_vars *vars)
{
	if (vars->size == 3)
	{
		sort_three(vars, 0, 0, 2);
	}
	else if (vars->size == 5)
	{
		sort_five(vars);
	}
	else
	{
		sort_radix(vars);
	}
}
