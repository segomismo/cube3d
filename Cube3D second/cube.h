/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:42:13 by mbahstou          #+#    #+#             */
/*   Updated: 2021/03/31 03:13:37 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
//# include "./minilibx-linux/mlx.h"

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_play
{
	int		posx;
	int		posy;
	char	dir;
}				t_play;


//poner en la estructura tres contadores para luego no tener que crearlos mas tarde
typedef struct	s_data
{
	int		contj;
	int		cols;
	int		rows;
	int		cpy_cols;
	int		cpy_rows;
	char 	*line;
	int 	fd;
	int		resx;
	int		resy;
	char	*pat_no;
	char	*pat_so;
	char	*pat_ea;
	char	*pat_we;
	char	*pat_s;
	char	*map;
	int		**matrix_map;// (R) he modificado que esto sea int
	int		**copy;
	int		n_sprites; // (R) he creado esto para saber cual es el numero de sprites para guardar luego su posicion
	t_color	*ceiling;
	t_color	*floor;
	t_play	*player;
}				t_data;

int		description_read(t_data *data);
void	ft_init(t_data *data);
void	resolution(t_data *data);
int		c_color(t_data *data);
int		f_color(t_data *data);
int		color_errors(t_data *data);
void	t_paths(t_data *data);
void	map_read(t_data *data);
void	map_to_matrix(t_data *data);
void 	position(t_data *data, int i, int z);
void 	fill (t_data *data, int i, int j);
void    checker (t_data *data, int i, int j);
void 	checker2(t_data *data);
void 	check_map (t_data *data, int i, int j);
void	mem_map (t_data *data);
void	copy_map (t_data *data, int rows, int cols);
void	p_finder (t_data *data, int rows);
void	p_position (t_data *data, int i, int j);
void 	check_map (t_data *data, int i, int j);
int		ft_atoi(char *str);
void 	map_errors (t_data *data);
/*
**              				GET NEXT LINE
*/
int		get_next_line(int fd, char **line);
int		ft_finder(char **p, char **line);
char	*ft_remove(char *p, int len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);


/*
**									LIBFT
*/

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif