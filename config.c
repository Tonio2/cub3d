/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:35:32 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/26 15:04:50 by alabalet         ###   ########.fr       */
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
		if (get_next_line(fd, &line) <= 0)
			ft_print_error("Erreur lors de la lecture du fichier");
		if (ft_len(line))
			ft_parse_config_line(line, config);
	}
}

t_map_line	*ft_parse_map(int fd)
{
	t_map_line	*first_elt;
	t_map_line	*last_elt;
	t_map_line	*cur_elt;
	char		*line;
	int			gnl_ret;

	first_elt = malloc(sizeof(t_map_line));
	first_elt->next = 0;
	last_elt = first_elt;
	cur_elt = first_elt;
	line = 0;
	while (ft_len(line) == 0)
		get_next_line(fd, &line);
	first_elt->line = ft_strcreate(line);
	gnl_ret = get_next_line(fd, &line);
	while (gnl_ret == 1 && ft_len(line))
	{
		cur_elt = malloc(sizeof(t_map_line));
		last_elt->next = cur_elt;
		cur_elt->line = ft_strcreate(line);
		cur_elt->next = 0;
		last_elt = cur_elt;
		gnl_ret = get_next_line(fd, &line);
	}
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		if (ft_len(line))
			ft_print_error("Non empty line after map");
	}
	return (first_elt);
}

void	ft_print_map_lines(t_map_line *first_elt)
{
	while (first_elt)
	{
		printf("%s\n", first_elt->line);
		first_elt = first_elt->next;
	}
}

void	ft_parse_config_file(char *filename, t_cub *config)
{
	int			fd;
	t_map_line	*map_lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(strerror(errno));
	ft_config_init(config);
	ft_parse_config(fd, config);
	map_lines = ft_parse_map(fd);
	ft_print_map_lines(map_lines);
	//ft_parse_map_lines(map_lines, config);
}
