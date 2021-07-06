/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:52:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:15:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "checker_structs.h"

typedef void (*t_ft_cmd)(t_process *);

void			ft_command_pa(t_process *process);
void			ft_command_pb(t_process *process);
void			ft_command_sa(t_process *process);
void			ft_command_sb(t_process *process);
void			ft_command_ss(t_process *process);
void			ft_command_ra(t_process *process);
void			ft_command_rb(t_process *process);
void			ft_command_rr(t_process *process);
void			ft_command_rra(t_process *process);
void			ft_command_rrb(t_process *process);
void			ft_command_rrr(t_process *process);

#endif
