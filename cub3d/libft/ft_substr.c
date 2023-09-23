/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:33 by namorgha          #+#    #+#             */
/*   Updated: 2022/10/12 15:02:41 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	lens;

	i = 0;
	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (start >= lens || len == 0)
	{
		ptr = malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len >= lens - start)
		return (ft_strdup(s + start));
	ptr = malloc((len) + 1);
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
