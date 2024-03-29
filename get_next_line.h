/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:17:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/15 13:38:56 by llaurent         ###   ########.fr       */
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

int				ft_strlen(char *str);
char			*ft_strnew(int size);
int				get_next_line(int fd, char **line);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				contains_char(char *s, char c);
int				free_string_and_return(char **str, int return_value);
#endif
