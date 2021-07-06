/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:41:57 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:22:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_rra(t_process *process)
{
	t_list	*first;
	t_list	*second;

	first = process->a;
	if (first && first->next)
	{
		second = first->next;
		while (second->next)
		{
			first = second;
			second = second->next;
		}
		first->next = 0;
		ft_lstadd_front(&process->a, second);
	}
}
