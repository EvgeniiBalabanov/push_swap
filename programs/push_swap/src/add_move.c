/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:28:05 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:42:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addmove(t_process *process, int command)
{
	process->moves.command[process->moves.count++] = command;
}
