/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:28:59 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:26:53 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <strings.h>
** SYNOPSIS: write zeroes to a byte string
** DESCRIPTION: The bzero() function writes n zeroes bytes to the string s. ~
** 				If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;

	s_cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_cast[i] = '\0';
		i++;
	}
	return ;
}
