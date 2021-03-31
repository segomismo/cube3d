/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:32:57 by mbahstou          #+#    #+#             */
/*   Updated: 2021/03/31 04:21:49 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void 	position(t_data *data, int i, int z) // (R) este es nuevo, es para no tener que recorrerlo después
{
	data->player->posx = i;
    data->player->posy = data->contj;
	printf("hola?\n");
	if (data->copy[i][data->contj] == 'N')
        data->player->dir = 'N';
    if (data->copy[i][data->contj] == 'S')
        data->player->dir = 'S';
    if (data->copy[i][data->contj] == 'E')
        data->player->dir = 'E';
    if (data->copy[i][data->contj] == 'W')
        data->player->dir = 'W';
    data->map[z] = '0';
	//(R) Meter aqui lo de de new_rows y new_cols

}

void	map_to_matrix(t_data *data) //(R) he modificado que sea una matriz tipo int, por lo que hay que hacer un itoa
{
	int i;
	int z;


	data->cpy_rows = (data->rows + 2);
	data->cpy_cols = (data->cols + 2);
	i = 0;
	z = 0;
	printf("mira a ver si llego aqui 3 y medio \n");
	while (i < data->rows)
	{
		data->contj = 0;
		printf("mira a ver si llego aqui 3 y medio \n");
		while (data->contj < data->cols)
		{
			printf("mira a ver si llego aqui 3 cuartos \n");
			if (data->map[z] == '2') // (R) he creado esto para saber cual es el numero de sprites
				data->n_sprites++;
				printf("mira a ver si llego aqui 3 y medio \n");
			if (data->copy[i][data->contj] == 'N' || data->copy[i][data->contj] == 'S'
            || data->copy[i][data->contj] == 'E' || data->copy[i][data->contj] == 'W')
				position(data, i, z);
				printf("mira a ver si llego aqui 4 \n");
			data->matrix_map[i][data->contj] = ft_atoi(&data->map[z]);// (R) modificado lo del itoa aquí
			data->contj++;
			z++;
		}
		i++;
	}
	printf("hola");
}

//¿qué pasa con los espacios cuando se pasa a int?




void	mem_map (t_data *data)// (R) he modificado que si la columna maxima es un espacio, no se guarde
//(R) tambien he modificado que no se cree un inte rows o cols, si no que se guarde directamente ahí
{
	int i;

	i = 0;
	data->rows = i+1;
	while (data->map[i] != '\0')
	{
		data->contj = 0;
		while (data->map[i] != '\n' && data->map[i+1] != '\0')
		{
			i++;
			data->contj++;
		printf("cuantas veces entro aqui, y j vale: %d \n", data->contj);
		}
		printf("a esto vale j: %d \n", data->contj);
		printf("a esto vale cols: %d \n", data->cols);
		if (data->contj > data->cols)
			data->cols = data->contj;
			printf("b esto vale j: %d \n", data->contj);
			printf("b esto vale rows: %d \n", data->rows);
		if (data->map[i] == '\n')
			data->rows++;
		i++;
		printf("b2 esto vale j: %d \n", data->cols);
		printf("b2 esto vale rows: %d \n", data->rows);
	}
	printf("c esto vale j: %d \n", data->contj);
	printf("c esto vale cols: %d \n", data->cols);
	printf("c esto vale rows: %d \n", data->rows);
	i = 0;
	if (!(data->matrix_map = (int**)malloc( data->rows * sizeof(int*))))
		printf("fail allocating memory");
			printf("mira a ver si llego aqui 2\n");
	while (i < data->rows)
	{
		if (!(data->matrix_map[i] = (int*)malloc(data->cols * sizeof(int))))
			printf("fail allocating memory");
		i++;

	}
		printf("mira a ver si llego aqui 3 \n");
	map_to_matrix(data);
//	map_errors(data);
	printf("mira a ver si llego aqui 5 \n");
}

void	map_read(t_data *data)
{
	data->map = ft_strjoin(data->line, "\n");
	while (get_next_line(data->fd, &data->line))
	{
		data->map = ft_strjoin(data->map, ft_strjoin(data->line, "\n"));
	}
	data->map = ft_strjoin(data->map, data->line);
	mem_map(data);
		printf("mira a ver si llego aqui 4 \n");
}