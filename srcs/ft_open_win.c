/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:33:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 21:25:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void		ft_open_win(char *str, t_param *p, t_way *way, int ants)
{
	t_data	data;

	if (((data.mlx_ptr = mlx_init()) == 0) ||
		((data.mlx_win =
		mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, str)) == NULL))
		return ;
	data.data = (t_new_data *)malloc(sizeof(t_new_data));
	data.data->ants = ants;
	data.data->way = way;
	data.data->start = p->start;
	data.data->p = p;
	data.data->step = -1;
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_expose_hook(data.mlx_win, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 1L << 2, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_close, &data);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr,
		&data.img.bpp, &data.img.size_l, &data.img.endian);
	mlx_loop(data.mlx_ptr);
}
