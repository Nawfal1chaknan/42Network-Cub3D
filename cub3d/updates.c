/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:33:03 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/21 18:09:54 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part_of_updates(t_mlx *mlx, double newplayer1, double newplayer0)
{
	if (mlx->washitvertical)
	{
		if (!haswallcircle(mlx, mlx->mv->x, newplayer1))
		{
			mlx->mv->y = newplayer1;
			if (!haswallcircle(mlx, newplayer0, newplayer1))
				mlx->mv->x = newplayer0;
		}
	}
	else
	{
		if (!haswallcircle(mlx, newplayer0, mlx->mv->y))
		{
			mlx->mv->x = newplayer0;
			if (!haswallcircle(mlx, newplayer0, newplayer1))
				mlx->mv->y = newplayer1;
		}
	}
}

void	update3(t_mlx *mlx)
{
	double	newplayer0;
	double	newplayer1;

	mlx->mv_step = mlx->mv->walk_direction * mlx->mv->move_speed;
	newplayer0 = mlx->mv->x + \
		cos(mlx->mv->rotationangle + (M_PI / 2)) * mlx->mv_step;
	newplayer1 = mlx->mv->y + \
		sin(mlx->mv->rotationangle + (M_PI / 2)) * mlx->mv_step;
	part_of_updates(mlx, newplayer1, newplayer0);
}

void	update2(t_mlx *mlx)
{
	double	newplayer0;
	double	newplayer1;

	mlx->mv_step = mlx->mv->walk_direction * mlx->mv->move_speed;
	newplayer0 = mlx->mv->x + cos(mlx->mv->rotationangle) * mlx->mv_step;
	newplayer1 = mlx->mv->y + sin(mlx->mv->rotationangle) * mlx->mv_step;
	part_of_updates(mlx, newplayer1, newplayer0);
}

void	update(t_mlx *mlx)
{
	mlx->mv->rotationangle = norm(mlx->mv->rotationangle);
	mlx->mv->rotationangle += mlx->mv->turn_direction * mlx->mv->rotation_speed;
	mlx->mv->rotationangle = norm(mlx->mv->rotationangle);
}
