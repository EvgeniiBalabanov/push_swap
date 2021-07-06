/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:38:34 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:03:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <ctype.h>
**
** 		int		isascii(int c);
** INFO:
** 		Если argument является числом
** 		в пределах от 0 до 127 включительно,
** 		которое можно итерпретировать по таблице ASCII,
** 		тогда возвращается 1, иначе 0
*/

int	ft_isascii(int argument)
{
	return (0 <= argument && argument <= 127);
}
