/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:11:48 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:41:57 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*ft_group_del_front(t_group *group)
{
	t_number	*new_begin;
	t_number	*result;

	if (!group->count)
		return (0);
	result = group->numbers;
	new_begin = (t_number *)result->transport.right;
	ft_dlstrelation(result->transport.left, (t_dlist *)new_begin);
	ft_number_round(result);
	if (group->count > 1)
		group->numbers = new_begin;
	else
		group->numbers = 0;
	group->count--;
	return (result);
}
