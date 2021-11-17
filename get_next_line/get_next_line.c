/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/17 17:07:50 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 15

char	*get_next_line(int fd)
{
	char *str;
	static char storage[BUFFER_SIZE + 1];

	if (fd < 0)
		return (0);
	str = 0;
	//get_line(fd, &str);
	//get_from_storage(storage, &str);
	get_from_file(fd, &str);


	return (str); 
}

void get_from_storage(char *storage, char **line)
{
	int storage_size;
	int new_line_index;

	storage_size = ft_strlen(storage);
	if (!storage_size)
		return ;
	new_line_index = get_char(storage, '\n');
	if (new_line_index >= 0);
		//line_cat(*line, storage, new_line_index + 1);
	else ;
		//line_cat(*line, storage, storage_size + 1);
	//update storage
}

char *line_cat(char *line, char *buff)
{
	char *new_line;
	int line_size;
	int buff_size;
	int nl_index;

	nl_index = get_char(buff, '\n');
	buff_size = ft_strlen(buff);
	line_size = 0;
	if (line)
		line_size = ft_strlen(line);
	if (nl_index >= 0)
		new_line = ft_calloc((line_size + nl_index + 2), sizeof(char));
	else if (buff_size > 0)
		new_line = ft_calloc((line_size + buff_size + 1), sizeof(char));
	if (line_size > 0)
		ft_strlcpy(new_line, line, line_size + 1);
	while (*buff != '\n' && *buff != '\0')
	{
		new_line[line_size] = *buff;
		buff++;
		line_size++;
	}
	new_line[line_size] = *buff;
	free(line);
	return (new_line);
}

void get_from_file(int fd, char **line)
{
	char *buff;
	int nl_index;
	int status;

	if (*line && get_char(*line, '\n') >= 0)
		return ;
	buff = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return ;
	nl_index = -1;
	status = 1;
	while (nl_index < 0 && status > 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		*line = line_cat(*line, buff);
		nl_index = get_char(buff, '\n');
	}
	if (nl_index >= 0 && (nl_index + 1) < ft_strlen(buff))
	{
		printf("\nupdate storage");
	}
	free(buff);
}
