/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:22:24 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:45:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_group	*ft_group_create(void)
{
	t_group	*group;

	group = ft_calloc(1, sizeof(t_group));
	return (group);
}
