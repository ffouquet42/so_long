/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:00:15 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/31 21:49:12 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_display_step_shell(t_game *game)
{
	if (game->step > game->previous_step)
	{
		ft_putstr("Step : ");
		ft_putnbr(game->step);
		ft_putchar('\n');
		game->previous_step = game->step;
	}
}


void	ft_print_errors(t_error *s_error)
{
	ft_putstr("Error\n");
	if (s_error->invalid_char == 1)
		ft_putstr("Invalid char detected\n");
	if (s_error->one_player != 1)
		ft_putstr("Need one starting position for player\n");
	if (s_error->one_exit != 1)
		ft_putstr("Need one exit\n");
	if (s_error->one_loot < 1)
		ft_putstr("Need at least one loot\n");
	if (s_error->map_shape == 1)
		ft_putstr("Invalid map shape\n");
	if (s_error->map_closed == 1)
		ft_putstr("Map must be closed by wall\n");
	if (s_error->valid_path == 1)
		ft_putstr("No valid path found\n");
}