/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 04:06:19 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 11:39:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_print_fail(t_process *process)
{
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_RED, 1);
	ft_putstr_fd("KO", 1);
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_NEUTRAL, 1);
	write(1, "\n", 1);
}

static void	ft_print_success(t_process *process)
{
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_GREEN, 1);
	ft_putstr_fd("OK", 1);
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_NEUTRAL, 1);
	write(1, "\n", 1);
}

void	ft_print_result(t_process *process)
{
	t_list	*now;

	if (process->b)
	{
		ft_print_fail(process);
		return ;
	}
	now = process->a;
	while (now && now->next)
	{
		if (((t_data *)now->content)->value > \
			((t_data *)now->next->content)->value)
		{
			ft_print_fail(process);
			return ;
		}
		now = now->next;
	}
	ft_print_success(process);
}
