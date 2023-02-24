/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:56:42 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/26 14:56:44 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writeprt_pf(unsigned long long num)
{
	if (num >= 16)
	{
		ft_writeprt_pf(num / 16);
		ft_writeprt_pf(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_pf(num + '0');
		else
			ft_putchar_pf(num - 10 + 'a');
	}
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	str_len;

	str_len = 0;
	str_len += write(1, "0x", 2);
	if (ptr == 0)
		str_len += write(1, "0", 1);
	else
	{
		ft_writeprt_pf(ptr);
		str_len += hexalen(ptr);
	}
	return (str_len);
}

int	hexalen(unsigned long long num)
{
	int		i;

	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}
