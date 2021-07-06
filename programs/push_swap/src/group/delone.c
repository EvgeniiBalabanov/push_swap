/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:13:16 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 11:59:59 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_group_delone(t_group *group, void (*ft_free_for_group)(void *))
{
	int		counter;
	t_dlist	*next;
	t_dlist	*now;

	counter = 0;
	now = (t_dlist *)group->numbers;
	while (counter++ < (int)group->count && now)
	{
		next = now->right;
		free(now);
		now = next;
	}
	if (ft_free_for_group)
		ft_free_for_group(group);
}
