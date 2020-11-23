/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:59:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/01/13 19:48:26 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			fill_line(char **s, char **line)
{
	int		i;
	char	*aux;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		aux = ft_strdup(&(*s)[i + 1]);
		free(*s);
		*s = aux;
	}
	else
	{
		*line = ft_substr(*s, 0, i);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int			checkline(char **s, char **line, int control, int fd)
{
	if (control < 0)
		return (-1);
	else if ((control == 0 && s[fd] == NULL) || s[fd][0] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	return (fill_line(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	int			control;
	static char	*s[4096];
	char		aux[BUFFER_SIZE + 1];
	char		*aux2;

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	while ((control = read(fd, aux, BUFFER_SIZE)) > 0)
	{
		aux[control] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(aux);
		else
		{
			aux2 = ft_strjoin(s[fd], aux);
			free(s[fd]);
			s[fd] = aux2;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (checkline(s, line, control, fd));
}
