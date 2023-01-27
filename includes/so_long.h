/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:48 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 23:05:41 by fllanet          ###   ########.fr       */
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
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor_ptr;
	void	*wall_ptr;
	void	*loot_ptr;
	void	*exit_ptr;
	void	*player_ptr;
	int		tile_width;
	int		tile_height;
	char	**map;
	int		map_width;
	int		map_height;
	int		step;
}	t_game;

typedef struct s_error
{

}	t_error;

//--------------- PROTOTYPES ---------------//

//--------------- so_long.c ---------------//
int		main(int argc, char **argv);

//--------------- initialyze.c ---------------//
char    **ft_map_initialyze(char *map_path, t_game *game);
int		ft_count_lines(char *map_path);

//--------------- setup.c ---------------//
void	ft_setup_window(t_game *game);
void	ft_setup_tileset(t_game *game);
void	ft_setup_map(t_game *game);
void	*ft_select_tileset(t_game *game, char c);

//--------------- movement.c ---------------//
void    ft_select_movement(int key, t_game *game);
void    ft_move_up(t_game *game);

//--------------- print.c ---------------//
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_display_step_shell(t_game *game);

//--------------- tools.c ---------------//
int		ft_strlen(char *str);
void	ft_swap(char *a, char *b);

//--------------- get_next_line.c ---------------//
char	*stash_to_line(char *stash, char *buff);
int		search_newline(const char *buff);
char	*buff_to_stash(char *buff);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*get_next_line(int fd);

#endif
