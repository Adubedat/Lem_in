/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:03:50 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 17:47:55 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "room.h"

typedef struct		s_tubes
{
	t_rooms			*room;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_room
{
	char			*name;
	int				ant;
	int				number;
	struct s_room	*next;
}					t_room;

typedef struct		s_paths
{
	t_room			*room;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_ants
{
	int				name;
	t_room			*room;
}					t_ants;

void				check_details(t_ants *ants, int ants_nbr, char **argv);
t_rooms				*get_input(char **input, t_rooms *room, int start, int end);
int					check_tube(char *str, int i, t_rooms *room);
void				free_split(char **split);
void				error_room(void);
void				check_data(t_rooms *room);
void				solve(t_rooms *room, t_paths **paths);
t_room				*create_elem(t_room *path, char *name, int number);
void				print_list_number(t_tubes *room);
t_rooms				*search_temp2(t_rooms *start);
void				path_error(void);
void				delete_path(t_room **path);
t_paths				*initialize_new(void);
void				move_ants(t_paths *paths, int ants, char **argv);
void				check_help(int argc, char **argv);
void				check_bonus(t_rooms *room, t_paths *paths, char **argv);

#endif
