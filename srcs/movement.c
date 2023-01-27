/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:44:25 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 23:39:58 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_move_up(t_game *game)
{
    int x;
    int y;

    ft_find_player_pos(game);
    y = game->pos_y;
    x = game->pos_x;
    if (game->map[y - 1][x] != '1')
    {
        if (game->map[y - 1][x] == 'C')
            ft_collect_loot(game);
        else if (game->map[y - 1][x] == 'E') // + can exit
            ft_putstr("\n EXIT !\n");
        else
            ft_swap(&game->map[y][x], &game->map[y - 1][x]);
        ft_setup_map(game);
        game->step++;
    }
}

void    ft_select_movement(int key, t_game *game)
{
    if (key == 'w' || key == 'W')
        ft_move_up(game);
    else if (key == 's' || key == 'S')
        ft_putstr("move down\n");
    else if (key == 'a' || key == 'A')
        ft_putstr("move left\n");
    else if (key == 'd' || key == 'D')
        ft_putstr("move right\n");
    else if (key == 65307)
        ft_putstr("ESC\n");
    ft_display_step_shell(game);
}