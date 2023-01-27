/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 18:01:32 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*ft_select_tileset(t_tileset *tileset, char c)
{	
	if (c == '1')
		return (tileset->wall_ptr);
	else if (c == '0')
		return (tileset->floor_ptr);
	else if (c == 'P')
		return (tileset->player_ptr);
	else if (c == 'C')
		return (tileset->loot_ptr);
	else if (c == 'E')
		return (tileset->exit_ptr);
}

void	ft_setup_map(t_data data, t_tileset *tileset, t_map *map)
{
	int	i;
	int	j;
	void *tile;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			tile = ft_select_tileset(tileset, map->value[i][j]);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tile, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	ft_setup_tileset(t_data data, t_tileset *tileset)
{
	tileset->width = 64;
	tileset->height = 64;
	tileset->floor_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./img/floor.xpm", &tileset->width, &tileset->height);
	tileset->wall_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./img/wall.xpm", &tileset->width, &tileset->height);
	tileset->loot_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./img/loot.xpm", &tileset->width, &tileset->height);
	tileset->exit_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./img/exit.xpm", &tileset->width, &tileset->height);
	tileset->player_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./img/player.xpm", &tileset->width, &tileset->height);
}

void	ft_setup_window(t_map *map)
{
	t_data		data;
	t_tileset	tileset;

	data.mlx_ptr = mlx_init();
	ft_setup_tileset(data, &tileset);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (map->width * 64), (map->height * 64), "so_long");
	ft_setup_map(data, &tileset, map);
	mlx_loop(data.mlx_ptr);
}
