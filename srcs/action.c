/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:18:01 by fllanet           #+#    #+#             */
/*   Updated: 2023/02/01 13:27:52 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_find_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_y = y;
				game->pos_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_collect_loot(t_game *game, int direction)
{
	int	x;
	int	y;

	ft_find_player_pos(game);
	y = game->pos_y;
	x = game->pos_x;
	ft_swap(&game->map[y][x], &game->map[y + direction][x]);
	game->map[y][x] = '0';
	game->looted++;
}

void	ft_collect_loot_side(t_game *game, int direction)
{
	int	x;
	int	y;

	ft_find_player_pos(game);
	y = game->pos_y;
	x = game->pos_x;
	ft_swap(&game->map[y][x], &game->map[y][x + direction]);
	game->map[y][x] = '0';
	game->looted++;
}
