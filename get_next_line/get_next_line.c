/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/11 11:11:10 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// headers para tirar
#include <stdio.h>
#include <fcntl.h>

/*
return: > 0  numero de bytes lidos
		= 0  fim do ficheiro
	    < 0  erro na leitura
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

char *get_line(int fd)
{
	int status;
	char c;
	
	status = get_char(fd, &c);
	printf("%c", c);
	while (status > 0 && c != '\n')
	{
		status = get_char(fd, &c); 
		printf("%c", c);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int buff;
	char *str;

	if (fd < 0)
		return (0);
	str = get_line(fd);
	return (str); 
}
