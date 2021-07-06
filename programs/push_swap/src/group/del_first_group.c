/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_first_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 07:28:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 07:31:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_first_group(t_process *process, t_group *first_group_a)
{
	t_list		*for_free;

	for_free = process->stack_a.groups;
	process->stack_a.groups = process->stack_a.groups->next;
	ft_lstdelone(for_free, 0);
	ft_group_delone(first_group_a, free);
}
