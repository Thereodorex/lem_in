/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrhaenys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:28:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 23:39:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRHAENYS_H
# define RRHAENYS_H

# include <mlx.h>

# define WIN_W 1300
# define WIN_H 1300
# define WIN_S (WIN_W * WIN_H)

# define SGN(x) ((x < 0) ? -1 : ((x > 0) ? 1 : 0))
# define BLOCK_1(a, b, c, d) {a -= b; c += d;}
# define BLOCK_2(a, b, c, d, e) {if ((a += e) >= b) BLOCK_1(a, b, c, d);}

typedef struct	s_new_data
{
	int			ants;
	t_way		*way;
	t_room		*start;
	int			step;
	t_param		*p;
	int			*pos;
	float		*old_pos;
}				t_new_data;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_new_data	*data;
}				t_data;

t_way			*a_star(t_room *start, t_room *end, t_room *old_room);
void			ant_muve(t_way *way, int way_size, int step, int ants);
void			free_ways_a(t_way *old, t_way *frontier, t_way *way);
int				way_len(t_way *way);
t_room			*get_room(t_way *way, int way_size, int step, int ants, int num);

void			ft_open_win(char *str, t_param *p, t_way *way, int ants);
int				ft_draw(t_data *data);
int				key_release(int key, t_data *data);
int				ft_close(t_data *data);

#endif
