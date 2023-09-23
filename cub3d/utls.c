/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:46:10 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 22:26:52 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	syc(t_mlx *mlx)
{
	if (mlx->left)
		mlx->ress = mlx->xnextvert - 1;
	else
		mlx->ress = mlx->xnextvert;
}

void	sycc(t_mlx *mlx)
{
	if (mlx->up)
		mlx->res = mlx->ynexthor - 1;
	else
		mlx->res = mlx->ynexthor;
}

void	ini(t_mlx *mlx)
{
	mlx->no = NULL;
	mlx->so = NULL;
	mlx->we = NULL;
	mlx->ea = NULL;
	mlx->floor = NULL;
	mlx->sky = NULL;
}

void	range_of_cnf(t_mlx *mlx)
{
	if (ft_strllen(mlx->sky) != 3 || \
		mlx->sky[ft_strllen(mlx->sky) - 1][0] == '\n')
		print_err("ERROR\n");
	if ((mlx->sky[0] && mlx->sky[1] && mlx->sky[2] && \
		ft_atoi(mlx->sky[0]) > 255) \
			|| ft_atoi(mlx->sky[1]) > 255 || ft_atoi(mlx->sky[2]) > 255)
		print_err("ERROR\n");
}

void	range_of_cnff(t_mlx *mlx)
{
	if (ft_strllen(mlx->floor) != 3 || \
		mlx->floor[ft_strllen(mlx->floor) - 1][0] == '\n')
		print_err("ERROR\n");
	if ((mlx->floor[0] && mlx->floor[1] && \
		mlx->floor[2] && ft_atoi(mlx->floor[0]) > 255) \
			|| ft_atoi(mlx->floor[1]) > 255 || ft_atoi(mlx->floor[2]) > 255)
		print_err("ERROR\n");
}
