/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_var_2(t_tool *tool)
{
	tool->ang_x = 0;
	tool->buff = NULL;
	tool->ang_y = 0;
	tool->ang_z = 0;
	tool->scale = 0;
	tool->cos_x = 0;
	tool->cos_y = 0;
	tool->cos_z = 0;
	tool->sin_x = 0;
	tool->sin_y = 0;
	tool->sin_z = 0;
	tool->line = NULL;
	tool->num = NULL;
	tool->buff = NULL;
	tool->cp_org = NULL;
	tool->cp_new = NULL;
	tool->ch = 0;
}

void	ft_init_var_1(t_tool *tool, t_dot *dot)
{
	tool->dx = 0;
	tool->dy = 0;
	tool->s_dot = 0;
	tool->fault = 0;
	tool->f2 = 0;
	tool->mvx = 0;
	tool->mvy = 0;
	tool->mvz = 0;
	tool->line = NULL;
	tool->itr = 0;
	tool->dist = 45;
	tool->str_x = 0;
	tool->end_y = 0;
	tool->s_buff = 0;
	DEPTH = 1.0;
	ZOOM = 0;
	ERROR = 0;
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
	dot->color = 0;
	dot->mass = NULL;
}

int		ft_z_color(t_tool *tool, int c)
{
	int i;
	int x;

	i = 0;
	if (CHR(ARR[c], ',') && CHR(ARR[c], 'x'))
	{
		while (ARR[c][i])
		{
			if (ARR[c][i] == 'x')
			{
				x = ft_atoi_base(&ARR[c][i + 1], 16);
				return (x);
			}
			i++;
		}
	}
	return (0);
}

void	ft_del_tool(t_tool **tool)
{
	int i;

	i = 0;
	if ((*tool)->line)
		ft_strdel(&(*tool)->line);
	((*tool)->num) ? free((*tool)->num) : 0;
	if ((*tool)->cp_new)
		((*tool)->cp_new->mass) ? ft_del_struct(&(*tool)->cp_new) \
		: free((*tool)->cp_new);
	if ((*tool)->cp_org)
		((*tool)->cp_org->mass) ? ft_del_struct(&(*tool)->cp_org) \
		: free((*tool)->cp_org);
	free(*tool);
	*tool = NULL;
}

int		ft_valid_line(t_tool *tool)
{
	int i;

	i = 0;
	if (!LNE)
		return (1);
	if (LNE && !ft_strlen_my(LNE))
		ERROR += 1;
	return (0);
}
