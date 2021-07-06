/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_last_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:48:33 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 06:46:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(t_process *process)
{
	t_list	*group;
	int		result;

	result = 0;
	group = process->stack_a.groups;
	while (group)
	{
		result += ((t_group *)group->content)->count;
		group = group->next;
	}
	result += process->stack_a.triangle.count;
	return (result);
}

static void	ft_set_rorate_buffer(t_rorate_buffer *rorate_buffer, int main_iter)
{
	rorate_buffer->base_rotate = CMD_RA;
	rorate_buffer->all_rotate = CMD_RR;
	rorate_buffer->ft_transfer = ft_group_transfer_bf;
	if (rorate_buffer->count_iter > main_iter)
	{
		rorate_buffer->count_iter = main_iter;
		rorate_buffer->base_rotate = CMD_RRA;
		rorate_buffer->all_rotate = CMD_RRR;
		rorate_buffer->ft_transfer = ft_group_transfer_fb;
	}
}

void	ft_from_a_last_part(t_process *process)
{
	t_rorate_buffer	rorate_buffer;

	rorate_buffer.count_iter = ft_count(process);
	ft_set_rorate_buffer(&rorate_buffer, process->stack_a.buffer.count);
	while (process->stack_a.buffer.count)
		ft_group_transfer_fb((t_group *)process->stack_a.groups->content, \
			&process->stack_a.buffer);
	while (rorate_buffer.count_iter--)
	{
		if (process->group_stack_b.numbers && \
			process->stack_a.triangle.count + 1 != \
			process->group_stack_b.numbers->index)
		{
			rorate_buffer.ft_transfer(&process->group_stack_b, \
				&process->group_stack_b);
			ft_addmove(process, rorate_buffer.all_rotate);
		}
		else
			ft_addmove(process, rorate_buffer.base_rotate);
	}
}
