/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:39:34 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/14 20:25:39 by bbeltran         ###   ########.fr       */
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
void		ft_putun_nbr_fd(long n, int fd, int *printed);
void		ft_putnbr_hex_fd(unsigned long n, int fd, char c, int *printed);
void		ft_charint_mark(int c, int *i, int *printed, char ioc);

#endif
