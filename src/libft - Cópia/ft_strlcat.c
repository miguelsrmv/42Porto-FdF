/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:21:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 08:47:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESCRIPTION:
**	strlcat() appends string src to the end of dst.
**	It will append at most dstsize strlen(dst) - 1 characters.
**	It will then NUL-terminate, unless dstsize is 0 or
**	the original dst string was longer than dstsize
**	(in practice this should not happen as it means that
**	either dstsize is incorrect or that dst is not a properstring).
**	If the src and dst strings overlap, the behavior is undefined.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	src_i;
	unsigned int	dest_i;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (size <= dest_size)
		return (src_size + size);
	src_i = 0;
	dest_i = dest_size;
	while (src[src_i] && (src_i + dest_size) < size - 1)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';
	return (dest_size + src_size);
}
