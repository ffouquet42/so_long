/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:46 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/26 18:35:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	char **map;
	
	if (argc == 2) 
	{
		map = ft_map_initialyze(argv[1]);
		if (map != NULL) // check map valid et remplir struct error de 1 pour error
			ft_setup_window(map);
		else
			ft_putstr("error\n"); // return (exit propre + print error)
	}
	else
		ft_putstr("error\n"); // return (exit propre + print error)
	return (0);
}
