/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:17:19 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 08:06:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_push_sort_part(t_process *process, t_number *number, int count)
{
	t_group	*group_in_a;

	group_in_a = process->stack_a.groups->content;
	while (count-- > 0)
	{
		number = ft_group_del_back(group_in_a);
		ft_group_add_front(&process->stack_a.triangle, number);
	}
}

static void	ft_has_sorted(t_process *process)
{
	t_number	*number;
	t_group		*group_in_a;
	int			last_index;
	int			count;

	group_in_a = process->stack_a.groups->content;
	if (!group_in_a->count)
		return ;
	number = (t_number *)group_in_a->numbers->transport.left;
	last_index = 0;
	count = 0;
	while (number && last_index != 1 && count < group_in_a->count)
	{
		if (number->index + 1 == last_index || !last_index)
		{
			count++;
			last_index = number->index;
		}
		else
			return ;
		number = (t_number *)number->transport.left->content;
	}
	ft_push_sort_part(process, number, count);
}

int	ft_group_is_sort(t_group *group)
{
	int			counter;
	t_number	*number;
	int			index;

	counter = 0;
	number = group->numbers;
	while (counter + 1 < group->max_index)
	{
		index = number->index;
		number = (t_number *)number->transport.right;
		if (index > number->index)
			return (0);
		counter++;
	}
	return (1);
}

void	ft_start(t_process *process)
{
	t_group	*group;
	int		len;

	group = (t_group *)process->stack_a.groups->content;
	len = group->max_index - group->min_index + 1;
	if (len == 1)
		return ;
	ft_has_sorted(process);
	while (!ft_logic_check_finish(process))
	{
		ft_logic_from_a(process);
		while (process->group_stack_b.count)
			ft_logic_from_b(process);
		ft_logic_clean_group(process);
	}
}
