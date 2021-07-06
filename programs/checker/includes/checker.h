/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:26:34 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 11:32:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "list.h"
# include "dlist.h"
# include "checker_structs.h"
# include "command.h"

# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_YELLOW "\033[1;33m"
# define COLOR_NEUTRAL "\033[0m"

int			main(int count_argums, const char **argums);

void		ft_exit(t_process *process, const char *error_msg);

void		ft_parse_argums(\
					t_process *process, \
					int count_argums, \
					const char **argums);

void		ft_parse_and_run_command(\
					t_process *process);

void		ft_print_result(t_process *process);

void		ft_show_process(t_process *process);

int			ft_read_line(char **string);

#endif
