/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:32:57 by mbahstou          #+#    #+#             */
/*   Updated: 2021/05/13 13:14:00 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	playerlocalization(t_data *data)
{
		data->posx = data->conti;
		data->posy = data->contj;
		if(data->dir != 'N' && data->dir != 'S' && data->dir != 'E' && data->dir != 'W')
		{
			data->dir = data->map[data->contk];
			data->matrix_map[data->conti][data->contj] = 0;
		}
		else
		{
			printf("ERROR: más de una posición de jugador \n");
			exit(-1);
		}
}

void	mapcomprovations(t_data *data)
{
	if (data->map[data->contk] == '2')
		data->n_sprites++;
	if (data->map[data->contk] == 'N' || data->map[data->contk] == 'S'
    || data->map[data->contk] == 'E' || data->map[data->contk] == 'W')
		playerlocalization(data);
	else if (data->map[data->contk] == 32)
		data->matrix_map[data->conti][data->contj] = 0;
	else if (data->map[data->contk] >= '0' && data->map[data->contk] < '3')
		data->matrix_map[data->conti][data->contj] = (data->map[data->contk] - '0');
	else
	{
		printf("ERROR: mapa inválido. Caracter extraño: ->%c<- en %d y %d\n", data->map[data->contk], data->conti, data->contj);
		exit(-1);
	}
}

void	jumpline(t_data *data)
{
	data->contj++;
	data->contk++;
	if (data->map[data->contk] == '\n')
	{
		while(data->map[data->contk] == '\n')
			data->contk++;
		while(data->contj < data->cols && data->map[data->contk] != '\0')
		{
			data->matrix_map[data->conti][data->contj] = 0;
			data->contj++;
		}
	}
}

void	map_to_matrix(t_data *data)
{
	data->conti = 0;
	data->contk = 0;
	while (data->conti < data->rows && data->map[data->contk] != '\0')
	{
		data->contj = 0;
		while (data->contj < data->cols && data->map[data->contk] != '\0')
		{
			mapcomprovations(data);
			jumpline(data);
		}
		data->conti++;
	}
}


void	imprimir_mapa(t_data *data) // esto para eliminar
{
	data->conti = 0;
	data->contj = 0;
	while(data->conti < data->rows)
	{
		while(data->contj < data->cols)
		{
			printf("%d", data->matrix_map[data->conti][data->contj]);
			data->contj++;
		}
		printf("\n");
		data->contj = 0;
		data->conti++;
	}
}
void	mem_map_while(t_data *data)
{
	data->contj = 0;
	while (data->map[data->conti] != '\n' && data->map[data->conti] != '\0')
	{
		data->conti++;
		data->contj++;
	}
	if (data->contj > data->cols)
		data->cols = data->contj;
	if (data->map[data->conti] == '\n' && data->map[data->conti - 1] != '\n')
		data->rows++;
	data->conti++;

}

void	mem_map (t_data *data)
{
	data->conti = 0;
	data->rows = 1;
	data->cols = 0;
	while (data->map[data->conti] != '\0')
		mem_map_while(data);
	data->conti = 0;
	data->matrix_map = (int**)malloc((data->rows) * sizeof(int*));
	while (data->conti < (data->rows))
	{
		data->matrix_map[data->conti] = (int*)malloc((data->cols) * sizeof(int));
		data->conti++;
	}
	map_to_matrix(data);
	//imprimir_mapa(data); //esto para eliminar
	data->spritex = (int*)malloc(data->n_sprites * sizeof(int));
	data->spritey = (int*)malloc(data->n_sprites * sizeof(int));
	map_errors(data);
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
	printf("MAPA VÁLIDO\n--> FIN <-- \n");
}