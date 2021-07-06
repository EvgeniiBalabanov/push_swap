/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:59:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 04:36:25 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*ft_number_create(int value)
{
	t_number	*number;

	number = ft_calloc(1, sizeof(t_number));
	if (number)
	{
		ft_number_round(number);
		number->transport.content = number;
		number->value = value;
		number->index = 1;
	}
	return (number);
}
