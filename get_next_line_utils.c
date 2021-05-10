/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:51:19 by mbahstou          #+#    #+#             */
/*   Updated: 2021/01/05 11:39:58 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char    *ft_strdup(const char *s1)
{
        char	*ptr;
        int		i;

        i = 0;
        while (s1[i])
                i++;
        if (!(ptr = malloc(sizeof(char) * i + 1)))
                return (0);
        i = 0;
        while (s1[i])
        {
                ptr[i] = s1[i];
                i++;
        }
        ptr[i] = '\0';
        return (ptr);
}

char    *ft_strchr(const char *s, int c)
{
        int             i;
        char    *ptr;

        i = 0;
        ptr = (char *)s;
        while (ptr[i])
        {
                if (ptr[i] == (char)c)
                {
                        return (ptr + i);
                }
                i++;
        }
        if (c == '\0')
                return (ptr + i);
        return (0);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
        unsigned int    i;
        char                    *p;
        unsigned int    l;

        if (s == 0)
                return (0);
        if (start > len)
                return (ft_strdup(""));
        l = ft_strlen(s + start);
        if (l < len)
                len = l;
        if (!(p = malloc((len + 1) * sizeof(char))))
                return (0);
        i = 0;
        while (i < len)
        {
                p[i] = s[i + start];
                i++;
        }
        p[i] = '\0';
        return (p);
}

char    *ft_strjoin(char *s1, char const *s2)
{
        int             i;
        int             j;
        char    *p;

        if (s1 == 0 || s2 == 0)
                return (0);
        if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char))))
                return (0);
        i = 0;
        while (s1[i] != '\0')
        {
                p[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2[j] != '\0')
        {
                p[i++] = s2[j];
                j++;
        }
        p[i] = '\0';
		free(s1);
        return (p);
}

size_t          ft_strlen(const char *s)
{
        unsigned int i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*a;

	i = 0;
	a = s;
	while (i < n && a[i])
	{
		a[i] = '\0';
		i++;
	}
}
