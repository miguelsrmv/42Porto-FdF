/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:23:05 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/07 15:01:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_input(const char *input, const char *limiter)
{
	unsigned int	i;
	unsigned int	result;
	char			*newlimiter;

	newlimiter = ft_strjoin(limiter, "\n");
	if (!newlimiter)
		return (0);
	i = 0;
	while (input[i] && newlimiter[i] && (input[i] == newlimiter[i]))
		i++;
	result = (unsigned char)input[i] - (unsigned char)newlimiter[i];
	free (newlimiter);
	return (result);
}
