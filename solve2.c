/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:34:26 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/22 17:57:20 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_elem(t_room *path, char *name)
{
	t_room	*temp;
	t_room	*new;

	temp = path;
	if (path == NULL)
	{
		path = (t_room*)malloc(sizeof(t_room));
		path->name = ft_strdup(name);
		path->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new = (t_room*)malloc(sizeof(t_room));
		new->name = ft_strdup(name);
		new->next = NULL;
		temp->next = new;
	}
	return (path);
}

t_rooms	*search_temp2(t_rooms *start)
{
	t_tubes	*temp;
	t_rooms	*temp2;

	temp = start->tubes;
	if (temp == NULL)
		return (NULL);
	temp2 = start;
	while (temp != NULL)
	{
		if (temp->room->number < temp2->number && temp->room->number != -1
				&& temp->room->used == 0)
			temp2 = temp->room;
		temp = temp->next;
	}
	if (temp2->used == 1 || temp2->start == 1)
		return (NULL);
	return (temp2);
}

void	delete_path(t_room **path)
{
	t_room	*temp;

	temp = *path;
	while (*path != NULL)
	{
		free((*path)->name);
		temp = (*path)->next;
		free(*path);
		*path = temp;
	}
}

t_paths	*initialize_new(void)
{
	t_paths	*new;

	new = (t_paths*)malloc(sizeof(t_paths));
	new->room = NULL;
	new->next = NULL;
	return (new);
}
