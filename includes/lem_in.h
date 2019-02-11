/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:02:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/11 19:29:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define MOD(x) (x < 0 ? -x : x)
# define STOP {ft_printf("MALLOC ERROR\n"); exit(0);}
# define STOP_IN {ft_printf("ERROR\n"); exit(0);}

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	struct s_room	*next;
	int				size;
	struct s_room	**links;
	int				visited;
	int				flag;
}				t_room;

typedef struct	s_way
{
	t_room			*room;
	t_room			*from;
	struct s_way	*next;
	struct s_way	*last;
}				t_way;

typedef struct	s_ways
{
	t_way			**way;
	int				size;
	struct s_ways	*next;
}				t_ways;

typedef struct	s_param
{
	int		ants;
	t_room	*start;
	t_room	*end;
	t_way	**ways;
	int		ways_count;
}				t_param;


t_room			*room_new(char *name, int x, int y);
t_room			*room_pushback(t_room *start, t_room *new);
t_room			*room_del(t_room *start);
t_room			**link_add(t_room **links, int size, t_room *new);
void			room_link(t_room *room1, t_room *room2);
void			read_data(t_param *p);
int				check_room(t_param *p, char *line);
int				check_link(char *line);
int				check_num(char  *line);
t_room			*pars_room(t_param *p, char *line);

#endif
