/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:46:18 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 07:10:10 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_directions(t_mlx *mlx)
{
	if (mlx->washitvertical == false && (mlx->hory) > mlx->mv->y)
		mlx->img = mlx->tex_south;
	else if (mlx->washitvertical == true && (mlx->wallx) < mlx->mv->x)
		mlx->img = mlx->tex_west;
	else if (mlx->washitvertical == true)
		mlx->img = mlx->tex_east;
	else
		mlx->img = mlx->tex_north;
}

void	draw_background(t_mlx *mlx, uint32_t floor, mlx_image_t *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_FACTOR * (mlx->map_height * TILE_SIZE))
	{
		j = 0;
		while (j < MINIMAP_FACTOR * (mlx->map_width * TILE_SIZE))
		{
			mlx_put_pixel(image, j, i, floor);
			j++;
		}
		i++;
	}
}

void	part_of_psp(t_mlx *mlx, int x, int y)
{
	if (mlx->map[x][y] == 'W')
		mlx->check_dir = M_PI;
	else if (mlx->map[x][y] == 'N')
		mlx->check_dir = (M_PI + (M_PI / 2));
	else if (mlx->map[x][y] == 'E')
		mlx->check_dir = M_PI * 2;
	else if (mlx->map[x][y] == 'S')
		mlx->check_dir = M_PI / 2;
}

void	player_position(t_mlx *mlx)
{
	int	x;
	int	y;
	int	o;

	x = 0;
	o = 0;
	while (mlx->map[x])
	{
		y = 0;
		while (mlx->map[x][y])
		{
			if (mlx->map[x][y] == 'W' || mlx->map[x][y] == 'N' || \
				mlx->map[x][y] == 'S' || mlx->map[x][y] == 'E')
			{
				o = 1;
				part_of_psp(mlx, x, y);
				mlx->mv->x = (y + 0.5) * TILE_SIZE;
				mlx->mv->y = (x + 0.5) * TILE_SIZE;
				break ;
			}
			y++;
		}
		x++;
	}
	error(o);
}

void	draw(t_mlx *mlx, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_FACTOR * TILE_SIZE)
	{
		y = 0;
		while (y < MINIMAP_FACTOR * TILE_SIZE)
		{
			mlx_put_pixel(mlx->mini_map, j + x, i + y, 0xffffffff);
			if (x == 0 || y == 0 || x == MINIMAP_FACTOR * TILE_SIZE - 1 \
				|| y == MINIMAP_FACTOR * TILE_SIZE - 1)
				mlx_put_pixel(mlx->mini_map, j + x, i + y, 1000);
			y++;
		}
		x++;
	}
}
