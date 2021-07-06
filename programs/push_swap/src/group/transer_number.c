/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transer_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:53:36 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 08:59:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_group_transfer_ff(t_group *destination, t_group *source)
{
	t_number	*number;

	number = ft_group_del_front(source);
	ft_group_add_front(destination, number);
}

void	ft_group_transfer_fb(t_group *destination, t_group *source)
{
	t_number	*number;

	number = ft_group_del_back(source);
	ft_group_add_front(destination, number);
}

void	ft_group_transfer_bf(t_group *destination, t_group *source)
{
	t_number	*number;

	number = ft_group_del_front(source);
	ft_group_add_back(destination, number);
}

void	ft_group_transfer_bb(t_group *destination, t_group *source)
{
	t_number	*number;

	number = ft_group_del_back(source);
	ft_group_add_back(destination, number);
}
