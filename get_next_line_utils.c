/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:19:11 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/08 15:30:24 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*c;
	unsigned int	index;

	index = 0;
	c = (unsigned char *)s;
	while (index < n)
	{
		c[index] = '\0';
		index++;
	}
}

int		ft_contains_eol(char *s, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < BUFFER_SIZE - n)
	{
		if (s[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
