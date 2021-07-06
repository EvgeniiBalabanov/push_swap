/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_first_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 06:53:51 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 06:54:23 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_group	*ft_from_b_first_part(t_process *process)
{
	t_group	*new_group;

	new_group = ft_group_create();
	if (!new_group)
		ft_exit(process, "malloc error");
	if (!ft_lstadd_front_content(&process->stack_a.groups, new_group))
	{
		free(new_group);
		ft_exit(process, "malloc error");
	}
	return (new_group);
}
