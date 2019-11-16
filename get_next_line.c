/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:18:50 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/15 16:04:19 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	join_line(int fd, char **string)
{
	int		r;
	char	*s;
	char	*buffer;

	if (!(buffer = ft_strnew(BUFFER_SIZE + 1)))
		return (ERROR_CODE);
	if ((r = read(fd, buffer, BUFFER_SIZE)) <= 0)
	{
		free(buffer);
		return (r);
	}
	buffer[r] = '\0';
	if (!(s = ft_strnew(ft_strlen(*string) + (r + 1))))
		return (ERROR_CODE);
	if (*string)
	{
		s = ft_strncat(s, *string, ft_strlen(*string));
		free(*string);
	}
	*string = ft_strncat(s, buffer, r);
	free(buffer);
	if (!contains_char(*string, '\n'))
		return (join_line(fd, string));
	return (SUCCESS_CODE);
}

static int	get_only_string(char **line, char **string, int *index, int *index2)
{
	char	*tmp;
	char	*s2;
	char	*s;

	while ((*string)[*index] && (*string)[*index] != '\n')
		(*index) += -(*index - (*index + 1));
	if (!(s = ft_strnew(*index + 1)))
		return (ERROR_CODE);
	*line = ft_strncat(s, *string, *index);
	*index2 = ft_strlen(*string) - *index;
	if (!(*index2))
		return (free_string_and_return(string, EOF_CODE));
	if ((s2 = ft_strnew(*index2)))
	{
		tmp = ft_strncat(s2, *string + *index + 1, *index2 - 1);
		free(*string);
		*string = tmp;
		return (SUCCESS_CODE);
	}
	return (free_string_and_return(string, ERROR_CODE));
}

static int	get_line_from_str(char **string, char **line)
{
	int	index;
	int	index2;
	int	r;

	index = 0;
	index2 = 0;
	r = 0;
	if ((r = get_only_string(line, string, &index, &index2)) != 1)
		return (free_string_and_return(string, 0));
	return (SUCCESS_CODE);
}

int			get_next_line(int fd, char **line)
{
	static char	*string = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR_CODE);
	if (!contains_char(string, '\n'))
	{
		if (join_line(fd, &string) == ERROR_CODE)
			return (free_string_and_return(&string, ERROR_CODE));
		if (!string)
		{
			*line = ft_strnew(1);
			return (EOF_CODE);
		}
	}
	return (get_line_from_str(&string, line));
}

int			main(int ac, char **av)
{
	char	*line;
	int		index;
	int		fd;

	index = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(0, &line) == SUCCESS_CODE)
		{
			index++;
			printf("%s\n", line);
		}
		printf("%s", line);
	}
	return (0);
}