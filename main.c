/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:37:13 by mbahstou          #+#    #+#             */
/*   Updated: 2021/05/10 15:55:57 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_init(t_data *data)
{
	data->resx = 0;
	data->resy = 0;
	data->ceilingr = -1;
	data->ceilingg = -1;
	data->ceilingb = -1;
	data->floorr = -1;
	data->floorg = -1;
	data->floorb = -1;
}

int		main(int argc, char *argv[])
{
	t_data *data;

	if (argc < 2 || argc >= 3 /*&& !ft_strcmp(argv[2], "--save")*/)
	////hacer stringcompare
	{
		printf("Arguments Error");
		return (1);
	}
	if (open(argv[1], O_RDONLY) < 0)
	{
		printf("Error while opening the file");
		return (1);
	}
	data = malloc(sizeof(t_data));
	data->fd = open(argv[1], O_RDONLY);
	ft_init(data);
	description_read(data);
	map_read(data); //tiene que pasar por filtro de si estan todos los indentificadores, y si hay mapa o no
	printf("\nResolución:\n-->x: %d<--   -->y: %d<--\n\n", data->resx, data->resy);
	printf("Direcciones:\n-->NO:%s<--  -->SO:%s<--  -->WE:%s<--  -->EA:%s<--  -->S:%s<--\n\n", data->pat_no, data->pat_so, data->pat_we, data->pat_ea, data->pat_s);
	printf("Colores:\n -->fr:%d   fg:%d   fb:%d<--  -->cr:%d   cg:%d   cb:%d<--\n\n", data->floorr, data->floorg, data->floorb, data->ceilingr, data->ceilingg, data->ceilingb);
	return (0);
}
