/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:02:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 19:16:10 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define PLUS_MAX(i, max) (i = i == max -1 ? 0 : i + 1)
# define BUF_SIZE 1000
# define MOD(x) (x < 0 ? -x : x)
# define STOP {ft_printf("MALLOC ERROR\n"); exit(0);}
# define STOP_IN {ft_printf("ERROR\n"); exit(0);}

typedef struct	s_buf
{
	char	buf[BUF_SIZE];
	int		len;
}				t_buf;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				way;
	struct s_room	*next;
	int				step_e;
	int				step_s;
	int				l_count;
	struct s_room	**links;
}				t_room;

typedef struct	s_way
{
	t_room			*room;
	int				steps;
	struct s_way	*prev;
	struct s_way	*next;
}				t_way;

typedef struct	s_ways
{
	int				count;
	struct s_way	**ways;
}				t_ways;

typedef struct	s_param
{
	int				step_mode;
	int				ants;
	t_room			*start;
	t_room			*end;
	t_ways			w_all;
	t_ways			w_main;
	t_buf			buf;
	unsigned int	s_limit;
	unsigned int	b_limit;
}				t_param;

t_room			*room_new(char *name, int x, int y);
t_room			*room_pushback(t_room *start, t_room *new);
t_room			*room_del(t_room *start);
t_room			**link_add(t_room **links, int size, t_room *new);
void			room_link(t_room *room1, t_room *room2);

t_way			*way_new(t_room *room);
t_way			*way_pushback(t_way *start, t_way *new);
t_way			*way_del(t_way *start, t_way *from);
t_way			*way_cpy(t_way *from, t_way *to);
void			way_realloc(t_ways *w);
void			del_ways(t_ways *w);

void			read_data(t_param *p);
t_room			*pars_room(t_param *p, char *line);
int				check_room(t_param *p, char *line);
int				check_link(char *line);
int				check_num(char *line);

void			set_steps(t_room *end, t_room *start, int e, int n);
void			sort_ways(t_ways *w);
void			comb_ways(t_param *p);

void			print_way(t_way *w);

void			buf_print(t_param *p);
void			buf_addstr(t_param *p, char *str);
void			buf_step(t_param *p, int lem, char *name);
void			move(t_param *p);

void			print_farm(t_param *p);

#endif
