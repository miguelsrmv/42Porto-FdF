/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/06 09:41:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_arg_fd(char *string, int *i, va_list args)
{
	int		counter;

	(*i)++;
	counter = 0;
	if (string[*i] == '%')
		counter += ft_printf_char('%');
	else if (string[*i] == 'c')
		counter += ft_printf_char(va_arg(args, int));
	else if (string[*i] == 's')
		counter += ft_printf_string(va_arg(args, char *));
	else if (string[*i] == 'd' || string[*i] == 'i')
		counter += ft_printf_int(va_arg(args, int));
	else if (string[*i] == 'u')
		counter += ft_printf_unsint(va_arg(args, unsigned int));
	else if (string[*i] == 'x')
		counter += ft_printf_base(va_arg(args, int), "0123456789abcdef");
	else if (string[*i] == 'X')
		counter += ft_printf_base(va_arg(args, int), "0123456789ABCDEF");
	else if (string[*i] == 'p')
		counter += ft_printf_ptr(va_arg(args, void *));
	return (counter);
}

int	ft_fprintf(int fd, const char *string, ...)
{
	int		counter;
	int		i;
	va_list	args;
	char	*str;

	str = (char *)string;
	counter = 0;
	i = 0;
	va_start(args, string);
	while (str[i])
	{
		if (str[i] == '%')
			counter += check_arg_fd(str, &i, args);
		else
		{
			ft_putchar_fd(str[i], fd);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
