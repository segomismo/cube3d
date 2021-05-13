/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:37:13 by mbahstou          #+#    #+#             */
/*   Updated: 2021/05/13 13:39:29 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - Solucionado el tema de resolucion, colores y textura
// - Solucionado el tema de errores dentro de description_read
// - Description_read completado
// - (hecho) Lo siguiente es que antes de que entre al mapa, comprobar que están texturas, colores y resolucion
// - (Hecho) Tambien hacer que la máxima resolución sea la pantalla
// - (hecho)Estaría bien hacer el makefile basado en el de Irene, con pruebas de minilibx, etc, y organizar por carpetas
// - Solucionado el tema del 0 donde el jugador
// - (HECHO) guardar los sitios de los sprites
// Organizar carpetas
// Intentar que funcione libx
// Solucionar frees del get next line
// Probar minilibx con el makefile


#include "cube.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)//funcion extra
{
	size_t	pos;

	pos = 0;
	while (s1[pos] && s2[pos] && s1[pos] == s2[pos] && pos < n)
		pos++;
	if (s1[pos] != s2[pos] && pos < n)
		return (((unsigned char)s1[pos] - (unsigned char)s2[pos]));
	return (0);
}

void	elements(t_data *data)
{
	if(!data->pat_no || !data->pat_so || !data->pat_we || !data->pat_ea || !data->pat_s
	|| data->resx == -1 || data->resy == -1 || data->ceilingr == -1 || data->ceilingg == -1
	|| data->ceilingb == -1 || data->floorr == -1 || data->floorg == -1 
	|| data->floorb == -1)
		ft_errors(4, data);
	if (data->resx > 2560 && data->save == 0)
		data->resx = 2560;
	if (data->resy > 1440 && data->save == 0)
		data->resy = 1440;
}

void	ft_init(t_data *data)
{
	data->resx = -1;
	data->resy = -1;
	data->ceilingr = -1;
	data->ceilingg = -1;
	data->ceilingb = -1;
	data->floorr = -1;
	data->floorg = -1;
	data->floorb = -1;
	data->save = 0;
}

static void	check_argc(t_data *data, int n, char *str)
{
	if (n < 2 || n > 3)
		ft_errors(0, data);
	if (n == 3 && !ft_strncmp(str, "--save", 6))
		data->save = 1;
	else if (n == 3)
		ft_errors(0, data);
}

int		main(int argc, char *argv[])
{
	t_data *data;

	data = malloc(sizeof(t_data));
	ft_init(data);
	data->fd = open(argv[1], O_RDONLY);
	check_argc(data, argc, argv[2]);
	description_read(data);
	elements(data);
	map_read(data); //tiene que pasar por filtro de si estan todos los indentificadores, y si hay mapa o no
	printf("\nResolución:\n-->x:%d<--   -->y:%d<--\n\n", data->resx, data->resy);
	printf("Direcciones:\n-->NO:%s<--  -->SO:%s<--  -->WE:%s<--  -->EA:%s<--  -->S:%s<--\n\n", data->pat_no, data->pat_so, data->pat_we, data->pat_ea, data->pat_s);
	printf("Colores:\n -->fr:%d   fg:%d   fb:%d<--  -->cr:%d   cg:%d   cb:%d<--\n\n", data->floorr, data->floorg, data->floorb, data->ceilingr, data->ceilingg, data->ceilingb);
	printf("posicion del jugador dentro de mapa: x: %d  y: %d con direccion: %c\n\n", data->posx, data->posy, data->dir);
	data->conti = -1;
	printf ("numero de sprites: %d\n", data->n_sprites);
	while (++data->conti < data->n_sprites)
	{
		printf("posición del sprite %d : eje x: %d    eje y: %d\n", data->conti, data->spritex[data->conti], data->spritey[data->conti]);
	}
	return (0);
}
