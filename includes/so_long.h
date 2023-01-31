/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:48 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/31 21:13:26 by fllanet          ###   ########.fr       */
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
	int		previous_step;
	int		pos_y;
	int		pos_x;
	int		total_loot;
	int		looted;
}	t_game;

typedef struct s_error
{
	int		errors_found;
	int		invalid_char;
	int		one_player;
	int		one_exit;
	int		one_loot;
	int 	map_shape;
	int		map_closed;
	int		valid_path;
}	t_error;

//--------------- PROTOTYPES ---------------//

//--------------- so_long.c ---------------//
int		main(int argc, char **argv);
int		ft_clean_exit(t_game *game, int step);

//--------------- initialyze.c ---------------//
char    **ft_map_initialyze(char *map_path, t_game *game);
int		ft_count_lines(char *map_path);
void	ft_count_total_loot(t_game *game);
void	ft_initialyze_error(t_error *s_error);

//--------------- setup.c ---------------//
void	ft_setup_window(t_game *game);
void	ft_setup_tileset(t_game *game);
void	ft_setup_map(t_game *game);
void	*ft_select_tileset(t_game *game, char c);

//--------------- movement.c ---------------//
int		ft_select_movement(int key, t_game *game);
void    ft_move_up(t_game *game);
void    ft_move_down(t_game *game);
void    ft_move_left(t_game *game);
void    ft_move_right(t_game *game);

//--------------- action.c ---------------//
void    ft_find_player_pos(t_game *game);
void    ft_collect_loot(t_game *game, int direction);
void    ft_collect_loot_side(t_game *game, int direction);

//--------------- print.c ---------------//
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_display_step_shell(t_game *game);

//--------------- tools.c ---------------//
int		ft_strlen(char *str);
void	ft_swap(char *a, char *b);
char	**ft_copy_map(t_game *game);
char	*ft_strdup(char *str);

//--------------- get_next_line.c ---------------//
char	*stash_to_line(char *stash, char *buff);
int		search_newline(const char *buff);
char	*buff_to_stash(char *buff);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*get_next_line(int fd);

//--------------- check_error.c ---------------//
int     ft_check_error(char *map_path);
void    ft_display_error(int error_id);
int     ft_check_ber(char *map_path);

//--------------- parsing.c ---------------//
int     ft_parsing(t_game *game, t_error *s_error);
int     ft_char_is_valid(char c, t_error *s_error);
void    ft_check_duplicate(t_error *s_error);
void    ft_check_map_shape(t_game *game, t_error *s_error);
void    ft_close_by_wall(t_game *game, t_error *s_error);

//--------------- valid_path.c ---------------//
void    ft_valid_path(t_game *game, t_error *s_error);
int     ft_player_can_move(t_game *game, char **map_cpy);
void    ft_fill_space_of_player(t_game *game, char **map_cpy);
int     ft_player_next_to_exit(t_game *game, char **map_cpy);
int     ft_player_can_full_loot(t_game *game, char **map_cpy);

#endif
