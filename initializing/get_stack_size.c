/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:40:49 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/13 02:59:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_numbers(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (s[index] != c && s[index] != '\0')
	{
		count++;
	}
	while (s[index] != '\0')
	{
		if (s[index] == '\0')
		{
			break ;
		}
		if (s[index] != c && s[index - 1] == c && index != 0)
		{
			count++;
		}
		index++;
	}
	return (count);
}

int	get_stack_size(t_vars *vars)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < vars->argc)
	{
		size += count_numbers(vars->argv[i], ' ');
		i++;
	}
	return (size);
}
