/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:06:40 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:14:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_if_sorted(t_vars *vars)
{
	int	in_order;
	int	i;

	in_order = vars->size;
	i = vars->size - 1;
	while (i > 0)
	{
		if (vars->numbers[i]->input > vars->numbers[i - 1]->input)
		{
			in_order -= 1;
		}
		else
		{
			in_order += 1;
		}
		i--;
	}
	if (in_order == 1)
	{
		free_number_array(vars, vars->size);
		exit (6);
	}
}

void	check_duplicates(t_vars *vars)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < vars->size)
	{
		j = i + 1;
		num = vars->numbers[i]->input;
		while (j < vars->size)
		{
			if (num == vars->numbers[j]->input)
			{
				write(2, "Error\n", 6);
				free_number_array(vars, vars->size);
				exit (5);
			}
			j++;
		}
		i++;
	}
}

void	check_input(t_vars *vars)
{
	check_duplicates(vars);
	check_if_sorted(vars);
}
