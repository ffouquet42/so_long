/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:28:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 14:13:58 by fllanet          ###   ########.fr       */
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
	while (x < lines)
	{
		map[x] = get_next_line(fd);
		x++;
	}
	close(fd);
	return (ft_delete_newline(map, lines));
}
