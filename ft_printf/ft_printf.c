/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:10:10 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/26 18:22:23 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_spesificator(char control_ch, va_list args)
{
	int		pf_strlen;

	pf_strlen = 0;
	if (control_ch == 'c')
		pf_strlen += ft_putchar_pf(va_arg(args, int));
	else if (control_ch == 's')
		pf_strlen += ft_putstr_pf(va_arg(args, char *));
	else if (control_ch == 'p')
		pf_strlen += ft_putptr_pf(va_arg(args, unsigned long long));
	else if (control_ch == 'd' || control_ch == 'i')
		pf_strlen += ft_putint_pf(va_arg(args, int));
	else if (control_ch == 'u')
		pf_strlen += ft_putuint_pf(va_arg(args, unsigned int), 10);
	else if (control_ch == 'x' || control_ch == 'X')
		pf_strlen += ft_puthexa_pf(va_arg(args, unsigned int), control_ch);
	else if (control_ch == '%')
		pf_strlen += write(1, "%", 1);
	return (pf_strlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		str_len;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	str_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			str_len += conversion_spesificator(str[i], args);
		}
		else
			str_len += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(args);
	return (str_len);
}
