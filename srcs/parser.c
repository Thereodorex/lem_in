/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:29 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 20:07:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		pars_link(t_param *p, char *line)
{
	t_room	*l1;
	t_room	*l2;
	char	*ptr;

	ptr = line;
	while (*ptr != '-')
		++ptr;
	*ptr++ = '\0';
	l1 = p->start;
	l2 = p->start;
	while (l1 && ft_strcmp(l1->name, line))
		l1 = l1->next;
	while (l2 && ft_strcmp(l2->name, ptr))
		l2 = l2->next;
	if (!l1 || !l2)
		STOP_IN;
	room_link(l1, l2);
}

static void		pars_ants(t_param *p, char **line)
{
	get_next_line(0, line);
	if (!line || *line == NULL || check_num(*line))
		STOP_IN;
	p->ants = ft_atoi(*line);
	if (p->ants < 0)
		STOP_IN;
	ft_strdel(line);
	if ((get_next_line(0, line)) == -1)
		STOP;
}

static void		check_name(t_room *start, char *line)
{
	while (start && ft_strcmp(start->name, line))
		start = start->next;
	if (start)
		STOP_IN;
}

t_room			*pars_room(t_param *p, char *line)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = line;
	while (*ptr != ' ')
		++ptr;
	*ptr++ = '\0';
	check_name(p->start, line);
	if (check_num(ptr))
		STOP_IN;
	x = ft_atoi(ptr);
	while (!ft_isdigit(*ptr))
		++ptr;
	while (ft_isdigit(*ptr))
		++ptr;
	if (check_num(ptr))
		STOP_IN;
	y = ft_atoi(ptr);
	return (room_new(line, x, y));
}

void			read_data(t_param *p, char *line, int f)
{
	pars_ants(p, &line);
	if ((ft_strlen(line) == 0))
		STOP_IN;
	while (line && *line)
	{
		if ((f = check_room(p, line)) == 1)
			p->start = room_pushback(p->start, pars_room(p, line));
		else if (f == 2)
			break ;
		ft_strdel(&line);
		if ((get_next_line(0, &line)) == -1)
			STOP;
	}
	while (line && *line)
	{
		if ((f = check_link(line)) == 1)
			pars_link(p, line);
		else if (f == o)
			STOP_IN;
		ft_strdel(&line);
		if ((get_next_line(0, &line)) == -1)
			STOP;
	}
	p->start->ants = p->ants;
}
