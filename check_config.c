/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:35:24 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/29 16:52:28 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	ft_check_config(t_cub *c)
{
	ft_check_color(c->bg[0]);
	ft_check_color(c->bg[1]);
	ft_check_map(c);
}

void	ft_check_color(int *bg)
{
	int	cpt;

	cpt = -1;
	while (++cpt < 3)
		if (bg[cpt] > 255)
			ft_print_error("Unknown color");
}

void	ft_check_map(t_cub *c)
{
	int	row;
	int	col;

	row = -1;
	while (++row < c->height)
	{
		col = -1;
		while (++col < c->width)
		{
			if (c->map[row][col] == ' ')
			{
				if (row == 0 || row == c->height - 1)
					ft_print_error("Map not closed");
				if (col == 0 || col == c->width - 1)
					ft_print_error("Map not closed");
				if (c->map[row - 1][col] == 'X' || c->map[row + 1][col] == 'X')
					ft_print_error("Map not closed");
				if (c->map[row][col - 1] == 'X' || c->map[row][col + 1] == 'X')
					ft_print_error("Map not closed");
			}
		}
	}
}
