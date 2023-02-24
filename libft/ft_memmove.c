/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:21:57 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/26 16:21:59 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	i = 0;
	if (source == NULL && destination == NULL)
		return (NULL);
	if (destination > source)
		while (0 < len--)
			destination[len] = source[len];
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
