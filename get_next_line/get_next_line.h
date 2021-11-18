/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:05:12 by diogo             #+#    #+#             */
/*   Updated: 2021/11/18 11:30:04 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
void get_line(int fd, char **line);
int read_file(int fd, char *buff);
char *line_cat(char *line, char *buff, int n);
void update_buffer(char *buff, char *src);

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int get_char(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
#endif