/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:51:57 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/15 21:01:40 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifdef BUFFER_SIZE
#  define MINIMUM_SIZE	512
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		has_eof(char *temp);
int		line_len(char *temp, int cursor, int flag);
char	*malloc_line(char *temp, int cursor, int flag);
int		has_null(char *temp);

#endif
