/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/08 13:57:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_muve_ant(t_turn *turn, t_room *room, int ant_wait)
{
	int		index;

	if (room->links[0]->ants == 0 ||
		room->links[0]->flag == -1)
	{
		ft_printf("%s-%s ", turn->name, room->links[0]->name);
		room->ants--;
		room->links[0]->ants++;
		turn->room = room->links[0];
		return (1);
	}
	index = 0;
	while (++index < room->link_size)
	{
		if (room->links[index]->flag == -1)
		{
			ft_printf("%s-%s ", turn->name, room->links[index]->name);
			room->ants--;
			room->links[index]->ants++;
			turn->room = room->links[index];
			return (1);
		}
		if (room->links[index]->ants == 0)
		{
			if ((room->steps[index - 1] + 1 + ant_wait) >= room->steps[index])
			{
				ft_printf("%s-%s ", turn->name, room->links[index]->name);
				room->ants--;
				room->links[index]->ants++;
				turn->room = room->links[index];
				return (1);
			}
			return (0);
		}
	}
	return (0);
}

int		ft_muve_turn(t_turn *turn)
{
	t_room	*room;
	int		index;
	int		step;
	int		ant_wait;

	step = 0;
	ant_wait = 0;
	while (turn != NULL)
	{
		room = turn->room;
		index = -1;
		if (room->flag != -1)
		{
			if (ft_muve_ant(turn, room, ant_wait))
			{
				step++;
			}
			else
				ant_wait++;
		}
		turn = turn->next;
	}
	return (step);
}

void	ft_free_turn(t_turn *turn)
{
	t_turn	*ptr;

	while (turn != NULL)
	{
		ptr = turn;
//		ft_printf("%s %s\n", turn->name, turn->room->name);
		turn = turn->next;
		free(ptr->name);
		free(ptr);
	}
}

int		ft_corr_rooms(t_room *start)
{
	int	index;

	index = -1;
	while (++index < start->link_size)
		if (start->steps[index] >= 0)
			return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_room	*start;
	int		ants;
	t_turn	*turn;

	ants = 1;
	if (argc == 2)
		ants = ft_atoi(argv[1]);
	start =	ft_init_rooms(ants);
	ft_init_len(start);
	if (ft_corr_rooms(start) == 0)
	{
		ft_printf("There is no way!\n");
		exit(0);
	}
	ft_sotr_len(start);
//	ft_print_rooms(start);
	turn = ft_init_turn_ant(ants, start);
	while (ft_muve_turn(turn) > 0)
		ft_printf("\n");
	ft_free_turn(turn);
//	ft_print_rooms(start);
	room_del(start);
	return (0);
}
