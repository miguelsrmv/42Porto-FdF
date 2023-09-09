/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:52:30 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:26:29 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <ctype.h>
** SYNOPSIS: alphabetic character test
** DESCRIPTION:	The isalpha() function tests for any
**				character for which isupper(3) or islower(3) is true.
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
