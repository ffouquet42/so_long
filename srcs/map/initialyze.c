/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 19:37:28 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int		ft_count_lines(char *map_path)
{
	char    *map_line;
    int     fd;
    int     lines;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = 0;
	map_line = get_next_line(fd);
	while (map_line)
	{
		lines++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char    **ft_map_initialyze(char *map_path, t_map *s_map)
{
    char    **map;
    int     fd;
    int     i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s_map->height = ft_count_lines(map_path);
	if (s_map->height == NULL)
		return (NULL);
	map = malloc(sizeof(char *) * (s_map->height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < s_map->height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	s_map->width = ft_strlen(map[i - 1]);
	map[i] = NULL;
	close(fd);
	return (map);
}
