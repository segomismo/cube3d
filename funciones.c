/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:53:10 by ruben             #+#    #+#             */
/*   Updated: 2021/05/03 13:21:35 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	check_exten(char *filename)//check extension
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
    {
        printf("wrong extation, must be .cub\n");
		pre_exit(NULL, 1);//clean_exit
    }
}
