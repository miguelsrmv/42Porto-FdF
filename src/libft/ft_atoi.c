/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:13:41 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:26:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <stdlib.h>
** SYNOPSIS: Convert a string into an integer
** DESCRIPTION: converts the initial portion of the string pointed to by str 
** 				to in
** RETURN VALUE: The converted value or 0 on error.
*/

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		n;

	n = 0;
	sign = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	return (n * sign);
}
