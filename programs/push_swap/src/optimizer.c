/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 03:03:52 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 04:16:50 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_int_arr_len(int *arr)
{
	int	result;

	result = 0;
	while (arr[result])
		result++;
	return (result);
}

static int	ft_check_comb(t_process *process, \
						int comb_left[4], \
						int comb_right[4], \
						int counter_move)
{
	int	len_left;
	int	len_right;

	len_left = ft_int_arr_len(comb_left);
	len_right = ft_int_arr_len(comb_right);
	if (!ft_memcmp(process->moves.command + counter_move, \
				comb_left, sizeof(int) * len_left))
	{
		ft_memmove(process->moves.command + counter_move + len_right, \
			process->moves.command + counter_move + len_left, \
			sizeof(int) * (process->moves.count - counter_move - len_left));
		ft_memmove(process->moves.command + counter_move, \
			comb_right, sizeof(int) * len_right);
		process->moves.count -= len_left - len_right;
		ft_optim(process);
		return (1);
	}
	return (0);
}

static void	ft_optim_run(t_process *process, int comb[][2][4])
{
	int	counter_move;
	int	counter_comb;
	int	len_left;
	int	len_right;

	counter_move = 0;
	while (counter_move < process->moves.count)
	{
		counter_comb = 0;
		while (comb[counter_comb][0][0])
		{
			if (ft_check_comb(process, comb[counter_comb][0], \
					comb[counter_comb][1], counter_move))
				break ;
			counter_comb++;
		}
		counter_move++;
	}
}

void	ft_optim(t_process *process)
{
	static int	comb[][2][4] = {{{CMD_PA, CMD_PB, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_PB, CMD_PA, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_SA, CMD_SA, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_SB, CMD_SB, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_RA, CMD_RRA, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_RRA, CMD_RA, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_RRB, CMD_RB, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_RB, CMD_RRB, 0, 0}, {0, 0, 0, 0}}, \
					{{CMD_RA, CMD_RB, 0, 0}, {CMD_RR, 0, 0, 0}}, \
					{{CMD_RRA, CMD_RRB, 0, 0}, {CMD_RRR, 0, 0, 0}}, \
					{{CMD_SA, CMD_RA, CMD_PB, 0}, {CMD_PB, CMD_RA, 0, 0}}, \
					{{CMD_PB, CMD_RA, CMD_PA, 0}, {CMD_SA, CMD_RA, 0, 0}}, \
					{{CMD_PA, CMD_RB, CMD_PB, 0}, {CMD_SB, CMD_RB, 0, 0}}, \
					{{0, 0, 0, 0}, {0, 0, 0, 0}}};

	ft_optim_run(process, comb);
}

void	ft_del_many_ra(t_process *process)
{
	int		count_number;
	int		counter;

	counter = process->moves.count;
	count_number = process->stack_a.triangle.count;
	while (counter--)
	{
		if (process->moves.command[counter] != CMD_RA || !--count_number)
			break ;
	}
	if (!count_number)
		process->moves.count -= process->stack_a.triangle.count;
}
