/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 03:09:24 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 13:18:46 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_data(t_rooms *room)
{
	t_rooms *temp;

	temp = room;
	if (temp == NULL)
	{
		ft_putendl("Error : No room");
		exit(1);
	}
	while (temp != NULL && temp->start == 0)
		temp = temp->next;
	if (temp == NULL)
	{
		ft_putendl("Error : No start room declared");
		exit(1);
	}
	temp = room;
	while (temp != NULL && temp->end == 0)
		temp = temp->next;
	if (temp == NULL)
	{
		ft_putendl("Error : No end room declared");
		exit(1);
	}
}

void	error_room(void)
{
	ft_putendl("Error : Room's name already used");
	exit(1);
}

void	path_error(void)
{
	ft_putendl("Error : No path founded");
	exit(1);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int		check_tube(char *str, int i, t_rooms *room)
{
	char	**split;
	t_rooms *temp;

	temp = room;
	split = ft_strsplit(str, '-');
	if (split[2] != NULL || split[1] == NULL)
		return (0);
	while (temp != NULL && i < 2)
	{
		if (ft_strcmp(temp->name, split[i]) == 0)
			return (check_tube(str, i + 1, room));
		temp = temp->next;
	}
	free_split(split);
	if (i < 2)
		return (0);
	return (2);
}
