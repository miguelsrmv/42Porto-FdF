/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:57:45 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 12:01:14 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_tolower(char *str)
{
	char	*lower_str;
	int		i;

	if (!str)
		return (NULL);
	lower_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!lower_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			lower_str[i] = ft_tolower(str[i]);
		else
			lower_str[i] = str[i];
		i++;
	}
	lower_str[i] = '\0';
	return (lower_str);
}
