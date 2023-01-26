/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/26 19:10:29 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char    **ft_map_initialyze(char *map_path)
{
    char    **map;
    int     fd;
    int     lines;
    int     x;
    
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    lines = 4; // fonction pour compter les lignes
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);
    x = 0;
    while (x <= lines)
    {
        map[x] = get_next_line(fd);
        x++;
    }
    close(fd);
    return (map);
}
