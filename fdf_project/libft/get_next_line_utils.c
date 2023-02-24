/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:30:47 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/14 16:30:49 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	char	*string;

	string = (char *)str;
	if (!str)
		return (NULL);
	while (*string != (char)c || *string != '\0')
	{
		if (*string == '\0')
			return (NULL);
		string++;
	}
	return (string);
}

char	*ft_strjoin_gnl(char *pb, char *buf, size_t i, size_t j)
{
	char	*ns;
	size_t	pb_len;
	size_t	buf_len;

	if (!pb)
	{
		pb = (char *)malloc(sizeof(char) * 1);
		pb[0] = '\0';
	}
	if (!pb || !buf)
		return (NULL);
	pb_len = ft_strlen(pb);
	buf_len = ft_strlen(buf);
	ns = (char *)malloc(sizeof(char) * (pb_len + buf_len) + 1);
	if (!ns)
		return (NULL);
	while (i < pb_len)
		ns[j++] = pb[i++];
	i = 0;
	while (i < buf_len)
		ns[j++] = buf[i++];
	ns[j] = '\0';
	free (pb);
	return (ns);
}
