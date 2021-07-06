/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:50:58 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 14:01:27 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_heap(t_process *process)
{
	t_list	*begin;

	begin = process->stack_a.groups;
	while (begin)
	{
		ft_group_delone(begin->content, free);
		begin->content = 0;
		begin = begin->next;
	}
	ft_lstclear(&process->stack_a.groups, 0);
	ft_group_delone(&process->group_stack_b, 0);
	ft_group_delone(&process->stack_a.triangle, 0);
}

void	ft_exit(t_process *process, const char *error_msg)
{
	int		exit_code;

	exit_code = 0;
	if (error_msg)
	{
		ft_putendl_fd(error_msg, 2);
		ft_putendl_fd("Error", 2);
	}
	ft_free_heap(process);
	exit(exit_code);
}
