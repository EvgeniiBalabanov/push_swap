/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:31:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 10:51:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int count_argums, const char **argums)
{
	t_process	process;

	ft_bzero(&process, sizeof(t_process));
	ft_parse_argums(&process, count_argums, argums);
	ft_parse_and_run_command(&process);
	ft_print_result(&process);
	ft_exit(&process, 0);
	return (0);
}
