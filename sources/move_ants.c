/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 19:02:04 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 13:50:49 by adubedat         ###   ########.fr       */
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

static void	move_ants4(t_paths *paths, int ants_nbr, char **argv)
{
	int		i;
	t_ants	ants[ants_nbr];
	t_paths *temp;

	temp = paths;
	i = 0;
	while (i < ants_nbr)
	{
		ants[i].name = i + 1;
		while (temp->room->ant <= 0)
		{
			if (temp->next == NULL)
				temp = paths;
			else
				temp = temp->next;
		}
		ants[i].room = temp->room;
		temp->room->ant -= 1;
		if (temp->next == NULL)
			temp = paths;
		else
			temp = temp->next;
		i++;
	}
	check_details(ants, ants_nbr, argv);
}

static void	move_ants3(t_paths *paths, int i, int ants, char **argv)
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
	move_ants4(paths, ants, argv);
}

static void	move_ants2(t_paths *paths, int paths_nbr, int ants, char **argv)
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
			return (move_ants2(paths, paths_nbr, ants, argv));
	}
	move_ants3(paths, i, ants, argv);
}

void		move_ants(t_paths *paths, int ants, char **argv)
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
	move_ants2(paths, paths_nbr, ants, argv);
}
