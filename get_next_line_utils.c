/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:19:11 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/15 10:32:14 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	index;

	index = 0;
	len = ft_strlen(dest);
	while (src[index] && index < nb)
		dest[len++] = src[index++];
	dest[len] = 0;
	return (dest);
}

char	*ft_strnew(int n)
{
	char	*string;
	int		index;

	if (!(string = (char *)malloc(n)))
		return (NULL);
	index = 0;
	while (index < n)
		string[index++] = 0;
	return (string);
}

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

int		free_string_and_return(char **string, int val)
{
	if (*string)
		free(*string);
	*string = NULL;
	return (val);
}
