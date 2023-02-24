/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_lf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:40 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/26 17:56:03 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

void	ft_itoa_pf(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = intlen(num);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return ;
	str[i--] = '\0';
	*str = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[i] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	ft_printf("%s", str);
	free(str);
}
