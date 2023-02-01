/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/02/01 12:38:46 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_select_tileset(t_game *game, char c)
{
	if (c == '1')
		return (game->wall_ptr);
	else if (c == '0')
		return (game->floor_ptr);
	else if (c == 'P')
		return (game->player_ptr);
	else if (c == 'C')
		return (game->loot_ptr);
	else if (c == 'E')
		return (game->exit_ptr);
	return (NULL);
}

void	ft_setup_map(t_game *game)
{
	int	i;
	int	j;
	void *tile;
	
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			tile = ft_select_tileset(game, game->map[i][j]);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, tile, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	ft_setup_tileset(t_game *game)
{
	ft_count_total_loot(game);
	game->tile_width = 64;
	game->tile_height = 64;
	game->floor_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/floor.xpm", &game->tile_width, &game->tile_height);
	game->wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/wall.xpm", &game->tile_width, &game->tile_height);
	game->loot_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/loot.xpm", &game->tile_width, &game->tile_height);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/exit.xpm", &game->tile_width, &game->tile_height);
	game->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/player.xpm", &game->tile_width, &game->tile_height);
}

void	ft_setup_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	ft_setup_tileset(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->map_width * 64), (game->map_height * 64), "so_long");
	ft_setup_map(game);
	mlx_key_hook(game->win_ptr, ft_select_movement, game);
	mlx_hook(game->win_ptr, 17, 0, &ft_clean_exit, game);
	mlx_loop(game->mlx_ptr);
}
