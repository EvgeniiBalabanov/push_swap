/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_setting_group.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 06:43:56 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 06:45:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_from_b_setting_group(t_process *process, t_group *group_in_a)
{
	group_in_a->min_index = process->group_stack_b.med_index;
	if (group_in_a->min_index < process->stack_a.triangle.count + 1)
		group_in_a->min_index = process->stack_a.triangle.count + 1;
	group_in_a->max_index = process->group_stack_b.max_index;
	ft_group_set_med_a(group_in_a);
	if (process->group_stack_b.count)
	{
		process->group_stack_b.max_index = group_in_a->min_index + 1;
		ft_group_set_med_b(&process->group_stack_b);
	}
}
