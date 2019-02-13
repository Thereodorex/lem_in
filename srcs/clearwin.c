/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearwin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:02:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:02:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

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
