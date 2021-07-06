/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:57:37 by telron            #+#    #+#             */
/*   Updated: 2021/06/18 22:28:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_group_set_med_a(t_group *group)
{
	if (group->max_index - group->min_index > 5)
		group->med_index = \
			group->min_index + (group->max_index - group->min_index) / 3 * 2;
	else
		group->med_index = \
			group->min_index + (group->max_index - group->min_index) / 2;
}

void	ft_group_set_med_b(t_group *group)
{
	if (group->max_index - group->min_index > 5)
		group->med_index = \
			group->min_index + (group->max_index - group->min_index) / 3 * 2;
	else
		group->med_index = \
			group->min_index + (group->max_index - group->min_index) / 2;
}

static void	ft_set_min_max(t_group *group)
{
	group->min_index = 1;
	group->max_index = group->count;
}

void	ft_group_index(t_group *group)
{
	size_t		counter;
	size_t		counter_cmp;
	t_number	*now;
	t_number	*num_cmp;

	if (!group->count)
		return ;
	ft_set_min_max(group);
	now = group->numbers;
	counter = 0;
	while (counter < group->count)
	{
		counter_cmp = 0;
		num_cmp = group->numbers;
		while (counter_cmp < group->count)
		{
			if (counter != counter_cmp && now->value > num_cmp->value)
				now->index++;
			num_cmp = (t_number *)num_cmp->transport.right;
			counter_cmp++;
		}
		now = (t_number *)now->transport.right;
		counter++;
	}
	ft_group_set_med_a(group);
}
