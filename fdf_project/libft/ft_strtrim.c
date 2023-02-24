/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:08:34 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/03 17:08:37 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_test(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstring;
	int		beginning;
	int		end;
	int		i;

	beginning = 0;
	end = ft_strlen(s1);
	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[beginning] && set_test(s1[beginning], set))
		beginning++;
	while (end > beginning && set_test(s1[end - 1], set))
		end--;
	trimstring = (char *)malloc(sizeof(char) * (end - beginning) + 1);
	if (!trimstring)
		return (NULL);
	while (beginning < end)
		trimstring[i++] = s1[beginning++];
	trimstring[i] = '\0';
	return (trimstring);
}
