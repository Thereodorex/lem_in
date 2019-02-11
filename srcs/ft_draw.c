/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 06:19:33 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 21:37:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

int				ft_close(t_data *data)
{
	exit(0);
	return (0);
}

int				key_release(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key == 49)
		ft_draw(data);
	else if (key == 256)
	{
		data->data->step = -1;
		ft_draw(data);
	}
	return (1);
}

void			ft_draw_px(t_data *data, int x, int y, int color)
{
	float z;

	if (data->img.size_l <= 100)
		return ;
	x = (int)(WIN_W / 2 + x);
	y = (int)(WIN_H / 2 - y - 1);
	z = x + (y * WIN_W);
	if (z >= 0 && z < WIN_S &&
		x >= 0 && x <= WIN_W &&
		y >= 0)
		data->img.data[y * WIN_W + x] = color;
}

void			ft_draw_square(t_data *data, int *pos, int rad, int color)
{
	int	dx;
	int	dy;

	dx = pos[0] - rad - 1;
	while (++dx < (pos[0] + rad))
	{
		dy = pos[1] - rad - 1;
		while (++dy < (pos[1] + rad))
		{
			ft_draw_px(data, dx, dy, color);
		}
	}
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
		data->img.data[index] = 0xffffff;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
}

void		line_fast(t_data *data, int *p1, int *p2, int color)
{
	int i;
	int x[2];
	int p[2];

	x[0] = abs((int)(p2[1] - p1[1])) >> 1;
	x[1] = abs((int)(p2[0] - p1[0])) >> 1;
	ft_draw_px(data, (p[0] = p1[0]),
				(p[1] = p1[1]), color);
	if (((i = -1) == -1) && abs((int)(p2[0] - p1[0])) >=
		abs((int)(p2[1] - p1[1])))
		while (++i < abs((int)(p2[0] - p1[0])))
		{
			BLOCK_2(x[1], abs((int)(p2[0] - p1[0])), p[1],
			SGN(p2[1] - p1[1]), abs((int)(p2[1] - p1[1])));
			ft_draw_px(data, (p[0] += SGN(p2[0] - p1[0])), p[1], color);
		}
	else
		while (++i < abs((int)(p2[1] - p1[1])))
		{
			BLOCK_2(x[0], abs((int)(p2[1] - p1[1])), p[0],
			SGN(p2[0] - p1[0]), abs((int)(p2[0] - p1[0])));
			ft_draw_px(data, p[0], (p[1] += SGN(p2[1] - p1[1])), color);
		}
}

void			ft_draw_lines(t_data *data, t_room *room, float scale, int color)
{
	int		index;
	int		p_start[2];
	int		p_fin[2];

	while (room != NULL)
	{
		index = -1;
		p_start[0] = room->x * scale;
		p_start[1] = room->y * scale;
		while (++index < room->size)
		{
			p_fin[0] = room->links[index]->x * scale;
			p_fin[1] = room->links[index]->y * scale;
			line_fast(data, p_start, p_fin, color);
		}
		room = room->next;
	}
}

void			ft_draw_way(t_data *data, t_way *way, float scale, int color)
{
	int		p_start[2];

	while (way != NULL)
	{
		p_start[0] = way->room->x * scale;
		p_start[1] = way->room->y * scale;
		if (way->room == data->data->p->start)
			ft_draw_square(data, p_start, 12, 0xffff00);
		else if (way->room == data->data->p->end)
			ft_draw_square(data, p_start, 12, 0x00ffff);
		else
			ft_draw_square(data, p_start, 12, color);
		way = way->next;
	}
}

void			ft_draw_room(t_data *data, t_room *room, float scale, int color)
{
	int		p_start[2];

	while (room != NULL)
	{
		p_start[0] = room->x * scale;
		p_start[1] = room->y * scale;
		ft_draw_square(data, p_start, 10, 0xff0000);
		room = room->next;
	}
}

void			ft_draw_ant(t_data *data, t_room *room, float scale, int color)
{
	int		p_start[2];
	char	*str;

	while (room != NULL)
	{
		str = get_ant(data->data->way, way_len(data->data->way), data->data->step, data->data->ants, room);
		if (str != NULL)
		{
			p_start[0] = WIN_W / 2 + (room->x * scale) - 5 * ft_strlen(str);
			p_start[1] = WIN_H / 2 - (room->y * scale) - 10;
			ft_printf("%s %s ", room->name, str);
			mlx_string_put(data->mlx_ptr, data->mlx_win, p_start[0], p_start[1], color, str);
			free(str);
		}
		room = room->next;
	}
	ft_putchar('\n');
}

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

	data->data->step++;
	max = ft_max_room(data->data->start);
	scale = ((WIN_W * 0.9) / (max * 2));
	ft_printf("scale=%f max=%d\n", scale, max);
	clearwin(data);
	ft_draw_lines(data, data->data->start, scale, 0x00ff00);
	ft_draw_way(data, data->data->way, scale, 0x0000ff);
	ft_draw_room(data, data->data->start, scale, 0xff0000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	ft_draw_ant(data, data->data->start, scale, 0);
	return (1);
}
