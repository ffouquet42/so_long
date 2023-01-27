/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:44:25 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 23:52:47 by fllanet          ###   ########.fr       */
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
            ft_collect_loot(game, -1);
        else if (game->map[y - 1][x] == 'E') // + can exit
            ft_putstr("\n EXIT !\n");
        else
            ft_swap(&game->map[y][x], &game->map[y - 1][x]);
        ft_setup_map(game);
        game->step++;
    }
}

void    ft_move_down(t_game *game)
{
    int x;
    int y;

    ft_find_player_pos(game);
    y = game->pos_y;
    x = game->pos_x;
    if (game->map[y + 1][x] != '1')
    {
        if (game->map[y + 1][x] == 'C')
            ft_collect_loot(game, 1);
        else if (game->map[y + 1][x] == 'E') // + can exit
            ft_putstr("\n EXIT !\n");
        else
            ft_swap(&game->map[y][x], &game->map[y + 1][x]);
        ft_setup_map(game);
        game->step++;
    }
}

void    ft_move_left(t_game *game)
{
    int x;
    int y;

    ft_find_player_pos(game);
    y = game->pos_y;
    x = game->pos_x;
    if (game->map[y][x - 1] != '1')
    {
        if (game->map[y][x - 1] == 'C')
            ft_collect_loot_side(game, -1);
        else if (game->map[y][x - 1] == 'E') // + can exit
            ft_putstr("\n EXIT !\n");
        else
            ft_swap(&game->map[y][x], &game->map[y][x - 1]);
        ft_setup_map(game);
        game->step++;
    }
}

void    ft_move_right(t_game *game)
{
    int x;
    int y;

    ft_find_player_pos(game);
    y = game->pos_y;
    x = game->pos_x;
    if (game->map[y][x + 1] != '1')
    {
        if (game->map[y][x + 1] == 'C')
            ft_collect_loot_side(game, 1);
        else if (game->map[y][x + 1] == 'E') // + can exit
            ft_putstr("\n EXIT !\n");
        else
            ft_swap(&game->map[y][x], &game->map[y][x + 1]);
        ft_setup_map(game);
        game->step++;
    }
}

void    ft_select_movement(int key, t_game *game)
{
    if (key == 'w' || key == 'W')
        ft_move_up(game);
    else if (key == 's' || key == 'S')
        ft_move_down(game);
    else if (key == 'a' || key == 'A')
        ft_move_left(game);
    else if (key == 'd' || key == 'D')
        ft_move_right(game);
    else if (key == 65307)
        ft_putstr("ESC\n");
    ft_display_step_shell(game);
}
