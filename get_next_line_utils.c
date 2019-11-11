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

char	*ft_strdup_gnl(char const *s)
{
	int		index;
	char	*new;

	index = 0;
	while (s[index] && s[index] != '\n')
		index++;
	if (!(new = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = 0;
	while (s[index] && s[index] != '\n')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = 0;
	return (new);
}

int	get_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	static int	index;
	int			r;

	
}