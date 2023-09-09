/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:52:59 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:27:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
** DESCRIPTION: Takes as a parameter a node and frees the memory of the node’s 
** 				content using the function ’del’ given as a parameter and free 
**				the node. The memory of ’next’ must not be freed.
**				lst: The note to free
**				del: The adress of the function used to delete the content.
**				Return Value: None
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(del)(lst->content);
	free(lst);
}
