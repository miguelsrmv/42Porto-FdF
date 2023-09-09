/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:20:48 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/23 20:17:10 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutoa_base(long unsigned int address, char *base)
{
	char	*str;
	int		i;
	int		base_len;

	if (address == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	i = 0;
	str = (char *)malloc((sizeof(char) * 32) + 1);
	if (!str)
		return (NULL);
	while (address)
	{
		str[i++] = base[address % base_len];
		address /= base_len;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*add_0x_prefix(char *str)
{
	char	*new_str;

	new_str = (char *)malloc((sizeof(char) * 32) + 1);
	if (!new_str)
		return (NULL);
	new_str[0] = '0';
	new_str[1] = 'x';
	ft_strlcpy(&new_str[2], str, ft_strlen(str) + 1);
	free(str);
	return (new_str);
}

int	ft_printf_ptr(void *address)
{
	long unsigned int	cast_address;
	char				*str;
	int					count;

	if (!address)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	cast_address = (long unsigned int)address;
	str = ft_lutoa_base(cast_address, "0123456789abcdef");
	if (!str)
		return (0);
	str = add_0x_prefix(str);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	return (count);
}
