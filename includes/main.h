/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:25:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"
# include <mlx.h>

# define WIN_W 1300
# define WIN_H 1300
# define WIN_S (WIN_W * WIN_H)

# define EXIT(){ft_puts("\x1b[31mError\033[0m");return (0);}
# define NOARGCH(){ft_puts("\x1b[31m./checker [-v] [0-9]\033[0m");return (0);}
# define NOARGP(){ft_puts("\x1b[31m./push_swap [0-9]\033[0m");return (0);}

typedef struct	s_stack
{
	int			*a;
	int			size_a;
	int			*b;
	int			size_b;
	char		*str;
}				t_stack;

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
	t_stack		*stack;
}				t_data;

void			ft_open_win(char *str);
int				ft_draw(t_data *data);
int				key_release(int key, t_data *data);
int				ft_close(t_data *data);


#endif
