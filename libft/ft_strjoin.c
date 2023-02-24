/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:12:42 by jaurasma          #+#    #+#             */
/*   Updated: 2022/10/29 14:12:44 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sum;
	char	*ns;
	int		i;
	int		j;

	sum = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ns = (char *)malloc(sizeof(char) * sum + 1);
	if (!ns)
		return (NULL);
	i = 0;
	j = 0;
	while ((size_t)i < ft_strlen(s1))
		ns[j++] = s1[i++];
	i = 0;
	while ((size_t)i < ft_strlen(s2))
		ns[j++] = s2[i++];
	ns[j] = '\0';
	return (ns);
}
