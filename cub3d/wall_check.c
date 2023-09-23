/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:13:15 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/21 20:31:08 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	part_of_haswallcircle(t_mlx *mlx, int x, int y)
{
	int	mapindexx;
	int	mapindexy;

	mapindexx = (int)(x / TILE_SIZE);
	mapindexy = (int)(y / TILE_SIZE);
	if (mapindexx >= 0 && mapindexx < mlx->map_width && \
		mapindexy >= 0 && mapindexy < mlx->map_height)
		if (mlx->map[mapindexy][mapindexx] == '1')
			return (1);
	return (0);
}

int	haswallcircle(t_mlx *mlx, int playerX, int playerY)
{
	int		x;
	int		y;
	int		angle;
	double	radians;
	int		distance;

	angle = 0;
	while (angle < 360)
	{
		distance = 1;
		while (distance <= RADIUS)
		{
			radians = angle * (M_PI / 180.0);
			x = playerX + (int)(distance * cos(radians));
			y = playerY + (int)(distance * sin(radians));
			if (x >= 0 && x < mlx->window_width * TILE_SIZE && \
				y >= 0 && y < mlx->window_height * TILE_SIZE)
				if (part_of_haswallcircle(mlx, x, y))
					return (1);
			distance++;
		}
		angle += 10;
	}
	return (0);
}

int	haswall(t_mlx *mlx, int x, int y)
{
	int	mapindexx;
	int	mapindexy;

	if (x < 0 || x > mlx->window_width * TILE_SIZE || \
		y < 0 || y > mlx->window_height * TILE_SIZE)
		return (1);
	mapindexx = (int)(x / TILE_SIZE);
	mapindexy = (int)(y / TILE_SIZE);
	if (mapindexy < mlx->map_height && \
		mapindexx < (int)ft_strlen(mlx->map[mapindexy]))
	{
		if (mlx->map[mapindexy][mapindexx] == '1')
			return (1);
	}
	return (0);
}

double	norm(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	else if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
