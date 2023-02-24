/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:22 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/01 16:32:27 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	ns = ((char *)malloc(sizeof(char) * len + 1));
	if (!(ns))
		return (0);
	if (start >= ft_strlen(s))
	{
		*ns = '\0';
		return (ns);
	}
	while (i < len)
		ns[i++] = s[start++];
	ns[i] = '\0';
	return (ns);
}
