/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:48 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/26 16:15:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//--------------- INCLUDES ---------------//
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//--------------- STRUCTURES ---------------//
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_tileset
{
	void	*floor_ptr;
	void	*wall_ptr;
	void	*loot_ptr;
	void	*exit_ptr;
	void	*player_ptr;
	int		width;
	int		height;
}	t_tileset;

typedef struct s_map
{
	char	**value;
}	t_map;

//--------------- PROTOTYPES ---------------//

//--------------- GAME ---------------//

//--------------- so_long.c ---------------//
int		main(int argc, char **argv);

//--------------- setup.c ---------------//
void	ft_setup_window(t_map *map);
void	ft_setup_tileset(t_data data, t_tileset *tileset);

//--------------- UTILS ---------------//

//--------------- print.c ---------------//
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif