/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:35:32 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/26 13:25:46 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	ft_config_init(t_cub *config)
{
	int	cpt;

	cpt = 0;
	while (cpt++ < 8)
		config->config_ready[cpt] = 0;
	config->dim_x = 0;
	config->dim_y = 0;
	config->bg[0][0] = 0;
	config->bg[0][1] = 0;
	config->bg[0][2] = 0;
	config->bg[1][0] = 0;
	config->bg[1][1] = 0;
	config->bg[1][2] = 0;
}

int	is_config_ready(t_cub *config)
{
	int	cpt;

	cpt = 0;
	while (cpt < 8)
	{
		if (config->config_ready[cpt] == 0)
			return (0);
		cpt++;
	}
	return (1);
}

void	ft_parse_config(int fd, t_cub *config)
{
	char	*line;

	line = 0;
	while (!is_config_ready(config))
	{
		if (ft_len(line))
			ft_parse_config_line(line, config);
		if (get_next_line(fd, &line) <= 0)
			ft_print_error("Erreur lors de la lecture du fichier");
	}
	while (ft_len(line) == 0)
		if (get_next_line(fd, &line) <= 0)
			ft_print_error("Erreur lors de la lecture du fichier");
}

char	**ft_parse_map(int fd)
{
	char	**lines;

	lines = 0;
	fd++;
	return (lines);
}

void	ft_parse_config_file(char *filename, t_cub *config)
{
	int		fd;
	char	**map_lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(strerror(errno));
	ft_config_init(config);
	ft_parse_config(fd, config);
	map_lines = ft_parse_map(fd);
	ft_parse_map_lines(map_lines, config);
}
