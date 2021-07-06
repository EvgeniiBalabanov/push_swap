/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:03:25 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 11:35:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_putnbr(t_process *process, int num)
{
	char	arr[15];
	int		counter_arr;
	int		positive;
	int		result;

	counter_arr = 14;
	arr[counter_arr--] = 0;
	positive = -1 + (num >= 0) * 2;
	if (!num)
		arr[counter_arr--] = '0';
	while (num)
	{
		arr[counter_arr--] = num % 10 * positive + '0';
		num /= 10;
	}
	if (positive == -1)
		arr[counter_arr--] = '-';
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_YELLOW, 1);
	result = write(1, arr + counter_arr + 1, ft_strlen(arr + counter_arr + 1));
	if (process->attributes & FLAG_COLOR)
		ft_putstr_fd(COLOR_NEUTRAL, 1);
	return (result);
}

static void	ft_print_cell(t_process *process, t_list **list_number_a)
{
	int	count_space;

	if (*list_number_a)
	{
		count_space = 11 - ft_putnbr(process, \
			((t_data *)(*list_number_a)->content)->value);
		while (count_space-- > 0)
			write(1, " ", 1);
		*list_number_a = (*list_number_a)->next;
	}
	else
		ft_putstr_fd("           ", 1);
	ft_putstr_fd("|", 1);
}

void	ft_show_process(t_process *process)
{
	t_list	*list_number_a;
	t_list	*list_number_b;
	int		count_space;

	if (!(process->attributes & FLAG_VISUAL))
		return ;
	list_number_a = process->a;
	list_number_b = process->b;
	ft_putendl_fd("._______________________________.", 1);
	ft_putendl_fd("| Stack |     A     |     B     |", 1);
	ft_putendl_fd("[-------+-----------+-----------]", 1);
	ft_putendl_fd("|       |   value   |   value   |", 1);
	ft_putendl_fd("[-------+-----------+-----------]", 1);
	while (list_number_a || list_number_b)
	{
		ft_putstr_fd("|       |", 1);
		ft_print_cell(process, &list_number_a);
		ft_print_cell(process, &list_number_b);
		write(1, "\n", 1);
	}
	ft_putendl_fd("._______|___________|___________.", 1);
}
