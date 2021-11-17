/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:05:12 by diogo             #+#    #+#             */
/*   Updated: 2021/11/17 17:07:08 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
int get_char(const char *s, int c);
char *line_cat(char *line, char *buff);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char *set_storage(char *storage, char *src);

void get_from_storage(char *storage, char **line);
void get_from_file(int fd, char **line);




#endif