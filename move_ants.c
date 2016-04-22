/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 19:02:04 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/22 21:39:39 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	create_start(t_room **room)
{
	t_room *new;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup("start");
	new->ant = 0;
	new->next = *room;
	*room = new;
}

static void	move_ants4(t_paths *paths)
{
	int		i;
	int		tmp;
	t_paths	*temp;
	t_room	*room;

	temp = paths;
	i = 0;                                    ////BULLSHIT
	while (temp != NULL)
	{
		room = temp->room;
		while (room->next != NULL)
		{
			if (room->ant > 0 && ft_strcmp(room->name, "start") == 0)
			{
				i++;
				room->ant -= 1;
				room->next->ant += i;
				ft_printf("L%d-%s ", i, room->next->name);
				room = room->next;
				tmp = i;
			}
			if (tmp != 0)
			{
				tmp = room->next->ant
				room->next->ant += room->ant


	
static void	move_ants3(t_paths *paths, int i)
{
	t_paths *temp;

	temp = paths;
	while (i > 0)
	{
		if (temp->room->ant - 1 >= 0)
		{
			temp->room->ant -= 1;
			i--;
		}
		if (temp->next == NULL)
			temp = paths;
		else
			temp = temp->next;
	}
	temp = paths;
	move_ants4(paths);
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->room->ant);
		temp = temp->next;
	}
}


static void	move_ants2(t_paths *paths, int paths_nbr)
{
	static int	i = 0;
	t_paths		*temp;

	temp = paths;
	if (paths_nbr > 1)
	{
		while (temp->next != NULL)
		{
			while ((temp->room->ant - temp->next->room->ant)
				< (temp->next->room->next->number - temp->room->next->number))
			{
				temp->room->ant += 1;
				i++;
			}
			temp = temp->next;
		}
		temp = paths;
		if ((temp->room->ant - temp->next->room->ant)
			< (temp->next->room->next->number - temp->room->next->number))
			return (move_ants2(paths, paths_nbr));
	}
	move_ants3(paths, i);
}

void		move_ants(t_paths *paths, int ants)
{
	t_paths	*temp;
	int		paths_nbr;
	int		i;

	paths_nbr = 0;
	temp = paths;
	while (temp != NULL)
	{
		paths_nbr++;
		temp = temp->next;
	}
	temp = paths;
	i = ants % paths_nbr;
	while (temp != NULL)
	{
		create_start(&(temp->room));
		temp->room->ant = ants / paths_nbr;
		if (i > 0)
		{
			temp->room->ant += 1;
			i--;
		}
		temp = temp->next;
	}
	move_ants2(paths, paths_nbr);
}
