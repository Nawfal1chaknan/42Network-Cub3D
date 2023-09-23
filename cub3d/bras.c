/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bras.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:37:39 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/21 14:07:47 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_bras *bras)
{
	if (bras->y1 < bras->y2)
		bras->sy = 1;
	else
		bras->sy = -1;
	if (bras->x1 < bras->x2)
		bras->sx = 1;
	else
		bras->sx = -1;
	bras->dy = abs(bras->y2 - bras->y1);
	bras->dx = abs(bras->x2 - bras->x1);
	bras->err = bras->dx - bras->dy;
}

void	draw_line_playerr(t_mlx *mlx, t_bras *bras)
{
	int32_t	color;
	int		e2;

	init(bras);
	while (1)
	{
		color = 0xffffff;
		mlx_put_pixel(mlx->mini_map, bras->x1, bras->y1, color);
		if (bras->x1 == bras->x2 && bras->y1 == bras->y2)
			break ;
		e2 = 2 * bras->err;
		if (e2 > -bras->dy)
		{
			bras->err -= bras->dy;
			bras->x1 += bras->sx;
		}
		if (e2 < bras->dx)
		{
			bras->err += bras->dx;
			bras->y1 += bras->sy;
		}
	}
	free(bras);
}

void	init1(t_brass *bras)
{
	if (bras->y1 < bras->y2)
		bras->sy = 1;
	else
		bras->sy = -1;
	if (bras->x1 < bras->x2)
		bras->sx = 1;
	else
		bras->sx = -1;
	bras->dy = abs(bras->y2 - bras->y1);
	bras->dx = abs(bras->x2 - bras->x1);
	bras->err = bras->dx - bras->dy;
}

void	draw_line_player(t_mlx *mlx, t_brass *bras, int color)
{
	int		e2;

	init1(bras);
	while (1)
	{
		if (bras->x1 >= 0 && bras->x1 < mlx->window_width \
			&& bras->y1 >= 0 && bras->y1 < mlx->window_height)
			mlx_put_pixel(mlx->window, bras->x1, bras->y1, color);
		if (bras->x1 == bras->x2 && bras->y1 == bras->y2)
			break ;
		e2 = 2 * bras->err;
		if (e2 > -bras->dy)
		{
			bras->err -= bras->dy;
			bras->x1 += bras->sx;
		}
		if (e2 < bras->dx)
		{
			bras->err += bras->dx;
			bras->y1 += bras->sy;
		}
	}
}
