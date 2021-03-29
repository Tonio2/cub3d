/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:29:58 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/29 15:32:34 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	ft_convert_map_char(char c, t_cub *config, int row, int column)
{
	static int	orientation_received;

	if (c == ' ')
		config->map[row][column] = 'X';
	else if (c == '0')
		config->map[row][column] = ' ';
	else if (c == '1')
		config->map[row][column] = '1';
	else if (c == '2')
		config->map[row][column] = '2';
	else if (ft_in(c, "WNES"))
	{
		config->map[row][column] = ' ';
		if (orientation_received)
			ft_print_error("Two initial orientation given");
		orientation_received = 1;
	}
	else
		ft_print_error("unknowm character in map");
}

void	ft_parse_map_lines(t_map_line *first_line, t_cub *config)
{
	int			height;
	int			width;
	t_map_line	*cur_line;
	int			cpt;

	height = 0;
	width = 0;
	cur_line = first_line;
	while (cur_line)
	{
		height++;
		if (ft_len(cur_line->line) > width)
			width = ft_len(cur_line->line);
		cur_line = cur_line->next;
	}
	config->height = height;
	config->width = width;
	config->map = malloc(height * sizeof(char *));
	height = 0;
	cur_line = first_line;
	while (cur_line)
	{
		config->map[height] = malloc(width);
		cpt = -1;
		while (cur_line->line[++cpt])
			ft_convert_map_char(cur_line->line[cpt], config, height, cpt);
		while (cpt < width)
			config->map[height][cpt++] = 'X';
		cur_line = cur_line->next;
		height++;
	}
}
