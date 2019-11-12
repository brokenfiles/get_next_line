/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:17:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/11 13:28:51 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define SUCCESS_CODE 1
# define EOF_CODE 0
# define ERROR_CODE -1
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, unsigned int n);
int		ft_contains_eol(char *s, unsigned int n);
char	*ft_strjoin_gnl(char *s1, char *s2, unsigned int n);
char	*ft_strdup_gnl(char *buffer, unsigned int n);
int		ft_fill_line(char *buffer, unsigned int *index, int fd, char **line);
#endif
