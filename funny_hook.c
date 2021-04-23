/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funny_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:11:46 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/23 18:49:27 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

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

int	press_hook(int keycode, t_vars *vars)
{
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;

	moveSpeed = 0.1;
	rotSpeed = 0.1;
	if (keycode == 123)
	{
		oldDirX = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(-rotSpeed) - vars->dir.y * sin(-rotSpeed);
		vars->dir.y = oldDirX * sin(-rotSpeed) + vars->dir.y * cos(-rotSpeed);
		oldPlaneX = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(-rotSpeed) - vars->plane.y * sin(-rotSpeed);
		vars->plane.y = oldPlaneX * sin(-rotSpeed) + vars->plane.y * cos(-rotSpeed);
	}
	if (keycode == 124)
	{
		oldDirX = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(rotSpeed) - vars->dir.y * sin(rotSpeed);
		vars->dir.y = oldDirX * sin(rotSpeed) + vars->dir.y * cos(rotSpeed);
		oldPlaneX = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(rotSpeed) - vars->plane.y * sin(rotSpeed);
		vars->plane.y = oldPlaneX * sin(rotSpeed) + vars->plane.y * cos(rotSpeed);
	}
	if (keycode == 125)
	{
		if (vars->config.map[(int)(vars->pos.y)][(int)(vars->pos.x - vars->dir.x * moveSpeed)] != '1')
			vars->pos.x -= vars->dir.x * moveSpeed;
		if (vars->config.map[(int)(vars->pos.y - vars->dir.y * moveSpeed)][(int)(vars->pos.x)] != '1')
			vars->pos.y -= vars->dir.y * moveSpeed;
	}
	if (keycode == 126)
	{
		if (vars->config.map[(int)(vars->pos.y)][(int)(vars->pos.x + vars->dir.x * moveSpeed)] != '1')
			vars->pos.x += vars->dir.x * moveSpeed;
		if (vars->config.map[(int)(vars->pos.y + vars->dir.y * moveSpeed)][(int)(vars->pos.x)] != '1')
			vars->pos.y += vars->dir.y * moveSpeed;
	}
	return (0);
}

int	ft_update(t_vars *vars)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	h;
	int		y;

	h = 480.0;
	x = -1;
	while (++x < 640)
	{
		y = -1;
		while (++y < 480)
			my_mlx_pixel_put(&vars->img, x, y, 0x00000000);
	}
	x = -1;
	while (++x < 640)
	{
		cameraX = 2 * x / 640.0 - 1;
		rayDirX = vars->dir.x + vars->plane.x * cameraX;
		rayDirY = vars->dir.y + vars->plane.y * cameraX;
		mapX = (int)(vars->pos.x);
		mapY = (int)(vars->pos.y);
		deltaDistX = (1 / rayDirX);
		deltaDistY = (1 / rayDirY);
		if (deltaDistX < 0)
			deltaDistX *= -1;
		if (deltaDistY < 0)
			deltaDistY *= -1;
		hit = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (vars->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - vars->pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (vars->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - vars->pos.y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (vars->config.map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - vars->pos.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - vars->pos.y + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(h / perpWallDist);
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		ft_verline(&vars->img, x, drawStart, drawEnd, side);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
