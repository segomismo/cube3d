/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:54:05 by mbahstou           #+#    #+#             */
/*   Updated: 2021/01/25 12:54:06 by mbahstou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*void checker2(t_data *data)
{
    if(data->copy[0][0] == 3)
        exit(-1);
}

void    checker (t_data *data, int i, int j)
{∫
    data->copy[i][j] = 3;
    if(data->copy[i + 1][j] == 0 || data->copy[i][j + 1] == 2)
        checker(data, i + 1, j);
    if(data->copy[i][j + 1] == 0 || data->copy[i][j + 1] == 2)
        checker(data , i, j + 1);
    if(data->copy[i - 1][j] == 0 || data->copy[i - 1][j] == 2)
        checker (data, i - 1, j);
    if(data->copy[i][j - 1] == 0 || data->copy[i][j - 1] == 2)
        checker (data, i, j - 1);
}
*/
//comprueba si el mapa es valido ###crear funcion para gestionar los returns###
/*
void check_map (t_data *data, int i, int j)
{
    i = data->player->posx;
    j = data->player->posy;
    *checker (data, i , j);
    checker2 (data);
}
*/ 

//(R) he borrado finder, ya estaba hecho anteriormente
void fill (t_data *data, int i, int j)
{
    i = -1;
    while (++i < data->cpy_cols)
    {
        data->copy[i][0] = 0;
        data->copy[i][data->cpy_cols] = 0;
    }
    i = -1;
    while (++i < data->cpy_rows)
    {
        data->copy[0][i] = 0;
        data->copy[data->cpy_rows][i] = 0;
    }
//    check_map(data, i, j);
}


//copia el mapa para hacer en la copia las comprobaciones
/*
void map_errors (t_data *data)
{
    int i;
    int j;

    i = 0;
    if (!(data->copy = (int**)malloc( data->cpy_rows * sizeof(int*))))
		printf("fail allocating memory");
	while (i < data->rows)
	{
		if (!(data->copy[i] = (int*)malloc(data->cpy_cols * sizeof(int))))
			printf("fail allocating memory");
		i++;
	}
    i = 1;
    while (i < data->cpy_rows)
	{
		j = 1;
		while (j < data->cpy_cols)
		{
			data->copy[i][j] = data->matrix_map[i][j];
			j++;
		}
		i++;
	}
    fill(data, i, j);
}
*/