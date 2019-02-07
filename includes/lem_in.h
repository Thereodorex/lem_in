/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:02:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/07 15:02:58 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define STOP {ft_printf("MALLOC ERROR\n"); exit(0);}

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	struct s_room	*next;
	int				steps;
	int				size;
	struct s_room	**links;
}				t_room;

typedef struct	s_way
{
	t_room			*room;
	struct s_way	*next;
}				t_way;

typedef struct	s_param
{
	int		ants;
	t_room	*start;
	t_room	*end;
	t_way	**ways;
	int		ways_count;
}				t_param;

#endif
