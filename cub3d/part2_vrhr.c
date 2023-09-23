/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_vrhr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:08:58 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 05:52:09 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d2(t_brass *bras, t_mlx *mlx, int i)
{
	bras->x1 = i;
	bras->y1 = 0;
	bras->x2 = i;
	bras->y2 = (WINDOW_HEIGHT / 2) - (mlx->wallheight / 2);
	draw_line_player(mlx, bras, (ft_atoi(mlx->sky[0]) \
		* ft_atoi(mlx->sky[1]) * ft_atoi(mlx->sky[2])));
}

void	cast_rays(t_mlx *mlx)
{
	t_brass	*bras;

	bras = malloc(sizeof(t_brass));
	mlx->i = 0;
	mlx->ray_angle = mlx->mv->rotationangle - (M_PI / 6);
	while (mlx->i < mlx->num_rays)
	{
		mlx->ray_angle += (FOV) / (double)mlx->num_rays;
		new_cast(mlx);
		check_directions(mlx);
		mlx->dstprojplane = ((mlx->window_width) / 2) / tan(FOV / 2);
		mlx->wallheight = (TILE_SIZE / mlx->distance) * mlx->dstprojplane;
		mlx->wall_start = (mlx->window_height / 2) - (mlx->wallheight / 2);
		d2(bras, mlx, mlx->i);
		mlx->y_step = (mlx->wallheight / TEX_SZ);
		mlx->y_start = (double)mlx->wall_start;
		if (mlx->washitvertical)
			mlx->tex_x = (int)mlx->ywall_hit % TEX_SZ;
		else
			mlx->tex_x = (int)mlx->xwall_hit % TEX_SZ;
		part_of_cast(mlx, mlx->i, bras);
		d1(bras, mlx, mlx->i);
		mlx->i++;
	}
	free(bras);
}
