/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:29:37 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:37:32 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_group_add_front(t_group *group, t_number *number)
{
	if (group->count)
	{
		ft_dlstrelation(group->numbers->transport.left, (t_dlist *)number);
		ft_dlstrelation((t_dlist *)number, (t_dlist *)group->numbers);
	}
	else
		ft_number_round(number);
	group->numbers = number;
	group->count++;
}
