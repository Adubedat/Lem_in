/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:22:31 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 15:27:10 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H
# include "lem_in.h"

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_tubes	*tubes;
	int				start;
	int				end;
	int				number;
	int				used;
	struct s_rooms	*next;
}					t_rooms;

#endif
