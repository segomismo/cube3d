/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:37:06 by mbahstou          #+#    #+#             */
/*   Updated: 2021/05/11 12:36:04 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	color_errors(int flocelr, int flocelg, int flocelb, int i, t_data *data)
{
	if (flocelr != -1 || flocelg != -1 || flocelb != -1)
		ft_errors (4, data);
	while (data->line[i] != '\0')
	{
		if (!((data->line[i] > 47 && data->line[i] < 58)
		|| data->line[i] == ',' || data->line[i] == ' '))
			ft_errors (4, data);
		i++;
	}
}

void	resolution(t_data *data)
{
	data->conti = 2;
	color_errors(data->resx, data->resy, -1, data->conti, data);
	while (data->line[data->conti] == ' ')
		data->conti++;
	data->resx = ft_atoi(&data->line[data->conti]);
	while (data->line[data->conti] > 47 && data->line[data->conti] < 58)
		data->conti++;
	while (data->line[data->conti] == ' ')
		data->conti++;
	data->resy = ft_atoi(&data->line[data->conti]);
	while (data->line[data->conti] > 47 && data->line[data->conti] < 58)
		data->conti++;
	if (data->line[data->conti] != '\0')
		ft_errors (4, data);
}

void		c_color(t_data *data)
{
	data->conti = 2;
	color_errors(data->ceilingr, data->ceilingg, data->ceilingb, data->conti, data);
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
		ft_errors (4, data);
}

void		f_color(t_data *data)
{
	data->conti = 2;
	color_errors(data->floorg, data->floorg, data->floorb, data->conti, data);
	data->floorr = ft_atoi(&data->line[data->conti]);
	while (data->line[data->conti] != ',')
		data->conti++;
	data->floorg = ft_atoi(&data->line[data->conti + 1]);
	data->conti++;
	while (data->line[data->conti] != ',')
		data->conti++;
	data->floorb = ft_atoi(&data->line[data->conti + 1]);
}

char *tex_adress(char *ident, int i, int a, t_data *data)
{
	i = a;
	if (!ident)
	{
		while(data->line[i] == ' ')
			i++;
		return (ft_strdup(&data->line[i]));
	}
	else
	{
		ft_errors (4, data);
		return(0);
	}
}

void	t_paths(t_data *data)
{
	if (data->line[0] == 'N' && data->line[1] == 'O'
		&& data->line[2] == ' ')
		data->pat_no = (tex_adress(data->pat_no, data->conti, 3, data));
	else if (data->line[0] == 'S' && data->line[1] == 'O'
		&& data->line[2] == ' ')
		data->pat_so = (tex_adress(data->pat_so, data->conti, 3, data));
	else if (data->line[0] == 'W' && data->line[1] == 'E'
		&& data->line[2] == ' ')
		data->pat_we = (tex_adress(data->pat_we, data->conti, 3, data));
	else if (data->line[0] == 'E' && data->line[1] == 'A'
		&& data->line[2] == ' ')
		data->pat_ea = (tex_adress(data->pat_ea, data->conti, 3, data));
	else if (data->line[0] == 'S' && data->line[1] == ' ')
		data->pat_s = (tex_adress(data->pat_s, data->conti, 2, data));
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
				ft_errors (4, data);
			else
				data->ideind = 0;
		}
	}
}
