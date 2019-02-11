/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:27:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 19:28:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		way_len(t_way *way)
{
	int	index;

	index = 0;
	while (way != NULL)
	{
		way = way->next;
		index++;
	}
	return (index);
}
