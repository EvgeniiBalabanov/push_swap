/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_agrums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:20:02 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:17:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_argum(t_process *process, const char *argum)
{
	size_t	counter;
	char	positive;
	long	result;

	counter = 0;
	positive = 1;
	if (argum[counter] == '-')
	{
		positive = -1;
		counter++;
	}
	result = 0;
	while (ft_isdigit(argum[counter]))
	{
		result = result * 10 + (argum[counter] - '0');
		if (result > (long)__INT32_MAX__ + (positive == -1))
			ft_exit(process, "int overflow");
		counter++;
	}
	if (argum[counter])
		ft_exit(process, "bad argument");
	return (result * positive);
}

static void	ft_has_identical_values(\
						t_process *process, \
						t_group *group, \
						t_number *new_number)
{
	size_t		counter;
	t_number	*number;

	counter = 0;
	number = group->numbers;
	while (counter++ < group->count)
	{
		if (number->value == new_number->value)
			ft_exit(process, "2 identical values");
		number = (t_number *)number->transport.right->content;
	}
}

static void	ft_add_argum_in_group(\
						t_process *process, \
						t_list *group, \
						const char *argum)
{
	int			value;
	t_number	*new_number;

	value = ft_atoi_argum(process, argum);
	new_number = ft_number_create(value);
	if (!new_number)
		ft_exit(process, "malloc error");
	ft_has_identical_values(process, group->content, new_number);
	ft_group_add_back(group->content, new_number);
}

void	ft_parse_argums(\
			t_process *process, \
			int count_argums, \
			const char **argums)
{
	size_t	counter;
	t_group	*first_group;

	if (count_argums <= 1)
		ft_exit(process, 0);
	first_group = ft_group_create();
	if (!first_group)
		ft_exit(process, "malloc error");
	if (!ft_lstadd_back_content(&process->stack_a.groups, first_group))
		ft_exit(process, "malloc error");
	counter = 1;
	while (counter < count_argums)
	{
		ft_add_argum_in_group(process, \
			process->stack_a.groups, \
			argums[counter]);
		counter++;
	}
	ft_group_index(first_group);
}
