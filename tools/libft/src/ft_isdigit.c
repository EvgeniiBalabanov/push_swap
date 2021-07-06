/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:33:21 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:07:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <ctype.h>
**
** 		int		isdigit(int c);
** INFO:
** 		Если argument является числом из таблицы ASCII
** 		в пределах от 48 до 57 включительно
** 		обозначающим числа [0123456789]
** 		тогда возвращается 1, иначе 0
*/

int	ft_isdigit(int argument)
{
	return ('0' <= argument && argument <= '9');
}