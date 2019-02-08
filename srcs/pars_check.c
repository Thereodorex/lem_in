/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:03:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/08 13:03:08 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_sharp(t_param *p, char *line)
{
	static int	start = 0;
	char		*line2;
	t_room		*tmp;

	if ((get_next_line(0, &line2)) == -1)
		STOP;
	check_room(p, line2);
	tmp = pars_room(p, line2);
	if (!ft_strcmp(line, "##start"))
	{
		if (++start != 1)
			STOP_IN;
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
	else
		STOP_IN;
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

int				check_num(char	*line)
{
	int		num;
	int		tmp;
	int		i;
	char	back_num[12];

	while (*line == ' ')
		++line;
	num = ft_atoi(line);
	i = 0;
	if (*line == '-' || *line == '+')
		*line == '-' && num != 0 ? back_num[i++] = *line : *line++;
	tmp = num;
	if (num == 0)
		back_num[0] = '0';
	while (tmp /= 10)
		++i;
	back_num[i + 1] = '\0';
	back_num[i] = MOD(num % 10) + '0';
	while (num /= 10)
		back_num[--i] = MOD(num % 10) + '0';
	return (num_cmp(line, back_num));
}

int				check_link(char *line)
{
	if (*line == '#')
	{
		if (*(line + 1) == '#')
			STOP_IN;
		return (2);
	}
	while (*line && *line != ' ' && *line != '-')
		line++;
	if (*line++ != '-')
		return (0);
	while (*line && *line != ' ' && *line != '-')
		line++;
	if (*line)
		return (0);
	return (1);
}

int				check_room(t_param *p, char *line)
{
	int			i;

	if (*line == '#')
	{
		if (*(line + 1) == '#')
			check_sharp(p, line);
		return (0);
	}
	if (check_link(line))
		return (2);
	while (*line && *line != ' ')
		++line;
	if (*line++ != ' ')
		STOP_IN;
	i = 1;
	while (++i < 4)
	{
		while (ft_isdigit(*line))
			++line;
		if (i == 3 ? *line : *line++ != ' ')
			STOP_IN;
	}
	return (1);
}
