/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:24:17 by rufranci          #+#    #+#             */
/*   Updated: 2020/11/23 18:25:20 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_data
{
    char    *line
}

int		get_next_line(int fd, char **line);
int		ft_finder(char **p, char **line);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif