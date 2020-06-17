/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:13:20 by youlee            #+#    #+#             */
/*   Updated: 2020/06/17 20:25:57 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		FINT(double x)
{
	return ((int)floor(x));
}

bool	CHECK_TOP(t_pos *p)
{
	return (FINT(p->x) >= 0 && FINT(p->y) >= 0);
}

bool	CHECK_BOT(t_pos *p, t_config *c)
{
	return (FINT(p->x) < (c)->columns && FINT(p->y) < (c)->rows);
}
