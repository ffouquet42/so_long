/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:46 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/25 17:53:24 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;

    mlx_ptr = mlx_init();

    win_ptr = mlx_new_window(mlx_ptr, 256, 256, "so_long");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "../img/wall.xpm", 64, 64);
    
    //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    
    mlx_loop(mlx_ptr);
    
    return (0);
}
