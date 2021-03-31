/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:07:11 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/09 19:09:21 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

#define KEY_W 13
#define KEY_S 1

typedef struct	s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_cub3d;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, void *param)
{
	t_cub3d *cube;

	cube = (t_cub3d *)param;
	if (key == KEY_S)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, cube->x, cube->y, 0xFFFFFF);
		cube->x++;
	}
	else if (key == KEY_W)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, cube->x, cube->y, 0xFFFFFF);
		cube->y--;
	}
	return (0);
}

int		deal_mouse(int key, int x, int y, void *param)
{
	t_cub3d *cube;

	cube = (t_cub3d *)param;
	mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, x, y, 0xdb1714);
	return (0);
}

int main ()
{
	t_cub3d *cube;

	if (!(cube = malloc (sizeof (t_cub3d))))
		return (-1);
	cube->x = 200;
	cube->y = 150;
	cube->mlx_ptr = mlx_init();
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, 1000, 1000, "first try");
	mlx_key_hook(cube->win_ptr, deal_key, (void *)cube);
	//mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, 500, 500, 0xFFFFFF);
	mlx_mouse_hook(cube->win_ptr, deal_mouse, (void *)cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
