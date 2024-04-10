/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:53:10 by iel-amra          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:10 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define V_FLAGS "# +-0"
# define CHARSET "cspdiuxX%"

int		addons_int(va_list args, char *flags, int len, int ft_mode);
int		addons_little_hexa(va_list args, char *flags, int len, int ft_mode);
int		addons_big_hexa(va_list args, char *flags, int len, int ft_mode);

int		ft_dprintf(int fd, const char *str, ...);

int		print_big_hexa(va_list args, char *flags, int fd);
int		len_print_big_hexa(va_list args, char *flags);

int		print_char(va_list args, char *flags, int fd);
int		len_print_char(va_list args, char *flags);

int		print_int(va_list args, char *flags, int fd);
int		len_print_int(va_list args, char *flags);

int		len_long_hexa(unsigned long int n);
int		print_little_hexa(va_list args, char *flags, int fd);
int		len_print_little_hexa(va_list args, char *flags);

void	one_hexa(unsigned char c, int decal, int fd);
void	ft_putulong_hexa(unsigned long n, int decal, int fd);
int		print_pointer(va_list args, char *flags, int fd);
int		len_print_pointer(va_list args, char *flags);

int		print_pourcentage(va_list args, char *flags, int fd);
int		len_print_pourcentage(va_list args, char *flags);

int		preci(char *flags);
int		print_string(va_list args, char *flags, int fd);
int		len_print_string(va_list args, char *flags);

int		print_unsigned_int(va_list args, char *flags, int fd);
int		len_print_unsigned_int(va_list args, char *flags);

int		spaces(int len, char *flags, int mode, int fd);
char	get_padding_type(char *flags);
void	one_hexa(unsigned char c, int decal, int fd);

void	get_functions(int (*f[9])(va_list, char *, int));
void	get_len_functions(int (*f[9])(va_list, char *));
int		rang(char c);
int		add_rang(char c);
void	get_addons(int (*f[4])(va_list, char *, int, int));
#endif
