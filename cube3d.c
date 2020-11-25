/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:25:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/11/25 18:59:35 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    readmap(t_data *data)
{
    int i;

    while(get_next_line(data->fd, &data->line))
    {
        i = 0;
        if (data->line[i] == "R")
        

        
    }
}

void    ft_init(t_data *data)
{
    data->x = 0;
    data->switchr = 0;
    data->switchno = 0;
    data->switchso = 0;
    data->switchwe = 0;
    data->switchea = 0;
    data->switchs = 0;
    data->switchf = 0;
    data->switchc = 0;
}

int     main(int argc, char *argv)
{
    t_data  *data;
    
    data = malloc(sizeof(t_data));

    ft_init(data);

    if(argc < 2)
    {
        printf("Falta un argumentos");
        return(1);
    }

    data->fd = open(argv[1], O_RDONLY);

    if(data->fd < 0)
    {
        printf("falta el archivo");
        return(1);
    }
    readmap(data);
    return(0);
}