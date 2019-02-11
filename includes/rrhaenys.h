/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrhaenys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:28:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 19:29:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRHAENYS_H
# define RRHAENYS_H

t_way			*a_star(t_room *start, t_room *end, t_room *old_room);
void			ant_muve(t_way *way, int way_size, int step, int ants);
void			free_ways_a(t_way *old, t_way *frontier, t_way *way);
int				way_len(t_way *way);

#endif
