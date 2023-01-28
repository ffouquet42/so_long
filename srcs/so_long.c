/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:46 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/28 01:12:28 by fllanet          ###   ########.fr       */
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

	if (argc == 2) // et que map valide (ou au moins rectangle)
	{
		game.map = ft_map_initialyze(argv[1], &game);
		if (game.map != NULL) // check map valid et remplir struct error de 1 pour error
			ft_setup_window(&game);
		else
			ft_putstr("error map (null)\n"); // return (exit propre + print error)
	}
	else
		ft_putstr("error argc\n"); // return (exit propre + print error)
	return (0);
}
