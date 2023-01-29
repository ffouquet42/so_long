/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:08:52 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/29 04:06:38 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int     ft_char_is_valid(char c, t_error *s_error)
{
    char    *valid_char;
    int     i;

    if (c == 'C')
        s_error->one_loot++;
    else if (c == 'E')
        s_error->one_exit++;
    else if (c == 'P')
        s_error->one_player++;
    valid_char = "10CEP";
    i = 0;
    while (valid_char[i])
    {
        if (c == valid_char[i])
            return (0);
        i++;
    }
    s_error->invalid_char = 1;
    s_error->errors_found++;
    return (1);
}

void    ft_check_duplicate(t_error *s_error)
{
    if (s_error->one_exit != 1 || s_error->one_player != 1 || s_error->one_loot < 1)
        s_error->errors_found++;
}

// function check entourer par des murs

void    ft_check_map_shape(t_game *game, t_error *s_error)
{
    if (game->map_height < 3 || game->map_width < 3 || game->map_height == game->map_width)
    {
        s_error->errors_found++;
        s_error->map_shape = 1;
    }
}

int     ft_parsing(t_game *game, t_error *s_error)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            ft_char_is_valid(game->map[i][j], s_error);
            if (s_error->errors_found != 0)
                return (s_error->errors_found);
            j++;
        }
        i++;
    }
    ft_check_map_shape(game, s_error);
    ft_check_duplicate(s_error);
    return (s_error->errors_found);
}