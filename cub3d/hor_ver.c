/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_ver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:35:04 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 05:57:15 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialisation(t_mlx *mlx)
{
	mlx->down = false;
	mlx->up = false;
	mlx->right = false;
	mlx->left = false;
	if (mlx->ray_angle > 0 && mlx->ray_angle < M_PI)
		mlx->down = true;
	else
		mlx->up = true;
	if (mlx->ray_angle < M_PI_2 || mlx->ray_angle > 3 * M_PI_2)
		mlx->right = true;
	else
		mlx->left = true;
}

void	last_check(t_mlx *mlx)
{
	mlx->foundvwall = false;
	mlx->wally = 0;
	initialisation_ver(mlx);
	while (mlx->xnextvert >= 0 && \
		mlx->xnextvert <= mlx->window_width * TILE_SIZE \
			&& mlx->ynextvert >= 0 && \
				mlx->ynextvert <= mlx->window_width * TILE_SIZE)
	{
		syc(mlx);
		if (haswall(mlx, mlx->ress, mlx->ynextvert))
		{
			mlx->foundvwall = true;
			mlx->wallx = mlx->xnextvert;
			mlx->wally = mlx->ynextvert;
			break ;
		}
		else
		{
			mlx->xnextvert += mlx->xstep;
			mlx->ynextvert += mlx->ystep;
		}
	}
	ver_or_hor(mlx);
}

void	new_cast(t_mlx *mlx)
{
	mlx->horx = 0;
	mlx->foundwall = false;
	mlx->ray_angle = norm(mlx->ray_angle);
	initialisation(mlx);
	initialisation_hor(mlx);
	while (mlx->xnexthor >= 0 && mlx->xnexthor <= mlx->window_width * TILE_SIZE \
		&& mlx->ynexthor >= 0 && mlx->ynexthor <= mlx->window_width * TILE_SIZE)
	{
		sycc(mlx);
		if (haswall(mlx, mlx->xnexthor, mlx->res))
		{
			mlx->foundwall = true;
			mlx->horx = mlx->xnexthor;
			mlx->hory = mlx->ynexthor;
			break ;
		}
		else
		{
			mlx->xnexthor += mlx->xstep;
			mlx->ynexthor += mlx->ystep;
		}
	}
	last_check(mlx);
}

void	part_of_cast(t_mlx *mlx, int i, t_brass *bras)
{
	int	y;

	y = 0;
	while (y < TEX_SZ)
	{
		bras->x1 = i;
		bras->y1 = mlx->y_start;
		bras->x2 = i;
		bras->y2 = mlx->y_start + mlx->y_step;
		draw_line_player(mlx, bras, mlx->img[TEX_SZ * y + mlx->tex_x]);
		mlx->y_start += mlx->y_step;
		y++;
	}
}

void	d1(t_brass *bras, t_mlx *mlx, int i)
{
	bras->x1 = i;
	bras->y1 = (WINDOW_HEIGHT / 2) + (mlx->wallheight / 2);
	bras->x2 = i;
	bras->y2 = WINDOW_HEIGHT;
	draw_line_player(mlx, bras, \
		(ft_atoi(mlx->floor[0]) * \
			ft_atoi(mlx->floor[1]) * ft_atoi(mlx->floor[2])));
}
