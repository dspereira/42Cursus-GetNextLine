/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/12 17:12:01 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 4

/*
return: > 0  number of bytes read
		= 0  end of file
	    < 0  error
*/
int get_line(int fd, char **str)
{
	char *s;
	int status;
	int index;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (0);
	status = 1;
	index = -1;
	while(status > 0 && index < 0)
	{
		status = read(fd, s, BUFFER_SIZE);
		index = get_char(s, '\n');
		printf("\nstring: |%s|", s);
	}

	printf("\n index: %i\n status: %i\n", index, status);
	
	*str = s;
	return (status);
}

char *str_concat(char *dst, char *src, int n)
{
	
} 

void set_storage()
{

}

void get_storage()
{
	
}

char	*get_next_line(int fd)
{
	char *str;

	if (fd < 0)
		return (0);
	get_line(fd, &str);
	return (str); 
}
