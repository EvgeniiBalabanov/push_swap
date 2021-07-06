/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:41:13 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:19:27 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_pb(t_process *process)
{
	t_list	*new_first_in_a;

	if (process->a)
	{
		new_first_in_a = process->a->next;
		ft_lstadd_front(&process->b, process->a);
		process->a = new_first_in_a;
	}
}
