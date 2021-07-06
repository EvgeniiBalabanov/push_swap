/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:17:55 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 09:59:32 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_finish(char **string, char **tail, ssize_t cnt)
{
	if (cnt == -1)
		free(*tail);
	else
	{
		*string = *tail;
		*tail = 0;
	}
}

int	ft_read_line(char **string)
{
	static char	*tail = 0;
	char		buffer[2];
	char		*pnt;
	ssize_t		cnt;

	if (!tail)
		tail = ft_strdup("");
	if (!tail)
		return (-1);
	buffer[1] = '\0';
	while (1)
	{
		cnt = read(0, buffer, 1);
		if (cnt < 1 || buffer[0] == '\n')
			break ;
		pnt = tail;
		tail = ft_strjoin(tail, buffer);
		free(pnt);
		if (!tail)
			return (-1);
	}
	ft_finish(string, &tail, cnt);
	return (cnt);
}
