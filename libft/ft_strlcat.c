/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:09:47 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/27 15:09:48 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ogdst;
	size_t	countdst;
	size_t	res;

	i = 0;
	res = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	countdst = ft_strlen(dst);
	ogdst = countdst;
	if (dstsize > countdst)
		res = ft_strlen(src) + countdst;
	else
		return (ft_strlen(src) + dstsize);
	while (src[i] && (countdst + 1) < dstsize)
	{
		dst[countdst] = src[i];
		countdst++;
		i++;
	}
	if (dstsize != 0 || ogdst < dstsize)
		dst[countdst] = '\0';
	return (res);
}
