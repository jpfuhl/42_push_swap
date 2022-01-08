/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:21:20 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:15:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(t_vars *vars)
{
	create_number_array(vars);
	fill_array(vars);
	check_input(vars);
	assign_indexing(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
	{
		return (0);
	}
	vars.argc = argc;
	vars.argv = argv;
	vars.size = get_stack_size(&vars);
	parse_input(&vars);
	initialize_stacks(&vars);
	sort_numbers(&vars);
	free_memory(&vars);
	return (0);
}
