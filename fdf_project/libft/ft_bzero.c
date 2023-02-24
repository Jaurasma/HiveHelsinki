/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:20:19 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/26 16:20:24 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (str == 0)
		str[-1] = 's';
	if (str == 0 || n <= 0)
		return (s);
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (s);
}
