/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:46 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/29 03:49:22 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_clean_exit(t_game *game, int step)
{
	int	i;

	if (step == 1)
	{
		game->step++;
		ft_display_step_shell(game);
	}
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall_ptr);
	mlx_destroy_image(game->mlx_ptr, game->loot_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_error s_error;

	if (argc == 2)
	{
		if (ft_check_error(argv[1]) == 0)
		{
			ft_initialyze_error(&s_error);
			game.map = ft_map_initialyze(argv[1], &game);
			// game.map = NULL;
			if (game.map != NULL && ft_parsing(&game, &s_error) == 0)
				//ft_setup_window(&game);
				ft_putstr("game start\n");
			else
				ft_putstr("!!!\n"); // return (print error, 0);
		}
	}
	else
		ft_putstr("Error\nWrong number of arguments\n");
	return (0);
}
