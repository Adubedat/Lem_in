/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 05:49:24 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/21 22:48:46 by adubedat         ###   ########.fr       */
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
	temp2 = room->tubes->room;
	while (temp != NULL)
	{
		if (temp->room->number < temp2->number && temp->room->number != -1
				&& temp->room->used == 0)
			temp2 = temp->room;
		temp = temp->next;
	}
	ft_printf("====> %s\n", temp2->name);
	*path = create_elem(*path, temp2->name);
//	ft_printf("==> %s\n", (*path)->name);
	t_room *test = *path;
	while (test != NULL)
	{
		ft_printf("==> %s\n", test->name);
		test = test->next;
	}
	if (temp2->end != 1)
		temp2->used = 1;
	if (temp2->end == 1 || temp2->number > room->number)
		return ;
	found_shorter_path(temp2, path);
}

static void	create_paths(t_rooms *room, t_paths *paths)
{
	t_tubes	*temp;
	t_paths	*temp2;

	temp2 = paths;
	temp = room->tubes;
	while (temp != NULL)
	{
		while (temp2 != NULL
				&& ft_strcmp(temp2->room->name, temp->room->name) != 0)
			temp2 = temp2->next;
		if (temp2 == NULL)
		{
			temp2 = (t_paths*)malloc(sizeof(t_paths));
			temp2->room = NULL;
			temp2->next = NULL;
			found_shorter_path(room, &temp2->room);
			print_list_number(room);
			ft_printf("%s\n%s\n", temp2->room->name, temp->room->name);
		}
		else
			temp = temp->next;
	}
}

void		print_list_number(t_rooms *room)
{
	t_rooms *temp;

	temp = room;
	while (temp != NULL)
	{
		ft_printf("%s -> %d\n", temp->name, temp->used);
		temp = temp->next;
	}
}

void		solve(t_rooms *room, t_paths *paths)
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
	ft_putchar('Z');
	print_list_number(room);
	create_paths(temp, paths);
}
