/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funny_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:11:46 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/22 17:39:11 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

int	key_hook(int keycode, t_vars *vars)
{
	vars->c.x += (keycode == 124) - (keycode == 123);
	vars->c.y += (keycode == 125) - (keycode == 126);
	return (0);
}

int	press_hook(int keycode, t_vars *vars)
{
	if (keycode == 124)
		vars->c.speed_x = 1;
	if (keycode == 123)
		vars->c.speed_x = -1;
	if (keycode == 125)
		vars->c.speed_y = 1;
	if (keycode == 126)
		vars->c.speed_y = -1;
	return (0);
}

int	release_hook(int keycode, t_vars *vars)
{
	if (keycode == 124 || keycode == 123)
		vars->c.speed_x = 0;
	if (keycode == 125 || keycode == 126)
		vars->c.speed_y = 0;
	return (0);
}

int	esc_close_window(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	keycode++;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(void)
{
	printf("Yo!\n");
	return (0);
}

int	ft_update(t_vars *vars)
{
	int		x;
	int		y;

	vars->c.x += vars->c.speed_x;
	vars->c.y += vars->c.speed_y;
	x = -1;
	while (++x < 640)
	{
		y = -1;
		while (++y < 480)
			my_mlx_pixel_put(&vars->img, x, y, 0x00000000);
	}
	ft_print_rainbow(&vars->img, vars->c.x, vars->c.y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
