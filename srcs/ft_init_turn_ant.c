/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_turn_ant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:51:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 13:22:21 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_turn	*ft_push_ant(t_turn **turn_ant, t_room *start, char *name)
{
	t_turn	*ant;
	t_turn	*ptr;

	ptr = *turn_ant;
	ant = (t_turn *)malloc(sizeof(t_turn));
	ant->room = start;
	ant->name = name;
	ant->next = NULL;
	if (*turn_ant == NULL)
		return (ant);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = ant;
	return (*turn_ant);
}

t_turn	*ft_init_turn_ant(int size, t_room *start)
{
	int		index;
	t_turn	*turn;
	char	*name;
	char	*new;
	char	*num;

	index = -1;
	turn = NULL;
	while (++index < size)
	{
		name = ft_strdup("L");
		num = ft_itoa(index + 1);
		new = ft_strjoin(name, num);
		free(num);
		free(name);
		turn = ft_push_ant(&turn, start, new);
	}
	return (turn);
}
