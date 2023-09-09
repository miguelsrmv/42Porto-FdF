/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:46:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/18 10:23:52 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION: Allocates (with malloc(3)) and returns an array of strings 
** 				obtained by splitting ’s’ using the character ’c’ as a 
**				delimiter. The array must end with a NULL pointer.
*/

#include "libft.h"

static int	wordcount(char *s, char c)
{
	int		wordcount;
	int		wordbegin;

	wordcount = 0;
	wordbegin = 0;
	while (*s)
	{
		if (*s == c)
			wordbegin = 0;
		else if (*s != c && wordbegin == 0)
		{
			wordbegin = 1;
			wordcount++;
		}
		s++;
	}
	return (wordcount);
}

static char	*word(char *s1, char c)
{
	char	*copy;
	int		len;

	len = 0;
	while (s1[len] != c && s1[len] != '\0')
		len++;
	copy = (char *)malloc(len * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len + 1);
	copy[len] = '\0';
	return (copy);
}

static char	**create_array(char **word_array, char *s1, char c, int word_count)
{
	int	i;

	i = 0;
	while (i < word_count)
	{
		while (*s1 == c)
			s1++;
		word_array[i] = word(s1, c);
		if (!word_array[i])
			return (NULL);
		while (*s1 != c && *s1 != '\0')
			s1++;
		i++;
	}
	word_array[i] = NULL;
	return (word_array);
}

char	**ft_split(char const *s, char c)
{
	char	**word_array;
	char	*s1;
	int		word_count;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	word_count = wordcount(s1, c);
	word_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!word_array)
		return (NULL);
	word_array = (create_array(word_array, s1, c, word_count));
	free(s1);
	return (word_array);
}
