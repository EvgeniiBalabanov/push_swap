/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:16:07 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 08:20:20 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_new_number_in_triangle(t_process *process)
{
	t_group		*first_group_a;

	first_group_a = process->stack_a.groups->content;
	ft_group_transfer_bf(&process->stack_a.triangle, first_group_a);
	ft_addmove(process, CMD_RA);
}

static void	ft_del_3_element(t_group *first_group_a, t_number *numbers[3])
{
	numbers[0] = ft_group_del_front(first_group_a);
	numbers[1] = ft_group_del_front(first_group_a);
	numbers[2] = ft_group_del_front(first_group_a);
}

static void	ft_group_has_3_elem(t_process *process)
{
	t_group		*first_group_a;
	t_number	*numbers[3];

	first_group_a = process->stack_a.groups->content;
	ft_del_3_element(first_group_a, numbers);
	ft_addmove(process, CMD_PB);
	ft_addmove(process, CMD_SA);
	ft_addmove(process, CMD_RA);
	ft_group_add_back(&process->stack_a.triangle, numbers[2]);
	if (numbers[0]->index > numbers[1]->index)
	{
		ft_addmove(process, CMD_RA);
		ft_addmove(process, CMD_PA);
		ft_group_add_back(&process->stack_a.triangle, numbers[1]);
		ft_group_add_back(&process->stack_a.triangle, numbers[0]);
	}
	else
	{
		ft_addmove(process, CMD_PA);
		ft_addmove(process, CMD_RA);
		ft_group_add_back(&process->stack_a.triangle, numbers[0]);
		ft_group_add_back(&process->stack_a.triangle, numbers[1]);
	}
	ft_addmove(process, CMD_RA);
}

void	ft_logic_clean_group(t_process *process)
{
	t_group	*first_group_a;

	first_group_a = process->stack_a.groups->content;
	while (first_group_a->count)
	{
		if (process->stack_a.triangle.count + 1 == \
			first_group_a->numbers->index)
			ft_new_number_in_triangle(process);
		else if (process->stack_a.triangle.count + 1 == \
			((t_number *)first_group_a->numbers->transport.right)->index)
		{
			ft_group_swap(first_group_a);
			ft_addmove(process, CMD_SA);
		}
		else if (first_group_a->count <= 3)
			ft_group_has_3_elem(process);
		else
			return ;
	}
	ft_del_first_group(process, first_group_a);
	if (process->stack_a.groups)
		ft_logic_clean_group(process);
}
