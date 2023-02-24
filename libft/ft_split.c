/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:07:41 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/24 14:01:15 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c);

static int	i_incrementer(const char *s, char c, int i)
{
	if (s[i] == c && s[i + 1] != c && s[i] != '\0')
		return (i);
	while (s[i] == c && s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i] != '\0')
			return (i);
		i++;
	}
	return (0);
}

static int	*ft_wordlenght(const char *s, char c, int i, int *wordlenght)
{
	int	j;
	int	k;

	j = 0;
	k = -1;
	while (s[i] == c)
		i++;
	while (k++ < ft_strcount(s, c) - 1)
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
			if (s[i] == c || s[i] == '\0')
			{
				wordlenght[k] = j;
				j = 0;
				i = i_incrementer(s, c, i);
				break ;
			}
		}
		i++;
	}
	return (wordlenght);
}

static char	**ft_stringcreator(int *wlenght, \
const char *s, char c, char **strings)
{
	int		wcount;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	wcount = ft_strcount(s, c);
	while (j < wcount)
	{
		strings[j] = (char *)malloc(sizeof(char) * (wlenght[j] + 1));
		while (k < wlenght[j])
		{
			if (s[i] != c)
				strings[j][k++] = s[i++];
			else
				i++;
		}
		strings[j][k] = '\0';
		k = 0;
		j++;
	}
	strings[j] = NULL;
	return (strings);
}

static int	ft_strcount(char const *s, char c)
{
	int		count;
	size_t	i;
	size_t	len;

	count = 0;
	i = 0;
	len = 0;
	if (s[i] != c)
		count = 1;
	while (s[len] != '\0')
		len++;
	while (i < len)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		*strindex;
	int		strcount;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		strings = ((char **)malloc(sizeof(char *) * 1));
		*strings = 0;
		return (strings);
	}
	strcount = ft_strcount(s, c);
	strindex = (int *)malloc(sizeof(int) * strcount);
	if (!strindex)
		return (NULL);
	strindex = ft_wordlenght(s, c, 0, strindex);
	strings = (char **)malloc(sizeof(char *) * (strcount + 1));
	if (!strings)
		return (NULL);
	strings = ft_stringcreator(strindex, s, c, strings);
	free (strindex);
	return (strings);
}
