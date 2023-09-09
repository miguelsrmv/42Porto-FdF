/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:38:00 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/19 14:56:50 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** DESCRIPTION: Iterates the list and applies the function ’f’ on the content 
**				of each node. Creates a new list resulting of the successive
**				applications of the function ’f’. The ’del’ function is used 
**				to delete the content of a node if needed.
**  			lst: The address of a pointer to a node.
**  			f: The address of the function used to iterate on the list.
**  			del: The address of the function used to delete the content 
**				of a node (if needed).
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_node;

	new_list = NULL;
	while (lst)
	{
		temp_node = ft_lstnew(f(lst->content));
		if (!temp_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp_node);
		lst = lst->next;
	}
	return (new_list);
}
