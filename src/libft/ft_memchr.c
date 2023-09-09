/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:58:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 08:22:10 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARY: <string.h>
**	DESCRIPTION: The memchr() function scans the initial "n" bytes
**	of the memory area pointed to by "s" for the first instance of "c".
**	Both "c" and the bytes of the memory area
**	pointed to by "s" are interpreted as unsigned char.
** 	The memchr() function locates the first occurrence 
**  of "c" (converted to an unsigned char) in string "s".
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	unsigned char	c_cast;
	size_t			i;

	s_cast = (unsigned char *)s;
	c_cast = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == c_cast)
			return ((void *)(s_cast + i));
		i++;
	}
	return (NULL);
}
