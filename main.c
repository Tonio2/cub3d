/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:34:23 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 14:48:06 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "constant.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_cub	config;

	if (ac != 2)
	{
		printf("Usage : ./cub3d config_file_path");
		return (1);
	}
	parse_config(av[1], &config);
	printf("%d", config.dim_x);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
