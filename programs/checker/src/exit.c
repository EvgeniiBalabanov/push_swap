/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:50:58 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 13:54:54 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_free_heap(t_process *process)
{
	ft_lstclear(&process->a, free);
	ft_lstclear(&process->b, free);
}

void	ft_exit(t_process *process, const char *error_msg)
{
	int		exit_code;

	exit_code = 0;
	if (error_msg)
	{
		ft_putendl_fd(error_msg, 2);
		ft_putendl_fd("Error", 2);
	}
	ft_free_heap(process);
	exit(exit_code);
}
