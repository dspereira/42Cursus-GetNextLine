/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2021/11/15 19:26:52 by diogo            ###   ########.fr       */
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

	s = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!s)
		return (0);
	status = 1;
	index = -1;
	while(status > 0 && index < 0)
	{
		status = read(fd, s, BUFFER_SIZE);
		index = get_char(s, '\n');
		if (index < 0)
			*str = line_cat(*str, s, BUFFER_SIZE);
		else{
			*str = line_cat(*str, s, index);
			printf("\nBUFFER_SIZE: %i  index: %i", BUFFER_SIZE, index);
		}
	}
	free(s);
	return (status);
}

char *line_cat(char *s1, char *s2, int n)
{
	int i;
	int s1_len;
	char *str;

	if (!s1)
		s1_len = 0;
	else 
		s1_len = ft_strlen(s1);
	str = malloc(s1_len + n + 1 + sizeof(char));
	if (s1_len > 0)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		free(s1);
	}
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + i] = '\0';
	return (str);
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
	str = 0;
	get_line(fd, &str);
	return (str); 
}
