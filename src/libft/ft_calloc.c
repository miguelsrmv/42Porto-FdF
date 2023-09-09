/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:23:41 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 09:23:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** LIBRARY: <stdlib.h>
** DESCRIPTION: calloc() function is used to dynamically allocate
** 				multiple blocks of memory. calloc needs two arguments.
** 				The number of blocks(size_t numb) and the size of each 
** 				block(size_t size). Memory allocated by calloc is initialized 
**				to zero. calloc return NULL when sufficient memory is not 
**				available in the heap.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;
	size_t	total_size;

	total_size = size * nmemb;
	space = malloc(total_size);
	if (space == NULL)
		return (NULL);
	ft_bzero(space, total_size);
	return (space);
}
