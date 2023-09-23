/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:38:59 by namorgha          #+#    #+#             */
/*   Updated: 2023/08/05 16:25:36 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char		buff[BUFFER_SIZE + 1];
	char		*ptr;
	int			r;

	r = 1;
	ptr = NULL;
	if (content)
		ptr = strjoin(content, ptr);
	while (r)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			break ;
		buff[r] = '\0';
		ptr = strjoin(ptr, buff);
		if (new_line(ptr))
			break ;
	}
	content = get_last(ptr);
	return (get_new_line(ptr));
}
