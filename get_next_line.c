/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:10:48 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 15:12:55 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

int	ft_len(char *str)
{
	int	cpt;

	if (!str)
		return (0);
	cpt = 0;
	while (*(str++))
		cpt++;
	return (cpt);
}

void	ft_strcpy(char *dst, char *src)
{
	int	cpt;

	cpt = 0;
	while (src[cpt])
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	dst[cpt] = '\0';
}

void	ft_strcat(char **dst, char *src)
{
	int		len;
	char	*tmp;
	int		cpt1;
	int		cpt2;

	len = ft_len(*dst) + ft_len(src) + 1;
	tmp = malloc(len);
	cpt1 = -1;
	cpt2 = -1;
	while ((*dst)[++cpt1])
		tmp[cpt1] = (*dst)[cpt1];
	while (src[++cpt2])
	{
		tmp[cpt1] = src[cpt2];
		cpt1++;
	}
	tmp[cpt1] = '\0';
	free(*dst);
	*dst = tmp;
}

int	ft_parse_buf(char **dst, char *src)
{
	int		cpt;
	char	tmp[50 + 1];

	cpt = 0;
	while (src[cpt] && (src[cpt] != '\n'))
	{
		tmp[cpt] = src[cpt];
		cpt++;
	}
	tmp[cpt] = '\0';
	ft_strcat(dst, tmp);
	if (src[cpt] == '\n')
	{
		ft_strcpy(src, src + cpt + 1);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[50 + 1];
	int			ret;

	*line = malloc(1);
	(*line)[0] = '\0';
	if (buffer[0] != '\0')
		if (ft_parse_buf(line, buffer) == 1)
			return (1);
	ret = read(fd, buffer, 50);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (ft_parse_buf(line, buffer) == 1)
			return (1);
		ret = read(fd, buffer, 50);
	}
	if (ret == -1)
	{
		free(*line);
		*line = 0;
		return (-1);
	}
	buffer[0] = '\0';
	return (0);
}
