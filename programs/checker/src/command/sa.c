/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:40:17 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:24:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_sa(t_process *process)
{
	t_list	*first;
	t_list	*second;

	first = process->a;
	if (first && first->next)
	{
		second = first->next;
		first->next = second->next;
		second->next = first;
		process->a = second;
	}
}
