/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_horver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:36:19 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/21 23:18:33 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialisation_hor(t_mlx *mlx)
{
	mlx->yinsterept = (int)(mlx->mv->y / TILE_SIZE) * TILE_SIZE;
	if (mlx->down)
		mlx->yinsterept += TILE_SIZE;
	else
		mlx->yinsterept += 0;
	mlx->xinsterept = mlx->mv->x + \
		(mlx->yinsterept - mlx->mv->y) / tan(mlx->ray_angle);
	mlx->ystep = TILE_SIZE;
	if (mlx->up)
		mlx->ystep *= -1;
	else
		mlx->ystep *= 1;
	mlx->xstep = TILE_SIZE / tan(mlx->ray_angle);
	if (mlx->left && mlx->xstep > 0)
		mlx->xstep *= -1;
	else
		mlx->xstep *= 1;
	if (mlx->right && mlx->xstep < 0)
		mlx->xstep *= -1;
	else
		mlx->xstep *= 1;
	mlx->xnexthor = mlx->xinsterept;
	mlx->ynexthor = mlx->yinsterept;
}

void	part_2(t_mlx *mlx, double horhitdst, double verhitdst)
{
	if (horhitdst < verhitdst)
		mlx->xwall_hit = mlx->horx;
	else
		mlx->xwall_hit = mlx->wallx;
	if (horhitdst < verhitdst)
		mlx->ywall_hit = mlx->hory;
	else
		mlx->ywall_hit = mlx->wally;
	if (horhitdst < verhitdst)
		mlx->distance = horhitdst;
	else
		mlx->distance = verhitdst;
	mlx->distance = mlx->distance * \
		cos(mlx->ray_angle - mlx->mv->rotationangle);
	if (verhitdst < horhitdst)
		mlx->washitvertical = true;
	else
		mlx->washitvertical = false;
}

void	ver_or_hor(t_mlx *mlx)
{
	double	horhitdst;
	double	verhitdst;
	t_bras	*bras;

	bras = malloc(sizeof(t_bras));
	if (mlx->foundwall)
		horhitdst = dst(mlx->mv->x, mlx->mv->y, mlx->horx, mlx->hory);
	else
		horhitdst = DBL_MAX;
	if (mlx->foundvwall)
		verhitdst = dst(mlx->mv->x, mlx->mv->y, mlx->wallx, mlx->wally);
	else
		verhitdst = DBL_MAX;
	part_2(mlx, horhitdst, verhitdst);
	bras->x1 = MINIMAP_FACTOR * mlx->mv->x;
	bras->y1 = MINIMAP_FACTOR * mlx->mv->y;
	bras->x2 = MINIMAP_FACTOR * mlx->xwall_hit;
	bras->y2 = MINIMAP_FACTOR * mlx->ywall_hit;
	draw_line_playerr(mlx, bras);
}

void	initialisation_ver(t_mlx *mlx)
{
	mlx->xinsterept = (int)(mlx->mv->x / TILE_SIZE) * TILE_SIZE;
	if (mlx->right)
		mlx->xinsterept += TILE_SIZE;
	else
		mlx->xinsterept += 0;
	mlx->yinsterept = mlx->mv->y + \
		(mlx->xinsterept - mlx->mv->x) * tan(mlx->ray_angle);
	mlx->xstep = TILE_SIZE;
	if (mlx->left)
		mlx->xstep *= -1;
	else
		mlx->xstep *= 1;
	mlx->ystep = TILE_SIZE * tan(mlx->ray_angle);
	if (mlx->up && mlx->ystep > 0)
		mlx->ystep *= -1;
	else
		mlx->ystep *= 1;
	if (mlx->down && mlx->ystep < 0)
		mlx->ystep *= -1;
	else
		mlx->ystep *= 1;
	mlx->xnextvert = mlx->xinsterept;
	mlx->ynextvert = mlx->yinsterept;
}
