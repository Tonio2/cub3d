/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funny_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:11:46 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/29 14:45:26 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

int	press_hook(int keycode, t_vars *vars)
{
	double	speed;
	double	vRot;
	double	oldDirX;
	double	oldPlaneX;

	speed = 0.1;
	vRot = 0.1;
	if (keycode == 123)
	{
		oldDirX = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(-vRot) - vars->dir.y * sin(-vRot);
		vars->dir.y = oldDirX * sin(-vRot) + vars->dir.y * cos(-vRot);
		oldPlaneX = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(-vRot) - vars->plane.y * sin(-vRot);
		vars->plane.y = oldPlaneX * sin(-vRot) + vars->plane.y * cos(-vRot);
	}
	if (keycode == 124)
	{
		oldDirX = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(vRot) - vars->dir.y * sin(vRot);
		vars->dir.y = oldDirX * sin(vRot) + vars->dir.y * cos(vRot);
		oldPlaneX = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(vRot) - vars->plane.y * sin(vRot);
		vars->plane.y = oldPlaneX * sin(vRot) + vars->plane.y * cos(vRot);
	}
	if (keycode == 125)
	{
		if (vars->config.map[(int)(vars->pos.y)]
				[(int)(vars->pos.x - vars->dir.x * speed)] != '1')
			vars->pos.x -= vars->dir.x * speed;
		if (vars->config.map[(int)(vars->pos.y - vars->dir.y * speed)]
				[(int)(vars->pos.x)] != '1')
			vars->pos.y -= vars->dir.y * speed;
	}
	if (keycode == 126)
	{
		if (vars->config.map[(int)(vars->pos.y)]
				[(int)(vars->pos.x + vars->dir.x * speed)] != '1')
			vars->pos.x += vars->dir.x * speed;
		if (vars->config.map[(int)(vars->pos.y + vars->dir.y * speed)]
				[(int)(vars->pos.x)] != '1')
			vars->pos.y += vars->dir.y * speed;
	}
	return (0);
}

void	ft_init_dda(t_vars *vars, int x, t_DDA *dda)
{
	dda->cameraX = 2 * x / (double)vars->config.dim_y - 1;
	dda->rayDirX = vars->dir.x + vars->plane.x * dda->cameraX;
	dda->rayDirY = vars->dir.y + vars->plane.y * dda->cameraX;
	dda->mapX = (int)(vars->pos.x);
	dda->mapY = (int)(vars->pos.y);
	dda->deltaDistX = fabs(1 / dda->rayDirX);
	dda->deltaDistY = fabs(1 / dda->rayDirY);
	dda->hit = 0;
}

void	ft_dda(t_vars *vars, t_DDA *dda)
{
	dda->stepX = (dda->rayDirX >= 0) - (dda->rayDirX < 0);
	dda->stepY = (dda->rayDirY >= 0) - (dda->rayDirY < 0);
	if (dda->rayDirX < 0)
		dda->sideDistX = (vars->pos.x - dda->mapX) * dda->deltaDistX;
	else
		dda->sideDistX = (dda->mapX + 1.0 - vars->pos.x) * dda->deltaDistX;
	if (dda->rayDirY < 0)
		dda->sideDistY = (vars->pos.y - dda->mapY) * dda->deltaDistY;
	else
		dda->sideDistY = (dda->mapY + 1.0 - vars->pos.y) * dda->deltaDistY;
	while (dda->hit == 0)
	{
		dda->side = (dda->sideDistX >= dda->sideDistY);
		if (dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->deltaDistX;
			dda->mapX += dda->stepX;
		}
		else
		{
			dda->sideDistY += dda->deltaDistY;
			dda->mapY += dda->stepY;
		}
		dda->hit = (vars->config.map[dda->mapY][dda->mapX] == '1');
	}
}

void	ft_dda_lineheight(t_vars *vars, t_DDA *dda)
{
	if (dda->side == 0)
		dda->perpWallDist = (dda->mapX - vars->pos.x
				+ (1 - dda->stepX) / 2) / dda->rayDirX;
	else
		dda->perpWallDist = (dda->mapY - vars->pos.y
				+ (1 - dda->stepY) / 2) / dda->rayDirY;
	dda->lineHeight = (vars->config.dim_y
			/ (2 * dda->perpWallDist * tan(M_PI / 6))) * 0.88;
	dda->draw.drawStart = (int)(-dda->lineHeight / 2 + vars->config.dim_x / 2);
	if (dda->draw.drawStart < 0)
		dda->draw.drawStart = 0;
	dda->draw.drawEnd = (int)(dda->lineHeight / 2 + vars->config.dim_x / 2);
	if (dda->draw.drawEnd >= vars->config.dim_x)
		dda->draw.drawEnd = vars->config.dim_x - 1;
}

void	ft_draw_line(t_vars *vars, int x, t_DDA *dda)
{
	if (dda->side == 0)
	{
		dda->wallX = vars->pos.y + dda->perpWallDist * dda->rayDirY;
		dda->textype = (dda->rayDirX > 0) * 3 + (dda->rayDirX < 0) * 2;
	}
	else
	{
		dda->wallX = vars->pos.x + dda->perpWallDist * dda->rayDirX;
		dda->textype = (dda->rayDirY > 0) * 1 + (dda->rayDirY < 0) * 0;
	}
	dda->wallX -= floor((dda->wallX));
	dda->texX = (int)(dda->wallX * (double)(64));
	if (dda->side == 0 && dda->rayDirX > 0)
		dda->texX = 64 - dda->texX - 1;
	if (dda->side == 1 && dda->rayDirY < 0)
		dda->texX = 64 - dda->texX - 1;
	dda->step = 64.0 / dda->lineHeight;
	dda->texPos = (dda->draw.drawStart - vars->config.dim_x / 2
			+ dda->lineHeight / 2) * dda->step;
	dda->y = dda->draw.drawStart - 1;
	while (++dda->y < dda->draw.drawEnd)
	{
		dda->texY = (int)dda->texPos;
		dda->texPos += dda->step;
		dda->color = ft_get_color(&vars->teximg[dda->textype], dda->texX, dda->texY);
		my_mlx_pixel_put(&vars->img, x, dda->y, dda->color);
	}
}

int	ft_update(t_vars *vars)
{
	int				x;
	t_DDA			dda;

	x = -1;
	while (++x < vars->config.dim_y)
	{
		dda.draw.drawStart = 0;
		dda.draw.drawEnd = vars->config.dim_x - 1;
		ft_verline(&vars->img, x, dda.draw, 0x000000);
	}
	x = -1;
	while (++x < vars->config.dim_y)
	{
		ft_init_dda(vars, x, &dda);
		ft_dda(vars, &dda);
		ft_dda_lineheight(vars, &dda);
		ft_draw_line(vars, x, &dda);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
