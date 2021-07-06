/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:07:19 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:38:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_number_round(t_number *number)
{
	if (number)
	{
		number->transport.left = (t_dlist *)number;
		number->transport.right = (t_dlist *)number;
	}
}
