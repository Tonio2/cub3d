/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:59:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/29 16:31:32 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

char	*ft_strcreate(char *str)
{
	char	*ret;
	int		cpt;

	ret = malloc(ft_len(str) + 1);
	cpt = 0;
	while (str[cpt])
	{
		ret[cpt] = str[cpt];
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}

int	ft_in(char c, char *str)
{
	int	cpt;

	cpt = 0;
	while (str[cpt])
	{
		if (str[cpt] == c)
			return (1);
		cpt++;
	}
	return (0);
}

void	ft_print_map_lines(t_map_line *first_elt)
{
	while (first_elt)
	{
		printf("%s\n", first_elt->line);
		first_elt = first_elt->next;
	}
}
