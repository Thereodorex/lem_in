/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:27:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/12 19:40:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		way_len(t_way *way)
{
	int		index;
	t_way	*tmp;

	index = 1;
	tmp = way->next;
	while (tmp != way)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
