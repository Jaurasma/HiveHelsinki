/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:41:45 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/28 14:41:47 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ns;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * len + 1);
	if (!(ns))
		return (NULL);
	while (*s != '\0')
	{
		ns[i] = *s++;
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
