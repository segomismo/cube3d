/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:37:06 by mbahstou          #+#    #+#             */
/*   Updated: 2021/05/10 16:05:41 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//-He solucionado el tema de los elementos y los identificadores
//-Respecto a los colores, he soluciuonado tambien que ya hubiese y los espacios, o letras, o numeros de mas.
//- El sigueinte paso es la resolucion, tanto gestiones de errores como que ya hubiese
//- También estaría bien que gestionase el tema de los errores, con códigos de dónde está y salidas del programa 

#include "cube.h"

void	color_errors(int flocelr, int flocelg, int flocelb, char *line, int i)
{
	if (flocelr != -1 || flocelg != -1 || flocelb != -1)
	{
		printf("Error, ya había colores\n");
		exit(-1);
	}
	while (line[i] != '\0')
	{
		if (!((line[i] > 47 && line[i] < 58)
		|| line[i] == ',' || line[i] == ' '))
		{
			printf("error, invalid set of colors\n");
			exit (-1);
		}
		i++;
	}
}

void	resolution(t_data *data)
{
	data->conti = 2;
	while (data->line[data->conti] != '\0')
	{
		if (data->resx == 0)
		{
			data->resx = ft_atoi(&data->line[data->conti]);
			while (data->line[data->conti] > 47 && data->line[data->conti] < 58)
				data->conti++;
		}
		else if (data->resy == 0)
		{
			data->resy = ft_atoi(&data->line[data->conti]);
			while (data->line[data->conti] > 47 && data->line[data->conti] < 58)
				data->conti++;
		}
		else
			break ;
	}
}

void		c_color(t_data *data)
{
	data->conti = 2;
	color_errors(data->ceilingr, data->ceilingg, data->ceilingb, data->line, data->conti);
	data->ceilingr = ft_atoi(&data->line[data->conti]);
	while (data->line[data->conti] != ',')
		data->conti++;
	data->ceilingg = ft_atoi(&data->line[data->conti + 1]);
	data->conti++;
	while (data->line[data->conti] != ',')
		data->conti++;
	data->ceilingb = ft_atoi(&data->line[data->conti + 1]);
	data->conti++;
	while (data->line[data->conti] == ' ')
		data->conti++;
	while (data->line[data->conti] > 47 && data->line[data->conti] < 58)
		data->conti++;
	if (data->line[data->conti] != '\0')
	{
		printf("Error2: information color incorrect\n");
		exit(-1);
	}
}

void		f_color(t_data *data)
{
	data->conti = 2;
	color_errors(data->floorg, data->floorg, data->floorb, data->line, data->conti);
	data->floorr = ft_atoi(&data->line[data->conti]);
	while (data->line[data->conti] != ',')
		data->conti++;
	data->floorg = ft_atoi(&data->line[data->conti + 1]);
	data->conti++;
	while (data->line[data->conti] != ',')
		data->conti++;
	data->floorb = ft_atoi(&data->line[data->conti + 1]);
}

char *tex_adress(char *ident, char *line, int i, int a)
{
	i = a;
	if (!ident)
	{
		while(line[i] == ' ')
			i++;
		return (ft_strdup(&line[i]));
	}
	else
	{
		printf("Error, multiple texture direcctions in some identifier\n");
		exit(-1);
	}
}

void	t_paths(t_data *data)
{
	if (data->line[0] == 'N' && data->line[1] == 'O'
		&& data->line[2] == ' ')
		data->pat_no = (tex_adress(data->pat_no, data->line, data->conti, 3));
	else if (data->line[0] == 'S' && data->line[1] == 'O'
		&& data->line[2] == ' ')
		data->pat_so = (tex_adress(data->pat_so, data->line, data->conti, 3));
	else if (data->line[0] == 'W' && data->line[1] == 'E'
		&& data->line[2] == ' ')
		data->pat_we = (tex_adress(data->pat_we, data->line, data->conti, 3));
	else if (data->line[0] == 'E' && data->line[1] == 'A'
		&& data->line[2] == ' ')
		data->pat_ea = (tex_adress(data->pat_ea, data->line, data->conti, 3));
	else if (data->line[0] == 'S' && data->line[1] == ' ')
		data->pat_s = (tex_adress(data->pat_s, data->line, data->conti, 2));
	else
		data->ideind = 1;
}

void		description_read(t_data *data)
{
	while (get_next_line(data->fd, &data->line))
	{
		if (data->line[0] == 'R' && data->line[1] == ' ')
			resolution(data);
		else if (data->line[0] == 'C' && data->line[1] == ' ')
			c_color(data);
		else if (data->line[0] == 'F' && data->line[1] == ' ')
			f_color(data);
		else if ((data->line[0] >= 48 && data->line[0] <= 49) || data->line[0] == ' ')
			break;
		else
		{
			t_paths(data);
			if (data->ideind == 1 && data->line[0] != 0 && data->line[0] != '\n')
			{
				printf("error, identificador incorrecto\n");
				exit(-1);
			}
			else
			data->ideind = 0;
		}
	}
}
