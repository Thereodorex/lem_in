/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:03:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/14 21:41:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_sharp(t_param *p, char *line)
{
	char		*line2;
	t_room		*tmp;

	if (!ft_strcmp(line, "##start") && ++(p->buf.len) != 1)
		STOP_IN;
	if ((get_next_line(0, &line2)) == -1)
		STOP;
	if ((check_room(p, line2)) != 1)
		STOP_IN;
	tmp = pars_room(p, line2);
	if (!ft_strcmp(line, "##start"))
	{
		tmp->next = p->start;
		p->start = tmp;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (p->end)
			STOP_IN;
		p->end = tmp;
		p->start = room_pushback(p->start, tmp);
	}
	free(line2);
}

static int		num_cmp(char *l1, char *l2)
{
	int		res;
	char	ch;
	char	*tmp;

	tmp = l1;
	while (*tmp && *tmp != ' ')
		++tmp;
	ch = *tmp;
	*tmp = '\0';
	res = ft_strcmp(l1, l2);
	*tmp = ch;
	return (res);
}

int				check_num(char *line)
{
	int		num;
	int		tmp;
	int		i;
	char	back_num[12];

	while (*line == ' ')
		++line;
	num = ft_atoi(line);
	if (num < 0 && *line != '-')
		return (-1);
	i = 0;
	if (*line == '-' || *line == '+')
		*line == '-' && num != 0 ? back_num[i++] = *line : *line++;
	tmp = num;
	if (num == 0)
		back_num[0] = '0';
	while (tmp /= 10)
		++i;
	back_num[i + 1] = '\0';
	back_num[i] = MOD((num % 10)) + '0';
	while (num /= 10)
		back_num[--i] = MOD((num % 10)) + '0';
	return (num_cmp(line, back_num));
}

int				check_link(char *line)
{
	if (*line == '#')
		return (2);
	while (*line && *line != '-')
		line++;
	if (*line++ != '-')
		STOP_IN;
	if (!(*line))
		STOP_IN;
	return (1);
}

int				check_room(t_param *p, char *line)
{
	int			i;

	if (*line == 'L')
		return (2);
	if (*line == '#' && *(line + 1) == '#')
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			check_sharp(p, line);
	if (*line == '#')
		return (0);
	while (*line && *line != ' ')
		++line;
	if (*line++ != ' ')
		return (2);
	i = 0;
	while (++i < 3)
	{
		if (*line == '-')
			++line;
		while (ft_isdigit(*line))
			++line;
		if (i == 1 ? *line++ != ' ' : *line)
			return (2);
	}
	return (1);
}
