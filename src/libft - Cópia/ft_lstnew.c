/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:46:30 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:29:40 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION: Allocates (with malloc(3)) and returns a “fresh” link. The 
**				variables content and content_size of the new link are 
**				initialized by a copy of the parameters of the function. If 
**				the parameter content is null, the variable content is 
**				initialized to NULL and the variable content_size is 
**				initialized to 0 even if the parameter content_size isn’t.
**				The variable next is initialized to NULL. If the allocation 
**				fails, the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
