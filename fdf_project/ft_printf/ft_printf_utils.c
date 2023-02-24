/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:42:21 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/26 17:55:30 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num > 0 || num < 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_putint_pf(int n)
{
	int	len;

	len = intlen(n);
	ft_itoa_pf(n);
	return (len);
}

int	ft_putuint_pf(unsigned int n, unsigned int base)
{
	if (n >= base)
	{
		ft_putuint_pf(n / base, base);
		ft_putuint_pf(n % base, base);
	}
	else
	{
		ft_putchar_pf(n + 48);
	}
	return (intlen(n));
}

int	ft_puthexa_pf(unsigned int n, char ch)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_puthexa_pf(n / 16, ch);
		ft_puthexa_pf(n % 16, ch);
	}
	else
	{
		if (n <= 9)
			ft_putchar_pf(n + '0');
		else if (ch == 'x')
			ft_putchar_pf(n - 10 + 'a');
		else if (ch == 'X')
			ft_putchar_pf(n - 10 + 'A');
	}
	return (hexalen(n));
}
