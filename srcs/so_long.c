/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:46 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 22:28:56 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
