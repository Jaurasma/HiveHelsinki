/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:10:16 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/21 13:10:18 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_pf(int c);
int		ft_printpercent(void);
size_t	ft_strlen(const char *s);
int		ft_putstr_pf(char *str);
int		intlen(long num);
int		ft_putint_pf(int n);
int		ft_putuint_pf(unsigned int n, unsigned int base);
int		ft_puthexa_pf(unsigned int n, char ch);
int		conversion_spesificator(char control_ch, va_list args);
int		hexalen(unsigned long long num);
void	ft_writeprt_pf(unsigned long long num);
int		ft_putptr_pf(unsigned long long ptr);
void	ft_itoa_pf(int n);
#endif
