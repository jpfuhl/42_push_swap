/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:22:31 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/15 14:47:41 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_error_bools(t_error *error)
{
	if (error->non_digit > 0)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (error->invalid_sign > 0)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}

void	check_invalid_sign(t_error *error, char *str, int i)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (i == 0 && str[i + 1] == '\0')
		{
			error->invalid_sign += 1;
		}
		else if (i > 0)
		{
			error->invalid_sign += 1;
		}
	}
}

void	check_non_digit(t_error *error, char *str, int i)
{
	if (str[i] < '0' || '9' < str[i])
	{
		if (str[i] != '+' && str[i] != '-')
		{
			error->non_digit += 1;
		}
	}
}

void	initialize_error_bools(t_error *error)
{
	error->non_digit = 0;
	error->invalid_sign = 0;
}

void	check_number(char *str)
{
	t_error	error;
	int		i;

	i = 0;
	initialize_error_bools(&error);
	while (str[i] != '\0')
	{
		check_non_digit(&error, str, i);
		check_invalid_sign(&error, str, i);
		i++;
	}
	check_error_bools(&error);
}
