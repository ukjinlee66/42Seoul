/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:33:23 by youlee            #+#    #+#             */
/*   Updated: 2020/06/17 20:22:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <math.h>
#include <stdbool.h>

bool		IN_MAP(t_pos *p, t_config *c)
{
	return (CHECK_TOP(p) && CHECK_BOT(p, c));
}

bool		MAP(t_pos *p, t_config *c)
{
	return ((c).map[(FINT(p->y) * (c)->columns) + FINT(p->x)]);
}

bool		MAP_XY(double x, double y, t_config *c)
{
	return ((c)->map[(FINT(y) * (c)->columns) + FINT(x)]);
}
