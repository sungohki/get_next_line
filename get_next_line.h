/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:51:57 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/17 05:01:29 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		is_endofline(char *temp, int cursor);
int		line_len(char *temp, int cursor);
char	*malloc_line(char *temp, int cursor);
char	*ft_strjoin(char *dst, char *src);
int		init(int *flag, int *cursor, char *temp, int fd);

#endif
