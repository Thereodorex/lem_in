/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:08:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 17:11:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void			ft_ants_pos(t_data *data, float scale, int index, int step)
{
	t_room	*room;
	
	room = get_room(data->data->ways,
	step, data->data->p->ants, (index / 2 + 1));
	if (data->data->step == 0)
		room = data->data->p->start;
	if (room != NULL)
	{
		data->data->pos[index] = room->x * scale;
		data->data->pos[index + 1] = room->y * scale;
	}
}

void			ft_update_position(t_data *data, int index, float d)
{
	data->data->old_pos[index] = data->data->old_pos[index] + 1 *
	((data->data->old_pos[index] < data->data->pos[index])
	- (data->data->old_pos[index] > data->data->pos[index]));
	data->data->old_pos[index + 1] = data->data->old_pos[index + 1] + d *
	((data->data->old_pos[index + 1] < data->data->pos[index + 1])
	- (data->data->old_pos[index + 1] > data->data->pos[index + 1]));
}

void			ft_on_position(t_data *data, float scale, int index)
{
	if (data->data->steps[index / 2] < data->data->step)
	{
		data->data->steps[index / 2]++;
		ft_ants_pos(data, scale, index, data->data->steps[index / 2]);
	}
	else if (data->data->step == 0)
		data->data->steps[index / 2] = -1;
}

void			ft_draw_ant(t_data *data, int index)
{
	char	*str;

	str = ft_itoa(index / 2 + 1);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W / 10 + data->data->old_pos[index] - 5 * ft_strlen(str),
	WIN_H * 9 / 10 - data->data->old_pos[index + 1] - 10, 0, str);
	free(str);
}

void			ft_ants_anim(t_data *data, float scale)
{
	int		index;
	float	dx;
	float	dy;
	float	d;

	index = 0;
	while (index < (data->data->p->ants * 2))
	{
		dx = data->data->old_pos[index] - data->data->pos[index];
		dy = data->data->old_pos[index + 1] - data->data->pos[index + 1];
		d = dy / (dx + dy * (dx ==0));
		d = d * (1 - 2 * (d < 0));
		if (data->data->old_pos[index] != data->data->pos[index] ||
			data->data->old_pos[index + 1] != data->data->pos[index + 1])
			ft_update_position(data, index, d);
		else
			ft_on_position(data, scale, index);
		ft_draw_ant(data, index);
		index += 2;
	}
}
