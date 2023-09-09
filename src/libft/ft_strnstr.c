/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:13:07 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 08:51:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARY: <string.h>
** SYNOPSIS: find a substring within a string
** DESCRIPTION: searches for the first occurrence of a
** null-terminated string needle within another null-terminated
** string haystack, but only up to the first len characters of haystack.
** If needle is an empty string, haystack is returned;
** if needle does not occur in haystack, NULL is returned;
** otherwise, a pointer to the first character of the first occurrence
** of needle is returned.
** Both haystack and needle must be null-terminated strings.
** If either haystack or needle is NULL, the function returns NULL.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == *little)
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] && (i + j) < len)
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
