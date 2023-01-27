/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:18:01 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 23:39:44 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_find_player_pos(t_game *game)
{
    int x;
    int y;

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

void    ft_collect_loot(t_game *game)
{
    int x;
    int y;

    ft_find_player_pos(game);
    y = game->pos_y;
    x = game->pos_x;
    ft_swap(&game->map[y][x], &game->map[y - 1][x]);
    game->map[y][x] = '0';
}