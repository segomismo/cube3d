/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:25:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/11/25 19:28:43 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    readmap(t_data *data)
{
    int i;

    while(get_next_line(data->fd, &data->line))
    {
        i = 0;
        while (data->line[i++] == ' ')
        if(data->line[i] == "R")
            ft_r(data);
        else if(data->line[i] == "N")
            ft_n(data);
        else if(data->line[i] == "S")//deriva a dos (SO y S)
            ft_s(data);
        else if(data->line[i] == "W")
            ft_w(data);
        else if(data->line[i] == "E")
            ft_e(data);
        else if(data->line[i] == "F")
            ft_f(data);
        else if(data->line[i] == "C")
            ft_c(data);
        else if(data->line[i]) == "1")
            ft_map(data);
        else
            return(-1);
    }
}
//no esta bien, falta saber si despues del espacio se acabase
void    ft_init(t_data *data)
{
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