/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 06:19:33 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:25:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

int				ft_close(t_data *data)
{
	exit(0);
	return (0);
}

int				key_release(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	if (key == 49)
		ft_draw(data);
	return (1);
}

void			ft_draw_px(t_data *env, int x, int y, int color)
{
	float z;

	if (env->img.size_l <= 100)
		return ;
	x = (int)(x);
	y = (int)(WIN_H - y - 1);
	z = x + (y * WIN_W);
	if (z >= 0 && z < WIN_S &&
		x >= 0 && x <= WIN_W &&
		y >= 0)
		env->img.data[y * WIN_W + x] = color;
}

void			clearwin(t_data *data)
{
	int index;
	int size;

	if (data->img.size_l <= 100)
		return ;
	index = -1;
	size = WIN_W * WIN_H;
	while (++index < size)
		data->img.data[index] = 0x000000;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
}

int				ft_draw(t_data *data)
{
	clearwin(data);
	return (1);
}
