/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:57:16 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:26:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <ctype.h>
** SYNOPSIS: alphanumeric character test
** DESCRIPTION: The isalnum() function tests for any 
** 				character for which isalpha or isdigit is true.
*/

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
