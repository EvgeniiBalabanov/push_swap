/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 01:20:56 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 06:46:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_suddenly_rotate_up(t_process *process)
{
	t_group		*group_in_a;
	t_number	*number;

	group_in_a = process->stack_a.groups->content;
	number = group_in_a->numbers;
	while (!process->stack_a.triangle.count && \
			!process->stack_a.buffer.count && \
			1 == ft_lstsize(process->stack_a.groups) && \
			group_in_a->count >= 1 && \
			number->index <= group_in_a->med_index && \
			((t_number *)group_in_a->numbers->transport.left)->index + 1 == \
				number->index)
	{
		ft_group_transfer_fb(group_in_a, group_in_a);
		ft_addmove(process, CMD_RRA);
	}
}

static int	ft_send_to_sorted_list(\
						t_process *process, \
						t_number *number, \
						size_t *need)
{
	t_group	*group_in_a;

	group_in_a = process->stack_a.groups->content;
	if (process->stack_a.triangle.count && \
		!process->stack_a.buffer.count && \
		process->stack_a.triangle.count + 1 == number->index)
	{
		ft_group_add_back(&process->stack_a.triangle, number);
		ft_addmove(process, CMD_RA);
		group_in_a->min_index++;
		(*need)--;
		return (1);
	}
	return (0);
}

static int	ft_send_to_b(\
						t_process *process, \
						t_number *number, \
						size_t *need)
{
	t_group	*group_in_a;

	group_in_a = process->stack_a.groups->content;
	if (number->index <= group_in_a->med_index)
	{
		ft_group_add_front(&process->group_stack_b, number);
		ft_addmove(process, CMD_PB);
		(*need)--;
		return (1);
	}
	return (0);
}

static void	ft_send_to_back(\
						t_process *process, \
						t_number *number)
{
	t_group		*group_in_a;

	group_in_a = process->stack_a.groups->content;
	if (!process->stack_a.triangle.count && \
		!process->stack_a.buffer.count && \
		1 == ft_lstsize(process->stack_a.groups))
		ft_group_add_back(group_in_a, number);
	else
		ft_group_add_back(&process->stack_a.buffer, number);
	ft_addmove(process, CMD_RA);
}

void	ft_logic_from_a(t_process *process)
{
	t_group		*group_in_a;
	t_number	*number;
	size_t		counter;
	size_t		need;

	group_in_a = process->stack_a.groups->content;
	counter = group_in_a->count;
	need = group_in_a->med_index - group_in_a->min_index + 1;
	while (counter-- && need)
	{
		ft_suddenly_rotate_up(process);
		number = ft_group_del_front(group_in_a);
		if (!ft_send_to_sorted_list(process, number, &need) && \
			!ft_send_to_b(process, number, &need))
			ft_send_to_back(process, number);
	}
	ft_from_a_last_part(process);
	process->group_stack_b.min_index = group_in_a->min_index;
	process->group_stack_b.max_index = group_in_a->med_index;
	ft_group_set_med_b(&process->group_stack_b);
	group_in_a->min_index = group_in_a->med_index + 1;
	ft_group_set_med_a(group_in_a);
}
