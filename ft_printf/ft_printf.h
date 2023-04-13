/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:39:34 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/13 13:02:25 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(char const *format, ...);
int			ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd, int *printed);
void		ft_putstr_fd(char *s, int fd, int *printed);
void		ft_putnbr_fd(long n, int fd, int *printed);
void		ft_putun_nbr_fd(unsigned int n, int fd, int *printed);
void		ft_putnbr_hex_fd(int n, int fd, char c, int *printed);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
