/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 02:19:02 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:38:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_group_swap(t_group *group)
{
	t_number	*last;
	t_number	*new_first;
	t_number	*new_second;
	t_number	*torshery;

	if (group->count < 2)
		return (-1);
	new_second = group->numbers;
	new_first = new_second->transport.right->content;
	last = new_second->transport.left->content;
	torshery = new_first->transport.right->content;
	if (group->count == 2)
		torshery = last;
	ft_dlstrelation((t_dlist *)last, (t_dlist *)new_first);
	ft_dlstrelation((t_dlist *)new_first, (t_dlist *)new_second);
	ft_dlstrelation((t_dlist *)new_second, (t_dlist *)torshery);
	group->numbers = new_first;
	return (0);
}
