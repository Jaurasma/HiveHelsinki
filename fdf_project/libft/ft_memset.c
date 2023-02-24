/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:17:51 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/24 19:17:53 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	unsigned char	*string;

	string = (unsigned char *)str;
	if (string == 0)
		string[-1] = 's';
	if (n <= 0)
		return (str);
	while (n > 0)
	{
		*string = (unsigned char) c;
		string++;
		n--;
	}
	return (str);
}
