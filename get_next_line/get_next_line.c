/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/11 11:39:01 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// headers para tirar
#include <stdio.h>

/*
return: > 0  number of bytes read
		= 0  end of file
	    < 0  error
*/
int get_char(int fd, char *c)
{
	char str[2];
	int status;
	
	status = read(fd, str, 1);
	if (status > 0)
		*c = str[0];
	return (status);
}

char *get_line(int fd, int buff_size)
{
	int status;
	char c;
	char *str;
	int i;
	
	str = malloc(buff_size * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (get_char(fd, &c) > 0 && c != '\n' && i < buff_size)
	{
		str[i] = c;
		i++;
	}
	if (c == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int buff;
	char *str;

	buff = 100;
	if (fd < 0)
		return (0);
	str = get_line(fd, buff);
	return (str); 
}
