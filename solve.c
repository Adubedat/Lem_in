/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 05:49:24 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/22 20:02:41 by adubedat         ###   ########.fr       */
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
		if (temp->number == i && temp->start == 0)
			temp = numbering_rooms(temp, i + 1, change);
		temp = temp->next;
	}
	return (begin_list);
}	

static void	found_shorter_path(t_rooms *room, t_room **path)
{
	t_tubes *temp;
	t_rooms *temp2;

	temp = room->tubes;
	temp2 = room;
	*path = create_elem(*path, temp2->name, temp2->number);
	temp2->used = 1;
	if (temp2->end == 1 || temp2->number > room->number)
		return ;
	while (temp != NULL)
	{
		if ((temp->room->number < temp2->number && temp->room->number != -1
				&& temp->room->used == 0) || temp->room->end == 1)
			temp2 = temp->room;
		temp = temp->next;
	}
	if (temp2->used == 1)
	{
		if (temp2->end == 1)
			*path = create_elem(*path, temp2->name, temp2->number);
		else
			delete_path(path);
		return ;
	}
	found_shorter_path(temp2, path);
}

static void	create_paths(t_rooms *room, t_paths **paths)
{
	t_rooms	*temp2;
	t_paths *tmp;
	t_paths	*new;

	if ((temp2 = search_temp2(room)) == NULL)
		return ;
	tmp = *paths;
	if (*paths == NULL)
	{
		(*paths) = (t_paths*)malloc(sizeof(t_paths));
		(*paths)->room = NULL;
		(*paths)->next = NULL;
		found_shorter_path(temp2, &((*paths)->room));
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = initialize_new();
		found_shorter_path(temp2, &(new->room));
		if (new->room)
			tmp->next = new;
	}
	create_paths(room, paths);
}

void		solve(t_rooms *room, t_paths **paths)
{
	t_rooms *temp;
	int		i;
	int		change;

	i = 0;
	change = 1;
	temp = room;
	while (temp->end != 1)
		temp = temp->next;
	temp->number = 0;
	while (change == 1)
	{
		change = 0;
		found_path(room, i, &change);
		i++;
	}
	temp = room;
	while (temp->start != 1)
		temp = temp->next;
	temp->number = 2147483647;
	create_paths(temp, paths);
	if (*paths == NULL)
		path_error();
}
