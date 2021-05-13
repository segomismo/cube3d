/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:23:03 by ruben             #+#    #+#             */
/*   Updated: 2021/05/12 17:31:32 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_errors (int a, t_data *data)
{
    free (data);
    if (a == 0)
    {
    	printf("Arguments Error\n");
		exit(-1);
    }
    if (a == 1)
    {
        printf("Error while opening the file");
		exit (-1);
    }
    if (a == 2)
    {
        printf("fail allocating memory");
		exit (-1);
    }
    if (a == 3)
    {
        printf("Error2: information resolution incorrect\n");
		exit(-1);
    }
    if (a == 4)
    {
        printf("Error, fail elements\n");
		exit(-1);
    }
}