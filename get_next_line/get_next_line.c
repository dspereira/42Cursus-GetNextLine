/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/16 15:33:49 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 20

/*
return: > 0  number of bytes read
		= 0  end of file
	    < 0  error
*/
int get_line(int fd, char **str)
{
	char *buff;
	int status;
	int index;
	static char *storage;

	storage = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (0);
	status = 1;
	index = -1;
	while(status > 0 && index < 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status > 0)
			buff[status] = '\0';
		index = get_char(buff, '\n');
		if (status > 0 && index < 0)
			*str = line_cat(*str, buff, status);
		else if (index > 0)
		{
			*str = line_cat(*str, buff, index + 1);
			storage = set_storage(storage, &buff[index + 1]);
		}
		printf("\nstorage: |%s|", storage);
			
		// passar tudo a zero para na proxima leitura do file trazer quebra de linha	
	}
	free(buff);
	return (status);
}

char *line_cat(char *line, char *buff, int n)
{
	int i;
	int line_len;
	char *new_line;

	if (!line)
		line_len = 0;
	else 
		line_len = ft_strlen(line);
	new_line = malloc(line_len + n + 1 + sizeof(char));
	if (line_len > 0)
	{
		ft_strlcpy(new_line, line, line_len + 1);
		free(line);
	}
	i = 0;
	while (i < n && buff[i] != '\0')
	{
		new_line[line_len + i] = buff[i];
		i++;
	}
	new_line[line_len + i] = '\0';
	return (new_line);
}

char *set_storage(char *storage, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		storage[i] = src[i];
		i++;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	char *str;

	if (fd < 0)
		return (0);
	str = 0;
	get_line(fd, &str);
	return (str); 
}
