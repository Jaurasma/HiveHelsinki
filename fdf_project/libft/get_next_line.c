/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:30:23 by jaurasma          #+#    #+#             */
/*   Updated: 2022/11/15 13:37:13 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reset_progressor(char *progressbar)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (progressbar[i] && progressbar[i] != '\n')
		i++;
	if (!progressbar[i])
	{
		free (progressbar);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen_gnl(progressbar) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (progressbar[i])
		str[j++] = progressbar[i++];
	str[j] = '\0';
	free (progressbar);
	return (str);
}

static char	*ft_linecreator(char *progressbar)
{
	char	*nextline;
	int		i;

	i = 0;
	if (!progressbar[i])
		return (NULL);
	while (progressbar[i] && progressbar[i] != '\n')
		i++;
	nextline = (char *)malloc(sizeof(char) * i + 2);
	if (!nextline)
		return (NULL);
	i = 0;
	while (progressbar[i] && progressbar[i] != '\n')
	{
		nextline[i] = progressbar[i];
		i++;
	}
	if (progressbar[i] == '\n')
	{
		nextline[i] = '\n';
		i++;
	}
	nextline[i] = '\0';
	return (nextline);
}

static char	*ft_progressor(char *progressbar, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(progressbar, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		progressbar = ft_strjoin_gnl(progressbar, buffer, 0, 0);
	}
	free (buffer);
	return (progressbar);
}

char	*get_next_line(int fd)
{
	static char	*progressbar;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	progressbar = ft_progressor(progressbar, fd);
	if (!progressbar)
		return (NULL);
	nextline = ft_linecreator(progressbar);
	progressbar = ft_reset_progressor(progressbar);
	return (nextline);
}
