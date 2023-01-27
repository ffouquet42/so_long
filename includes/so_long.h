/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:48 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 18:00:08 by fllanet          ###   ########.fr       */
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

//--------------- VARIABLE ---------------//
# define BUFFER_SIZE 1

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
	int		width;
	int		height;
}	t_map;

typedef struct s_error
{

}	t_error;

//--------------- PROTOTYPES ---------------//

//--------------- GAME ---------------//

//--------------- so_long.c ---------------//
int		main(int argc, char **argv);

//--------------- setup.c ---------------//
void	ft_setup_window(t_map *map);
void	ft_setup_tileset(t_data data, t_tileset *tileset);
void	ft_setup_map(t_data data, t_tileset *tileset, t_map *map);
void	*ft_select_tileset(t_tileset *tileset, char c);

//--------------- MAP ---------------//

//--------------- initialyze.c ---------------//
char	**ft_map_initialyze(char *map_path, t_map *s_map);
char    **ft_delete_newline(char **map, int lines); // delete ?

//--------------- UTILS ---------------//

//--------------- print.c ---------------//
void	ft_putchar(char c);
void	ft_putstr(char *str);

//--------------- tools.c ---------------//
int		ft_strlen(char *str);

//--------------- GET_NEXT_LINE ---------------//

//--------------- get_next_line.c ---------------//
char	*stash_to_line(char *stash, char *buff);
int		search_newline(const char *buff);
char	*buff_to_stash(char *buff);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*get_next_line(int fd);

#endif
