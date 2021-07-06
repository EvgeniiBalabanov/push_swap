/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 03:32:41 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 07:16:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_num_a_to_triangle(t_process *process, t_group *group_in_a)
{
	t_number	*number;

	while (group_in_a->numbers && \
			process->stack_a.triangle.count + 1 == group_in_a->numbers->index)
	{
		number = ft_group_del_front(group_in_a);
		ft_group_add_back(&process->stack_a.triangle, number);
		ft_addmove(process, CMD_RA);
		group_in_a->min_index++;
	}
}

int	ft_num_b_to_triangle(t_process *process, t_number *number)
{
	if (process->stack_a.triangle.count + 1 == number->index)
	{
		ft_group_add_back(&process->stack_a.triangle, number);
		ft_addmove(process, CMD_PA);
		ft_addmove(process, CMD_RA);
		process->group_stack_b.min_index++;
		return (1);
	}
	return (0);
}

static int	ft_send_to_a(\
						t_process *process, \
						t_group *group_in_a, \
						t_number *number, \
						size_t *need)
{
	if (number->index >= process->group_stack_b.med_index)
	{
		ft_group_add_front(group_in_a, number);
		ft_addmove(process, CMD_PA);
		need--;
		return (1);
	}
	return (0);
}

void	ft_logic_from_b(t_process *process)
{
	t_group		*group_in_a;
	t_number	*number;
	size_t		count;
	size_t		need;

	group_in_a = ft_from_b_first_part(process);
	count = process->group_stack_b.count;
	need = process->group_stack_b.max_index - \
		process->group_stack_b.med_index + 1;
	while (count-- && need)
	{
		ft_num_a_to_triangle(process, group_in_a);
		number = ft_group_del_front(&process->group_stack_b);
		if (!ft_num_b_to_triangle(process, number) && \
			!ft_send_to_a(process, group_in_a, number, &need))
		{
			ft_group_add_back(&process->group_stack_b, number);
			ft_addmove(process, CMD_RB);
		}
	}
	ft_from_b_setting_group(process, group_in_a);
}
