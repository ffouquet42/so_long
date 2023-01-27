/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:42:52 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/27 17:01:20 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
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

int deal_key(int key, void *param)
{
    // ft_putchar('x');
    ft_putnbr(key);
    return (0);
}

int main(int argc, char **argv)
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_key_hook(win_ptr, deal_key, (void *)0);

    mlx_loop(mlx_ptr);
    return (0);
}


    // void *img_ptr;
    // img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./img/wall.xpm", 64, 64);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    // mlx_destroy_image (mlx_ptr, img_ptr);
    // mlx_destroy_display(mlx_ptr);

void	ft_display(t_data data, t_tileset *tileset)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->floor_ptr, (size_t)0, (size_t)0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->wall_ptr, (size_t)64, (size_t)0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->loot_ptr, (size_t)128, (size_t)0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->exit_ptr, (size_t)192, (size_t)0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tileset->player_ptr, (size_t)256, (size_t)0);
}

// DEV
	// int d = 0;
	// while (d < map->height)
	// {
	// 	printf("map in setup %i : %s", d, map->value[d]);
	// 	d++;
	// }
	// printf("\nwidth: %i\n", map->width);
	// printf("\nheigth: %i\n", map->height);
	// DEV