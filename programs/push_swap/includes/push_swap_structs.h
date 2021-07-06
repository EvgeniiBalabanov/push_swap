/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:04:51 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 10:45:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include "dlist.h"

typedef struct s_number
{
	t_dlist		transport;
	int			value;
	ssize_t		index;
}				t_number;

typedef struct s_group
{
	t_number	*numbers;
	char		attribute;
	size_t		count;
	int			min_index;
	int			med_index;
	int			max_index;
}				t_group;

typedef struct s_stack
{
	char		attribute;
	t_list		*groups;
	t_group		triangle;
	t_group		buffer;
}				t_stack;

typedef struct s_rorate_buffer
{
	char		base_rotate;
	char		all_rotate;
	int			count_iter;
	void		(*ft_transfer)(t_group *, t_group *);
}				t_rorate_buffer;

typedef struct s_move
{
	int			command[1000000];
	int			count;
}				t_move;

typedef struct s_process
{
	t_stack		stack_a;
	t_group		group_stack_b;
	t_move		moves;
}				t_process;

#endif