/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:41:46 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:34:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_rb(t_process *process)
{
	t_list	*first;
	t_list	*second;

	first = process->b;
	if (first && first->next)
	{
		second = first->next;
		ft_lstlast(second)->next = first;
		first->next = 0;
		process->b = second;
	}
}
