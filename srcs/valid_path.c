/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:57 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/31 21:25:29 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int     ft_player_can_move(t_game *game, char **map_cpy)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (map_cpy[i][j] == 'P')
            {
                if (map_cpy[i - 1][j] == '0' || map_cpy[i - 1][j] == 'C')
                    return (1);
                if (map_cpy[i + 1][j] == '0' || map_cpy[i + 1][j] == 'C')
                    return (1);
                if (map_cpy[i][j - 1] == '0' || map_cpy[i][j - 1] == 'C')
                    return (1);
                if (map_cpy[i][j + 1] == '0' || map_cpy[i][j + 1] == 'C')
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_fill_space_of_player(t_game *game, char **map_cpy)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (map_cpy[i][j] == 'P')
            {
                if (map_cpy[i - 1][j] == '0' || map_cpy[i - 1][j] == 'C')
                    map_cpy[i - 1][j] = 'P';
                if (map_cpy[i + 1][j] == '0' || map_cpy[i + 1][j] == 'C')
                    map_cpy[i + 1][j] = 'P';
                if (map_cpy[i][j - 1] == '0' || map_cpy[i][j - 1] == 'C')
                    map_cpy[i][j - 1] = 'P';
                if (map_cpy[i][j + 1] == '0' || map_cpy[i][j + 1] == 'C')
                    map_cpy[i][j + 1] = 'P';
            }
            j++;
        }
        i++;
    }
}

int     ft_player_next_to_exit(t_game *game, char **map_cpy)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (map_cpy[i][j] == 'E')
            {
                if (map_cpy[i - 1][j] == 'P')
                    return (1);
                if (map_cpy[i + 1][j] == 'P')
                    return (1);
                if (map_cpy[i][j - 1] == 'P')
                    return (1);
                if (map_cpy[i][j + 1] == 'P')
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int     ft_player_can_full_loot(t_game *game, char **map_cpy)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (map_cpy[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    ft_valid_path(t_game *game, t_error *s_error)
{
    char    **map_cpy;

    map_cpy = ft_copy_map(game);
    if (map_cpy == NULL)
    {
        s_error->valid_path = 1;
        s_error->errors_found++;
        return ;
    }
    while (ft_player_can_move(game, map_cpy) == 1)
        ft_fill_space_of_player(game, map_cpy);
    if (ft_player_next_to_exit(game, map_cpy) == 1 && ft_player_can_full_loot(game, map_cpy) == 1)
        return ;
    s_error->valid_path = 1;
    s_error->errors_found++;
    return ;
}
