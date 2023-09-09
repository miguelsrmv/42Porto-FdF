/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:33:11 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 08:27:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  LIBRARY: <string.h>
**  DESCRIPTION: The memcpy() function copies n bytes from memory area src 
**  to memory area dest.  The memory areas must
**  not overlap.  Use memmove(3) if the memory areas do overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	if (src == NULL && dest == NULL)
		return (NULL);
	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest);
}
