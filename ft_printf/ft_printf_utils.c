/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:47:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/13 13:39:53 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar_fd(char c, int fd, int *printed)
{
	write(fd, &c, 1);
	(*printed)++;
}

void	ft_putstr_fd(char *s, int fd, int *printed)
{
	int	index;
	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd, printed);
		index++;
	}

}

void	ft_putun_nbr_fd(unsigned int n, int fd, int *printed)
{
	unsigned int	unnbr;
	unsigned int				newnbr;

	if (n < 0)
	{
		unnbr = n;
		newnbr = n;
		ft_putnbr_fd(newnbr, fd, printed);
	}
	else if (n >= 0)
		ft_putnbr_fd(n, fd, printed);
}

void	ft_putnbr_fd(long n, int fd, int *printed)
{
	//if (n == -2147483648)
	//	return (ft_putstr_fd("-2147483648", fd, printed));
	if (n < 0)
	{
		ft_putchar_fd('-', fd, printed);
		ft_putnbr_fd(n * -1, fd, printed);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, printed);
		ft_putchar_fd(n % 10 + '0', fd, printed);
	}
	else
		ft_putchar_fd(n + '0', fd, printed);
}

static size_t	ft_findhexlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex_fd(int n, int fd, char c, int *printed)
{
	size_t	len;
	int	remain;
	char	*reversed;

	len = ft_findhexlen(n);
	reversed = malloc(sizeof(char) * len + 1);
	if (!reversed)
		return ;
	reversed[len] = '\0';
	while (n != 0 && len--)
	{
		remain = n % 16;
		if (remain < 10)
			reversed[len] = n + '0';
		else
		{
			if (c == 'x')
				reversed[len] = 'a' + (remain - 10);
			else if (c == 'X')
				reversed[len] = 'A' + (remain - 10);
		}
		n = n / 16;
	}
	ft_putstr_fd(reversed, fd, printed);
	free(reversed);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	i = 0;
	if (!src && !dst)
		return (slen);
	if (!dstsize)
		return (slen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
