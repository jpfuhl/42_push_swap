/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:35:03 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:08:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sign(char c, int *sign)
{
	if (c == '+')
		*sign = 1;
	else if (c == '-')
		*sign = -1;
}

int	ps_atoi(t_vars *vars, const char	*str)
{
	long int	number;
	int			i;
	int			sign;

	number = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		check_sign(str[i], &sign);
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (number * sign < -2147483648 || 2147483647 < number * sign)
	{
		write(2, "Error\n", 6);
		free_number_array(vars, vars->size);
		exit (11);
	}
	return (number * sign);
}

void	fill_with_split(t_vars *vars, char *split, int *pos)
{
	char	**tmp;
	int		i;

	tmp = ft_split(split, ' ');
	if (!tmp)
	{
		free_number_array(vars, vars->size);
		exit (3);
	}
	i = 0;
	while (tmp[i] != NULL)
	{
		check_number(tmp[i]);
		vars->numbers[*pos]->input = ps_atoi(vars, tmp[i]);
		vars->numbers[*pos]->assigned = 0;
		vars->numbers[*pos]->checked = 0;
		free(tmp[i]);
		*pos += 1;
		i++;
	}
	free(tmp);
}	

void	fill_single(t_vars *vars, char *fill, int pos)
{
	check_number(fill);
	vars->numbers[pos]->input = ps_atoi(vars, fill);
	vars->numbers[pos]->assigned = 0;
	vars->numbers[pos]->checked = 0;
}

void	fill_array(t_vars *vars)
{
	int	pos;
	int	i;
	int	count;

	pos = 0;
	i = 1;
	while (i < vars->argc)
	{
		count = count_numbers(vars->argv[i], ' ');
		if (count > 1)
		{
			fill_with_split(vars, vars->argv[i], &pos);
		}
		else if (count == 0)
		{
			free_empty_string(vars, i);
		}
		else
		{
			fill_single(vars, vars->argv[i], pos);
			pos++;
		}
		i++;
	}
}
