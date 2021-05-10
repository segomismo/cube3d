/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:14:16 by mbahstou          #+#    #+#             */
/*   Updated: 2021/01/05 11:38:57 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

char	*ft_remove(char *p, int len)
{
	char	*newstr;
	int 	i;

	i = 0;
	if(!(newstr = malloc((ft_strlen(p) - len) * sizeof(char))))
		return (0);
	while (p[len]) // es igual si uso p[len++]
		newstr[i++] = p[len++ + 1];
	free(p);
	return(newstr);
}

int	ft_finder(char **p, char **line)
{
	int i;

	i = 0;
	while ((*p)[i] && (*p)[i] != '\n')
		i++;
	if ((*p)[i] == '\n')
	{
		*line = ft_substr(*p, 0, i);
		*p = ft_remove(*p, i);
		return (1);
	}
	*line = ft_substr(*p, 0, i);
	*p = ft_remove(*p, i);
	**p = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int 		lectura;
	char		buff[BUFFER_SIZE + 1];
	static char	*p[4096];
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	while ((lectura = read (fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[lectura] = '\0';
		if(!p[fd])
			p[fd] = ft_strdup(buff);
		else
			p[fd] = ft_strjoin(p[fd], buff);
	}
	if (lectura < 0)
		return (-1);
	if (ft_strchr(p[fd], '\n') != 0)
	{
		return (ft_finder(&p[fd], line));
		/*while (p[fd][i] != '\n')
			i++;
		*line = ft_substr(p[fd], 0, i);
		p[fd] = ft_remove(p[fd], i);
		return (1);*/
	}
	else if (ft_strchr(p[fd], '\0') != 0)
	{
		return (ft_finder(&p[fd], line));
		/*while (p[fd][i] != '\0')
				i++;
			*line = ft_substr(p[fd], 0, i);
			p[fd] = ft_remove(p[fd], i);
			j = ft_strlen(p[fd]);
			p[fd][j] = 0;
		return (0);*/
	}
	return(-1);
}
