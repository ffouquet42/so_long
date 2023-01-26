/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/26 18:32:19 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char    **ft_map_initialyze(char *map_path)
{
    char    **map;
    int     fd;
    int     i;
    int     lines;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    
    return (map);
}
