/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:00:19 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/13 16:17:32 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int	i;
	int	printed_chars;
	va_list	ap;
	
	va_start(ap, format);
	i = 0;
	printed_chars = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] && format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(ap, int), 1, &printed_chars);
			i += 2;
		}
		else if (format[i] && format[i] == '%' && format[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(ap, char *), 1, &printed_chars);
			i += 2;
		}
		else if (format[i] && format[i] == '%' && format[i + 1] == 'p')
		{
			ft_putstr_fd("0x", 1, &printed_chars);
			ft_putnbr_hex_fd(va_arg(ap, int), 1, 'x', &printed_chars);
		}
		else if (format[i] && format[i] == '%' &&
			(format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr_fd(va_arg(ap, int), 1, &printed_chars);
			i += 2;
		}
		else if (format[i] && format[i] == '%' && format[i + 1] == 'u')
		{
			ft_putun_nbr_fd(va_arg(ap, unsigned int), 1, &printed_chars);
			i += 2;
		}	
		else if (format[i] && format[i] == '%' && format[i + 1] == 'x')
		{
			ft_putnbr_hex_fd(va_arg(ap, int), 1, 'x', &printed_chars);
			i += 2;
		}
		else if (format[i] && format[i] == '%' && format[i + 1] == 'X')
		{
			ft_putnbr_hex_fd(va_arg(ap, int), 1, 'X', &printed_chars);
			i += 2;
		}
		else if (format[i] && format[i] == '%' && format[i + 1] == '%')
			i++;
		else
		{
			ft_putchar_fd(format[i], 1, &printed_chars);
			i++;
		}
	}
	return (printed_chars);
}

/*int	main(void)
{	
	int	a = 31;
	unsigned int unbr = 123;
	int	i = printf("%u, Hello %d, %c %s %%, hex %x %X", unbr, -42, 'a', "test", 31, 31);
	printf("\nOriginal val: %i\n", i);
//	printf("\nOriginal unsigned long ptr val: %lu\n", &a);
	printf("\nOriginal ptr val: %p\n", &a);
	int	j = ft_printf("%u, Hello %d, %c %s %%, hex %x %X", unbr, -42, 'a', "test", 31, 31);
	printf("\nMy ptr val: %p\n", &a);
	printf("\nMy val: %i\n", j);
	return (0);
}*/
/*int	main(void)
{
//	unsigned int unum = -11;
	int	i = printf("Hello %i, this is %c %s %%", 42, 'a', "test");
	printf("\nOriginal val: %i\n", i);
	int	j = ft_printf("Hello %i, this is %c %s %%", 42, 'a', "test");
	printf("\nMy val: %i\n", j);
	return (0);
}*/
