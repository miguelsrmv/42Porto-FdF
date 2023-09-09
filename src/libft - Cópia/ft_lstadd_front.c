/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:01:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:24:48 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  DESCRIPTION: 
**  Adds the 'new' element at the beginning of the list.
**  Param. #1 The address of a pointer to the first link of a list.
**  Param. #2 The link to add at the beginning of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
