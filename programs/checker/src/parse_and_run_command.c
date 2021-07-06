/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_run_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 04:05:43 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 13:48:19 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_set_counter(void *cmd[][2], char *line, size_t *counter)
{
	*counter = 0;
	while (cmd[*counter][0])
	{
		if (!ft_strcmp(cmd[*counter][0], line))
			break ;
		(*counter)++;
	}
}

static void	ft_parse_and_run_command_run(t_process *process, void *cmd[][2])
{
	char		*line;
	int			code;
	size_t		counter;

	code = 1;
	while (code > 0)
	{
		code = ft_read_line(&line);
		if (code == -1)
			ft_exit(process, "malloc error");
		if (!code && !ft_strlen(line))
		{
			free(line);
			return ;
		}
		ft_set_counter(cmd, line, &counter);
		free(line);
		if (!cmd[counter][0])
			ft_exit(process, "bad command");
		((t_ft_cmd)cmd[counter][1])(process);
		ft_show_process(process);
	}
}

void	ft_parse_and_run_command(t_process *process)
{
	static void	*cmd[][2] = {{"pa", ft_command_pa}, {"pb", ft_command_pb}, \
		{"sa", ft_command_sa}, {"sb", ft_command_sb}, {"ss", ft_command_ss}, \
		{"ra", ft_command_ra}, {"rb", ft_command_rb}, {"rr", ft_command_rr}, \
		{"rra", ft_command_rra}, {"rrb", ft_command_rrb}, \
		{"rrr", ft_command_rrr}, {0, 0}};

	ft_show_process(process);
	ft_parse_and_run_command_run(process, cmd);
}
