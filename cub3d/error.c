/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:56:16 by nchaknan          #+#    #+#             */
/*   Updated: 2023/09/23 22:29:43 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char *err)
{
	printf("%s", err);
	exit(1);
}

void	checking_err(t_mlx *mlx, int i)
{
	int	j;

	j = 0;
	while (mlx->map[i][j])
	{
		if (mlx->map[i][0] == '\n' || mlx->map[i][j] == '\t' || \
		(mlx->map[i][j] == '\n' && mlx->map[i][j - 1] != '1' && \
			mlx->map[i][j - 1] != '0'))
			print_err("ERROE :: invalid map !!\n");
		j++;
	}
}

void	part_of_it(t_mlx *mlx)
{
	int	j;

	j = 0;
	checkk(mlx);
	while (mlx->map[0][j] != '\n')
	{
		if ((mlx->map[0][j] != '1') && (mlx->map[0][j] != ' '))
			print_err("ERROR :: invalid map !!\n");
		j++;
	}
	j = 0;
	while (mlx->map[mlx->map_height - 1][j] != '\n')
	{
		if ((mlx->map[mlx->map_height - 1][j] != '1') \
			&& (mlx->map[mlx->map_height - 1][j] != ' '))
			print_err("ERROE :: invalid map !!\n");
		j++;
	}
}

void	part_of_it2(t_mlx *mlx, int i, int j)
{
	if (!mlx->map[i][j + 1])
		print_err("ERROE :: invalid map !!\n");
	if (!mlx->map[i][j - 1])
		print_err("ERROE :: invalid map !!\n");
	if (!mlx->map[i + 1][j])
		print_err("ERROE :: invalid map !!\n");
	if (!mlx->map[i - 1][j])
		print_err("ERROE :: invalid map !!\n");
}

void	part_ot_valid_map(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i + 1][j] == '\0' || \
		mlx->map[i - 1][j] == '\0' || mlx->map[i][j + 1] == '\0' \
			|| mlx->map[i][j - 1] == '\0')
		print_err("ERROE :: invalid map !!\n");
	if (mlx->map[i + 1][j] == '\n' || \
		mlx->map[i - 1][j] == '\n' || mlx->map[i][j + 1] == '\n' \
			|| mlx->map[i][j - 1] == '\n')
		print_err("ERROE :: invalid map !!\n");
	if (mlx->map[i + 1][j] == ' ' || \
		mlx->map[i - 1][j] == ' ' || mlx->map[i][j + 1] == ' ' \
			|| mlx->map[i][j - 1] == ' ')
		print_err("ERROE :: invalid map !!\n");
}
