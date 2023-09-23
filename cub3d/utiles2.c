/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:49:30 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 06:37:28 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wal(t_mlx *mlx)
{
	int	x;
	int	y;
	int	tilx;
	int	tily;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			tilx = x * TILE_SIZE;
			tily = y * TILE_SIZE;
			if (mlx->map[y][x] == '1')
				draw(mlx, MINIMAP_FACTOR * tily, MINIMAP_FACTOR * tilx);
			x++;
		}
		y++;
	}
}

void	size_of_map(t_mlx *mlx)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(mlx->map[0]);
	while (mlx->map[i])
	{
		if (mlx->map[i] && mlx->map[i + 1] && \
			size < ft_strlen(mlx->map[i + 1]))
			size = ft_strlen(mlx->map[i + 1]);
		i++;
	}
	mlx->map_width = size - 1;
}

int	check_fb(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (ft_isdigit(a[i][j]) || a[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	get_map2(t_mlx *mlx)
{
	int	f;
	int	i;
	int	o;
	int	j;

	f = get_map(mlx);
	i = f;
	o = 0;
	j = 0;
	while (mlx->line[f])
	{
		f++;
		o++;
	}
	mlx->map = malloc(sizeof(char *) * (o + 1));
	while (mlx->line[i])
	{
		mlx->map[j] = ft_strdup(mlx->line[i]);
		checking_err(mlx, j);
		j++;
		i++;
	}
	mlx->map[j] = NULL;
	mlx->map_height = j;
}

double	dst(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
