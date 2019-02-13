/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:57:53 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 18:43:31 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	buf_print(t_param *p)
{
	write(1, p->buf.buf, p->buf.len);
	p->buf.len = 0;
}

void	buf_addstr(t_param *p, char *str)
{
	while (*str)
	{
		p->buf.buf[p->buf.len++] = *str++;
		if (p->buf.len == BUF_SIZE)
			buf_print(p);
	}
}

void	buf_step(t_param *p, int lem, char *name)
{
	int		tmp;
	int		len;
	char	num[11];

	tmp = lem;
	len = 1;
	while (tmp /= 10)
		++len;
	num[len--] = '\0';
	while (lem)
	{
		num[len--] = lem % 10 + '0';
		lem /= 10;
	}
	buf_addstr(p, "L");
	buf_addstr(p, num);
	buf_addstr(p, "-");
	buf_addstr(p, name);
	buf_addstr(p, " ");
}
