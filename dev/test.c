/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:42:52 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/25 18:38:56 by fllanet          ###   ########.fr       */
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