/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:59:13 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/02 17:59:15 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long num)
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

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = intlen(num);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	*str = '0';
	if (num == 0)
		return (str);
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
	return (str);
}
