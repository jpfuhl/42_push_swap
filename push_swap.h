/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:11:11 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/18 21:49:56 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_number_element
{
	int	input;
	int	assigned;
	int	checked;
}	t_nbr;

typedef struct s_stack
{
	int	first;
	int	last;
	int	**list;
}	t_stack;

typedef struct s_error_booleans
{
	int	non_digit;
	int	invalid_sign;
}	t_error;

typedef struct s_program_variables
{
	int		argc;
	char	**argv;
	int		size;
	t_nbr	**numbers;
	t_stack	*a;
	t_stack	*b;
}	t_vars;

/*
**		PARSING INPUT (ARRAY OF S_NUMBER_ELEMENTS)
*/

int		get_stack_size(t_vars *vars);
int		count_numbers(char const *s, char c);

void	parse_input(t_vars *vars);

void	create_number_array(t_vars *vars);

void	fill_array(t_vars *vars);
void	fill_single(t_vars *vars, char *fill, int pos);
void	fill_with_split(t_vars *vars, char *split, int *pos);
int		ps_atoi(t_vars *vars, const char	*str);
void	check_sign(char c, int *sign);

void	assign_indexing(t_vars *vars);
int		update_minimum(t_vars *vars);

/*
**		INITIALIZING STACKS (ARRAYS OF INT *)
*/

void	initialize_stacks(t_vars *vars);
int		**get_stack_a(t_vars *vars);
int		**get_stack_b(t_vars *vars);

/*
**		MEMORY MANAGEMENT
*/

void	free_memory(t_vars *vars);
void	free_empty_string(t_vars *vars, int i);
void	free_number_array(t_vars *vars, int j);

/*
**		CHECKING AND ERROR MANAGEMENT
*/

void	check_number(char *str);
void	initialize_error_bools(t_error *error);
void	check_non_digit(t_error *error, char *str, int i);
void	check_invalid_sign(t_error *error, char *str, int i);
void	check_error_bools(t_error *error);

void	check_input(t_vars *vars);
void	check_duplicates(t_vars *vars);
void	check_if_sorted(t_vars *vars);

/*
** VISUALIZATION
*/

void	print_parsed_numbers(t_vars *vars);
void	print_stack(int **a, int **b, t_vars *vars);
void	print_stack_ptr(int **a, int **b, t_vars *vars);

/*
** SORTING OPERATIONS
*/

void	swap_a(t_vars *vars);
void	swap_b(t_vars *vars);
void	rotate_a(t_vars *vars);
void	rotate_b(t_vars *vars);
void	reverse_rotate_a(t_vars *vars);
void	reverse_rotate_b(t_vars *vars);
void	push_a(t_vars *vars);
void	push_b(t_vars *vars);

/*
** SORTING ALGORITHM
*/

void	sort_numbers(t_vars *vars);

void	sort_three(t_vars *vars, int shift, int min, int max);
void	first_in_start(t_vars *vars, int shift, int max);
void	first_in_middle(t_vars *vars, int shift, int max);
void	first_in_end(t_vars *vars, int shift, int max);

void	sort_five(t_vars *vars);
int		sort_push_to_b(t_vars *vars, int pos, int value);

void	sort_radix(t_vars *vars);
int		count_bits(t_vars *vars);

#endif