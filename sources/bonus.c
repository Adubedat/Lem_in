/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:47:41 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 15:14:15 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	wrong_entry(char *str)
{
	ft_printf("Error : Unknown option [%s]\n", str);
	ft_putendl("Expected entry : ./lem-in [-hdrp] < [file_name]");
	ft_putendl("-h : Help\n-r : Show rooms details");
	ft_putendl("-p : Show the possible paths");
	ft_putendl("-d : Show details");
	exit(1);
}

void		check_help(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] != '-')
			wrong_entry(argv[i]);
		j++;
		while (argv[i][j])
		{
			if (ft_strchr("hrpd", argv[i][j]) == NULL)
				wrong_entry(argv[i]);
			if (argv[i][j] == 'h')
			{
				ft_putendl("Expected entry : ./lem-in [-hdrp] < [file_name]");
				ft_putendl("-h : Help\n-r : Show rooms details");
				ft_putendl("-p : Show the possible pathsi\n-d : Show details");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	print_rooms(t_rooms *rooms)
{
	t_rooms	*temp;
	t_tubes	*temp2;

	temp = rooms;
	while (temp != NULL)
	{
		temp2 = temp->tubes;
		ft_printf("Room's name : %s\n", temp->name);
		ft_printf("Coordinates : [%d;%d]\n", temp->x, temp->y);
		ft_putstr("Linked rooms : ");
		while (temp2 != NULL)
		{
			ft_printf("[%s] ", temp2->room->name);
			temp2 = temp2->next;
		}
		ft_putchar('\n');
		if (temp->start == 1)
			ft_putendl("This is the start room.");
		if (temp->end == 1)
			ft_putendl("This is the end room.");
		temp = temp->next;
		ft_putstr("\n");
	}
}

static void	print_paths(t_paths *paths)
{
	t_paths	*temp;
	t_room	*temp2;
	int		i;

	temp = paths;
	i = 1;
	while (temp != NULL)
	{
		temp2 = temp->room;
		ft_printf("Chemin %d : ", i);
		while (temp2 != NULL)
		{
			if (temp2->next == NULL)
				ft_printf("[%s]", temp2->name);
			else
				ft_printf("[%s] - ", temp2->name);
			temp2 = temp2->next;
		}
		ft_putchar('\n');
		temp = temp->next;
		i++;
	}
	ft_putchar('\n');
}

void		check_bonus(t_rooms *rooms, t_paths *paths, char **argv)
{
	int	i;
	int	j;
	int	room_flag;
	int	paths_flag;

	i = 1;
	room_flag = 0;
	paths_flag = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'r' && room_flag++ == 0)
				print_rooms(rooms);
			else if (argv[i][j] == 'p' && paths_flag++ == 0)
				print_paths(paths);
			j++;
		}
		i++;
	}
}
