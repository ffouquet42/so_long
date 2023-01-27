/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:39:41 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 22:29:31 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*stash_to_line(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (stash[j] && j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (buff[j] && stash[i])
		buff[j++] = stash[i++];
	buff[j] = '\0';
	return (line);
}

int	search_newline(const char *buff)
{
	int	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*buff_to_stash(char *buff)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		dest[i] = buff[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*merge_stash_and_buff(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*dest;

	if (!stash)
		return (buff_to_stash(buff));
	dest = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buff)) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		dest[i] = stash[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	free(stash);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	char		*stash;
	int			read_count;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	read_count = BUFFER_SIZE;
	stash = NULL;
	stash = merge_stash_and_buff(stash, buff);
	while (read_count == BUFFER_SIZE && !search_newline(buff))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
			return (free(stash), NULL);
		buff[read_count] = '\0';
		if (read_count == 0 && !stash[0])
			return (free(stash), NULL);
		stash = merge_stash_and_buff(stash, buff);
	}
	line = stash_to_line(stash, buff);
	return (free(stash), line);
}
