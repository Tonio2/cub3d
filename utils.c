/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:59:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:08 by alabalet         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (-1);
		i++;
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
