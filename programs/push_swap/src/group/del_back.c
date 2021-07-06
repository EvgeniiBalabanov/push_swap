/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:11:45 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:43:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*ft_group_del_back(t_group *group)
{
	t_number	*result;
	t_number	*begin;

	if (!group->count)
		return (0);
	begin = group->numbers;
	result = (t_number *)begin->transport.left;
	ft_dlstrelation(result->transport.left, (t_dlist *)begin);
	ft_number_round(result);
	if (group->count == 1)
		group->numbers = 0;
	group->count--;
	return (result);
}
