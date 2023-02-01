/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:45:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/02/01 00:47:10 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*tmp;
	char	*dest;

	tmp = str;
	i = 0;
	while (tmp[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		dest[i] = tmp[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_copy_map(t_game *game)
{
	char **map_cpy;
	int	i;

	map_cpy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	ft_free_map(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}