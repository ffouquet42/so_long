/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/26 20:51:27 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	t_data	data;
	t_tileset tileset;

	// int q = -1;
    // while (q++ < 4)
    //     printf("setup %i : %s", q, map->value[q]);

	data.mlx_ptr = mlx_init();
	ft_setup_tileset(data, &tileset);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 320, 64, "so_long");
	mlx_loop(data.mlx_ptr);
}
