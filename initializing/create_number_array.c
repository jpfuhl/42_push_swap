/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_number_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:44:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:45:22 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_number_array(t_vars *vars)
{
	int	i;

	i = 0;
	vars->numbers = malloc(vars->size * sizeof(t_nbr *));
	if (!vars->numbers)
	{
		exit (1);
	}
	while (i < vars->size)
	{
		vars->numbers[i] = malloc(sizeof(t_nbr));
		if (!vars->numbers[i])
		{
			free_number_array(vars, i);
			exit (2);
		}
		i++;
	}
}
