/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:01:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:29:59 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
** DESCRIPTION: Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			list_size;

	list_size = 0;
	while (lst)
	{
		lst = lst->next;
		list_size++;
	}
	return (list_size);
}
