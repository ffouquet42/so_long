/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:44:25 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 23:03:33 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_move_up(t_game *game)
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
                ft_swap(&game->map[y][x], &game->map[y - 1][x]);
                ft_setup_map(game);
            }
            x++;
        }
        y++;
    }
    game->step++; // si mouvement possible ?
}

// ft qui renvoie pos du 'P' ?

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