/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:57:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:26:31 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <ctype.h>
** SYNOPSIS: test for ASCII character
** DESCRIPTION: The isascii() function tests for an ASCII character,
** 				which is any character between 0 and 127.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
