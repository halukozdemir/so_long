/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:47 by muguveli          #+#    #+#             */
/*   Updated: 2024/06/18 04:11:30 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	ft_strlen1(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*readline(int fd, char *readone);
char	*putline(char *readone);
char	*nxtline(char *readone);

#endif