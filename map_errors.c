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

void	imprimir_mapa2(t_data *data)
{
	data->conti = 0;
	data->contj = 0;
	while(data->conti < data->cpy_rows)
	{
		while(data->contj < data->cpy_cols)
		{
			printf("%d", data->copy[data->conti][data->contj]);
			data->contj++;
		}
		printf("\n");
		data->contj = 0;
		data->conti++;
	}
}

void    checker (t_data *data, int i, int j) // AQUI CONTINUO. Tengo que poner que tiene que existir los laterales
{   
        data->copy[i][j] = 3;
       // imprimir_mapa2(data);
        data->contk = 0;
        while(data->contk < data->cols)
        {
            if (data->copy[data->cpy_rows-1][data->contk] == 3 || data->copy[data->cpy_rows-1][data->cpy_cols - 1] == 3)
            {
                printf("ERROR: Mapa abierto, es inválido\n");
                exit(-1);
            }
            data->contk++;
        }
        if((data->copy[i + 1][j] == 0 || data->copy[i + 1][j] == 2))
            checker(data, i + 1, j);
        if((data->copy[i][j + 1] == 0 || data->copy[i][j + 1] == 2))
            checker(data , i, j + 1);
        if((data->copy[i - 1][j] == 0 || data->copy[i - 1][j] == 2))
            checker (data, i - 1, j);
        if((data->copy[i][j - 1] == 0 || data->copy[i][j - 1] == 2))
            checker (data, i, j - 1);
}

void check_map (t_data *data)
{
    int i;
    int j;

    i = data->posx + 1;
    j = data->posy + 1;
    checker (data, i , j);
}

void    map_erros_secondwhile(t_data *data)
{
	data->contj = 0;
	while (data->contj < data->cols)
	{
		data->copy[data->conti+1][data->contj+1] = data->matrix_map[data->conti][data->contj];
		data->contj++;
	}
	data->conti++;
}

void    map_errors (t_data *data)
{
	data->cpy_rows = (data->rows + 2);
	data->cpy_cols = (data->cols + 2);
    data->conti = 0;
    if (!(data->copy = (int**)malloc( data->cpy_rows * sizeof(int*))))
		printf("fail allocating memory");
	while (data->conti < data->cpy_rows)
	{
		if (!(data->copy[data->conti] = (int*)malloc(data->cpy_cols * sizeof(int))))
			printf("fail allocating memory");
		data->conti++;
	}
    data->conti = 0;
    while (data->conti < data->rows)
        map_erros_secondwhile(data);
    imprimir_mapa2(data);
    printf("esto vale el x0y0->%d\n", data->copy[0][0]);
    check_map(data);
}