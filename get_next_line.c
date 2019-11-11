/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:18:50 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/11 14:15:22 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	ft_bzero(void *s, unsigned int n)
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

static	int	ft_contains_eol(char *s, unsigned int n)
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

static char	*ft_strjoin_gnl(char *s1, char *s2, unsigned int n)
{
	char			*joined;
	unsigned int	index;
	unsigned int	len_s1;
	unsigned int	len_s2;

	index = 0;
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (len_s2 < BUFFER_SIZE - n)
		len_s2++;
	if (!(joined = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (*s1 && *s1 != '\n')
		joined[index++] = *s1++;
	while (index < len_s1 + len_s2 && *s2 != '\n')
		joined[index++] = *s2++;
	joined[index] = 0;
	return (joined);
}

static char	*ft_strdup_gnl(char *buffer, unsigned int n)
{
	char			*allocated;
	unsigned int	index;
	unsigned int	len;

	index = 0;
	len = 0;
	while (len < BUFFER_SIZE - n && buffer[len] != '\n')
		len++;
	if (!(allocated = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (index < len)
	{
		allocated[index] = buffer[index];
		index++;
	}
	allocated[index] = 0;
	return (allocated);
}

static int	ft_fill_line(char *buffer, unsigned int *index, int fd, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strdup_gnl(&buffer[*index], *index)))
		return (-1);
	free(tmp);
	while (ft_contains_eol(&buffer[*index], *index) == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		*index = 0;
		if (!(read(fd, buffer, BUFFER_SIZE)))
			return (0);
		tmp = *line;
		*line = ft_strjoin_gnl(*line, buffer, *index);
		free(tmp);
	}
	while (*index < BUFFER_SIZE && buffer[*index] != '\n')
		(*index)++;
	if (*index < BUFFER_SIZE && buffer[*index] == '\n')
		(*index)++;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char			buffer[BUFFER_SIZE];
	static unsigned int	index = 0;

	if (!BUFFER_SIZE)
		return (0);
	*line = ft_strdup_gnl("", BUFFER_SIZE - 1);
	if (index == BUFFER_SIZE && !(index = 0))
		ft_bzero(buffer, BUFFER_SIZE);
	if (index < BUFFER_SIZE && buffer[index])
		return (ft_fill_line(buffer, &index, fd, line));
	if (read(fd, buffer, BUFFER_SIZE) < 0)
		return (-1);
	else
		return (ft_fill_line(buffer, &index, fd, line));
}

int			main(int ac, char **av)
{
	char	*line;
	int		index;
	int		fd;

	index = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		index++;
		printf("line %d : %s\n", index, line);
	}
}
