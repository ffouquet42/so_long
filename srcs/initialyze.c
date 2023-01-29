/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/29 04:01:05 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_initialyze_error(t_error *s_error)
{
	s_error->errors_found = 0;
	s_error->invalid_char = 0;
	s_error->one_player = 0;
	s_error->one_exit = 0;
	s_error->one_loot = 0;
	s_error->map_shape = 0;
}

void	ft_count_total_loot(t_game *game)
{
	int	i;
	int	j;
	
	game->total_loot = 0;
	game->looted = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->total_loot++;
			j++;
		}
		i++;
	}
}

int		ft_count_lines(char *map_path)
{
	char    *map_line;
    int     fd;
    int     lines;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
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

char    **ft_map_initialyze(char *map_path, t_game *game)
{
    char    **tmp_map;
    int     fd;
    int     i;

	game->step = 0;
	game->previous_step = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->map_height = ft_count_lines(map_path);
	if (game->map_height == 0)
		return (NULL);
	tmp_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!tmp_map)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		tmp_map[i] = get_next_line(fd);
		i++;
	}
	game->map_width = ft_strlen(tmp_map[i - 1]);
	tmp_map[i] = NULL;
	close(fd);
	return (tmp_map);
}
