/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 03:15:49 by telron            #+#    #+#             */
/*   Updated: 2021/06/14 02:15:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_moves(t_process *process)
{
	int					counter;
	static const char	*cmd[] = \
	{"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr", 0};

	counter = 0;
	while (counter < process->moves.count)
	{
		ft_putendl_fd(cmd[process->moves.command[counter] - 1], 1);
		counter++;
	}
}

int	main(int count_argums, const char *argums[])
{
	t_process	process;

	ft_bzero(&process, sizeof(t_process));
	ft_parse_argums(&process, count_argums, argums);
	ft_start(&process);
	ft_optim(&process);
	ft_del_many_ra(&process);
	ft_print_moves(&process);
	ft_exit(&process, 0);
	return (0);
}
