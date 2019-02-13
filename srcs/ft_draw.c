/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 06:19:33 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:09:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

int				ft_max_room(t_room *room)
{
	int	max;
	int	x;
	int	y;

	max = 0;
	while (room != NULL)
	{
		x = abs(room->x);
		y = abs(room->y);
		x = x * (x > y) + y * (x <= y);
		max = max * (max >= x) + x * (max < x);
		room = room->next;
	}
	return (max);
}

int				ft_draw(t_data *data)
{
	float	scale;
	int		max;
	char	*step;

	clearwin(data);
	max = ft_max_room(data->data->p->start);
	scale = ((WIN_W * 0.81) / (max));
	ft_draw_lines(data, data->data->p->start, scale, 0x00ff00);
	ft_draw_ways(data, data->data->ways, scale, 0x0000ff);
	ft_draw_room(data, data->data->p->start, scale, 0xff0000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	ft_ants_anim(data, scale);
	step = ft_itoa(data->data->step);
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W / 2 - 50, 5, 0, "step = ");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W / 2 + 15, 5, 0, step);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 5, 0, "space step++");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 25, 0, "ctrl step = 0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 45, 0, "esc to exit");
	free(step);
	return (1);
}
