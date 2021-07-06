/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:08:45 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:17:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_STRUCTS_H
# define CHECKER_STRUCTS_H

# include "list.h"

# define	FLAG_VISUAL	0b01
# define	FLAG_COLOR	0b10

typedef struct s_data
{
	int			value;
}				t_data;

typedef struct s_process
{
	char		attributes;
	t_list		*a;
	t_list		*b;
}				t_process;

#endif
