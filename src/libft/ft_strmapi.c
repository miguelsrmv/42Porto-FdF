/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:22:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 08:50:18 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION: Applies the function ’f’ to each character of the
** string ’s’, and passing its index as first argument
** to create a new string (with malloc(3)) resulting
** from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;
	size_t			length;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	newstr = malloc(length * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
