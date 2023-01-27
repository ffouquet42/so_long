/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 16:52:10 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// char    **ft_delete_newline(char **map, int lines)
// {
//     // int x;
//     // int len;

//     // x = 0;
//     // while (x < lines)
//     // {
//     //     len = 0; //
//     //     printf("len : %i\n", len); //
//     //     len = ft_strlen(map[x]);
//     //     printf("len : %i\n", len); //
//     //     if (map[x + 1] == NULL)
//     //         break;
//     //     else
//     //         map[x][len] = 0;
//     //     len = ft_strlen(map[x]);
//     //     printf("len : %i\n", len); //
//     //     x++;
//     // }


//     // int x;
//     // int y;
    
//     // x = 0;
//     // while (x < lines)
//     // {
//     //     y = 0;
//     //     while (map[x][y])
//     //     {
//     //         if (map[x][y] == '\n')
//     //             printf("\n char : %c\n", map[x][y]);
//     //             map[x][y] = '\0';
//     //         y++;
//     //     }
//     //     x++;
//     // }
    
//     //
//     int i = -1;
//     while (i++ < 4)
//         printf("dlnw %i : %s", i, map[i]);
//     //
//     return (map);
// }

// char	**ft_delete_newline(char **map, int lines)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '\n' || map[i][j] == '\r')
// 				map[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (map);
// }

// delete newline pas sur d'en avoir besoin

char    **ft_map_initialyze(char *map_path, t_map *s_map)
{
    char    **map;
    int     fd;
    int     x;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s_map->height = 4; // fonction pour compter les lignes
	map = malloc(sizeof(char *) * (s_map->height + 1));
	if (!map)
		return (NULL);
	x = 0;
	while (x < s_map->height)
	{
		map[x] = get_next_line(fd);
		x++;
	}
	s_map->width = ft_strlen(map[x - 1]);
	map[x] = NULL;
	close(fd);
	// return (ft_delete_newline(map, s_map->height));
	return (map);
}
