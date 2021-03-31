/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:37:06 by mbahstou          #+#    #+#             */
/*   Updated: 2021/03/31 03:01:30 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	resolution(t_data *data)
{
	int i;

	i = 2;
	while (data->line[i] != '\0')
	{
		if (data->resx == 0)
		{
			data->resx = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else if (data->resy == 0)
		{
			data->resy = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else
			break ;
	}
}

int		c_color(t_data *data)
{
	int i;

	i = 2;
	if (color_errors(data) == 1)
		return (1);
	while (data->line[i] != '\0')
	{
		data->ceiling->r = ft_atoi(&data->line[i]);
		while (data->line[i] != ',')
			i++;
		data->ceiling->g = ft_atoi(&data->line[i + 1]);
		i++;
		while (data->line[i] != ',')
			i++;
		data->ceiling->b = ft_atoi(&data->line[i + 1]);
		break ;
	}
	return (0);
}

int		f_color(t_data *data)
{
	int i;

	i = 2;

	if (color_errors(data) == 1)
		return (1);
	while (data->line[i] != '\0')
	{
		data->floor->r = ft_atoi(&data->line[i]);
		while (data->line[i] != ',')
			i++;
		data->floor->g = ft_atoi(&data->line[i + 1]);
		i++;
		while (data->line[i] != ',')
			i++;
		data->floor->b = ft_atoi(&data->line[i + 1]);
		break ;
	}
	return (0);
}

void	t_paths(t_data *data)
{
	int i;

	i = 0;
	if (data->line[i] == 'N' && data->line[i + 1] == 'O'
		&& data->line[i + 2] == ' ')
		data->pat_no = ft_strdup(&data->line[i + 3]);
	else if (data->line[i] == 'S' && data->line[i + 1] == 'O'
		&& data->line[i + 2] == ' ')
		data->pat_so = ft_strdup(&data->line[i + 3]);
	else if (data->line[i] == 'W' && data->line[i + 1] == 'E'
		&& data->line[i + 2] == ' ')
		data->pat_we = ft_strdup(&data->line[i + 3]);
	else if (data->line[i] == 'E' && data->line[i + 1] == 'A'
		&& data->line[i + 2] == ' ')
		data->pat_ea = ft_strdup(&data->line[i + 3]);
	else if (data->line[i] == 'S' && data->line[i + 1] == ' ')
		data->pat_s = ft_strdup(&data->line[i + 2]);
}

int		description_read(t_data *data)
{
	int i;

	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		if (data->line[i] == 'R' && data->line[i + 1] == ' ')
			resolution(data);
		else if (data->line[i] == 'C' && data->line[i + 1 == ' '])
		{
			if (c_color(data) == 1)
				return (1);
		}
		else if (data->line[i] == 'F' && data->line[i + 1 == ' '])
		{
			if (f_color(data) == 1)
				return (1);
		}
		t_paths(data);
		if ((data->line[i] >= 48 && data->line[i] <= 49) || data->line[i] == ' ')
			map_read(data);
	}
	return (0);
}
