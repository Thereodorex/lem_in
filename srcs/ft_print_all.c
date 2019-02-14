/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:57:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/14 23:00:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void	ft_print_all(t_param *p, char *name)
{
	int			*map;
	int			index;

	map = testfun(&(p->w_main), p->ants);
	index = 0;
	if (p->visual == 1)
		ft_open_win(name, p, &(p->w_main));
	else
		while (ant_muve(&(p->w_main), ++index, map) == 1)
			;
	free(map);
}
