/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:57:47 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:26:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
** DESCRIPTION: Deletes and frees the given node and every successor of that 
** 				node, using the function ’del’ and free(3). Finally, the 
**				pointer to the list must be set to NULL.
**				lst: The address of a pointer to a node.
** 				del: The address of the function used to delete the content 
**					 of the node.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)-> next;
		(del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
