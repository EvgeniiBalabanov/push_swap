/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:21:34 by telron            #+#    #+#             */
/*   Updated: 2021/06/06 07:31:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list.h"
# include "libft.h"
# include "push_swap_structs.h"
# include <stdlib.h>

# define CMD_PA 1
# define CMD_PB 2
# define CMD_SA 3
# define CMD_SB 4
# define CMD_SS 5
# define CMD_RA 6
# define CMD_RB 7
# define CMD_RR 8
# define CMD_RRA 9
# define CMD_RRB 10
# define CMD_RRR 11

int			main(int count_argums, const char **argums);

void		ft_exit(t_process *process, const char *error_msg);

void		ft_parse_argums(\
					t_process *process, \
					int count_argums, \
					const char **argums);

void		ft_start(t_process *process);

void		ft_addmove(t_process *process, int command);

void		ft_group_add_back(t_group *group, t_number *number);
void		ft_group_add_front(t_group *group, t_number *number);
t_group		*ft_group_create(void);
t_number	*ft_group_del_back(t_group *group);
t_number	*ft_group_del_front(t_group *group);
void		ft_group_index(t_group *group);
int			ft_group_swap(t_group *group);
void		ft_group_set_med_a(t_group *group);
void		ft_group_set_med_b(t_group *group);
void		ft_group_delone(t_group *group, void (*ft_free_for_group)(void *));
void		ft_del_first_group(t_process *process, t_group *first_group_a);

int			ft_logic_check_finish(t_process *process);
void		ft_logic_from_a(t_process *process);
void		ft_from_a_last_part(t_process *process);
void		ft_logic_from_b(t_process *process);
void		ft_from_b_setting_group(t_process *process, t_group *group_in_a);
t_group		*ft_from_b_first_part(t_process *process);
void		ft_logic_clean_group(t_process *process);

t_number	*ft_number_create(int value);
void		ft_number_round(t_number *number);

void		ft_optim(t_process *process);
void		ft_del_many_ra(t_process *process);

void		ft_group_transfer_ff(t_group *destination, t_group *source);
void		ft_group_transfer_fb(t_group *destination, t_group *source);
void		ft_group_transfer_bf(t_group *destination, t_group *source);
void		ft_group_transfer_bb(t_group *destination, t_group *source);

#endif
