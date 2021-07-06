/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 04:05:24 by telron            #+#    #+#             */
/*   Updated: 2021/06/04 05:12:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (argum[counter] || (positive == -1 && !result))
		ft_exit(process, "bad argument");
	return (result * positive);
}

static t_list	*ft_create_data(t_process *process, const char *argum)
{
	t_list	*result;
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_exit(process, "malloc error");
	data->value = ft_atoi_argum(process, argum);
	result = ft_lstnew(data);
	if (!result)
	{
		free(data);
		ft_exit(process, "malloc error");
	}
	return (result);
}

static void	ft_add_argum_in_stack(t_process *process, const char *argum)
{
	t_list	*data;
	t_list	*now;

	data = ft_create_data(process, argum);
	now = process->a;
	if (!now)
		process->a = data;
	while (now)
	{
		if (((t_data *)now->content)->value == ((t_data *)data->content)->value)
			ft_exit(process, "2 identical values");
		if (!now->next)
		{
			now->next = data;
			break ;
		}
		now = now->next;
	}
}

void	ft_parse_argums(\
					t_process *process, \
					int count_argums, \
					const char **argums)
{
	size_t	counter;

	if (count_argums <= 1)
		ft_exit(process, 0);
	counter = 1;
	while (counter < count_argums)
	{
		if (!ft_strcmp("-c", argums[counter]))
			process->attributes |= FLAG_COLOR;
		else if (!ft_strcmp("-v", argums[counter]))
			process->attributes |= FLAG_VISUAL;
		else
			ft_add_argum_in_stack(process, argums[counter]);
		counter++;
	}
}
