/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:41:16 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:18:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_pa(t_process *process)
{
	t_list	*new_first_in_b;

	if (process->b)
	{
		new_first_in_b = process->b->next;
		ft_lstadd_front(&process->a, process->b);
		process->b = new_first_in_b;
	}
}
