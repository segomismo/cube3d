/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:24:17 by rufranci          #+#    #+#             */
/*   Updated: 2020/11/25 18:59:32 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct  s_data
{
    int     switchr;
    int     switchno;
    int     switchso;
    int     switchwe;
    int     switchea;
    int     switchs;
    int     switchf;
    int     switchc;
    int     x;
    int    fd;
    char    *line;
}               t_data;

int		get_next_line(int fd, char **line);
int		ft_finder(char **p, char **line);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif