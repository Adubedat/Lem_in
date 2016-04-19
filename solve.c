/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 05:49:24 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/19 09:26:42 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_rooms	*numbering_rooms(t_rooms *room, int i, int *change)
{
	t_tubes	*temp;

	temp = room->tubes;
	while (temp != NULL)
	{
		if (temp->room->number == -1)
		{
			temp->room->number = i;
			*change = 1;
		}
		temp = temp->next;
	}
	return (room);
}

static t_rooms	*found_path(t_rooms *begin_list, int i, int *change)
{
	t_rooms		*temp;

	temp = begin_list;
	while (temp != NULL)
	{
		if (temp->number == i)
		{
			temp = numbering_rooms(temp, i + 1, change);
			*change = 1;
		}
		temp = temp->next;
	}
	return (begin_list);
}	

void		found_shorter_path(t_rooms *room)
{
	t_tubes *temp;
	t_rooms *temp2;

	temp = room->tubes;
	temp2 = room->tubes->room;
	ft_printf("%d\n", room->number);
	ft_printf("[%s] - ", room->name);
	while (temp != NULL)
	{
		if (temp->room->number < temp2->number && temp->room->number != -1)
			temp2 = temp->room;
		temp = temp->next;
	}
	if (temp2->end == 1)
	{
		ft_printf("[%s]", temp2->name);
		return ;
	}
	found_shorter_path(temp2);
}

void		solve(t_rooms *room)
{
	t_rooms *temp;
	int		i;
	int		change;

	i = 0;
	change = 0;
	temp = room;
	while (temp->end != 1)
		temp = temp->next;
	temp->number = 0;
	while (change == 1)
	{
		found_path(room, i, &change);
		i++;
	}
	temp = room;
	while (temp->start != 1)
		temp = temp->next;
	found_shorter_path(temp);
}
