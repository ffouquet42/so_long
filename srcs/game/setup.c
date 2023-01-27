/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 17:20:27 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_setup_map(t_data data, t_tileset *tileset, t_map *map)
{
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->floor_ptr, 0, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->wall_ptr, 64, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->loot_ptr, 128, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->exit_ptr, 192, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->player_ptr, 256, 0);

	int	i;
	int	j;

	i = 0;
	// printf("height: %i", map->height);
	// printf("width: %i", map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->wall_ptr, (int)(i * 64), (int)(j * 64));
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
	ft_setup_map(data, &tileset, &map);
	mlx_loop(data.mlx_ptr);
}
