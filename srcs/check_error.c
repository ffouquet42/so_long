/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:31:43 by fllanet           #+#    #+#             */
/*   Updated: 2023/02/01 01:06:02 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int     ft_check_ber(char *map_path)
{
    int i;

    i = ft_strlen(map_path);
    if (i < 5)
        return (1);
    if (map_path[i - 4] == '.' && map_path[i - 3] == 'b' && map_path[i - 2] == 'e' && map_path[i - 1] == 'r')
        return (0);
    return (1);
}

void    ft_display_error(int error_id)
{
    ft_putstr("Error\n");
    if (error_id == 1)
        ft_putstr("Need *.ber map file as argument\n");
}

int     ft_check_error(char *map_path)
{
    if (ft_check_ber(map_path) == 1)
        return (ft_display_error(1), 1);
    return (0);
}

void	ft_free_map_copy(char **map)
{
    int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
