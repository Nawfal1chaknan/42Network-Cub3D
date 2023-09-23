/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:35:51 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/19 06:30:21 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_line(char *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	strleen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (strleen(s1) == 0 && strleen(s2) == 0)
		return (0);
	ptr = malloc(sizeof(char) * (strleen(s1) + strleen(s2) + 1));
	if (!ptr)
		return (0);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && i < strleen(s1) + strleen(s2))
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*get_last(char *s1)
{
	int		count;
	int		count2;
	char	*ptr;
	int		i;

	count = 0;
	count2 = 0;
	i = 0;
	if (!s1)
		return (0);
	while (s1[count])
		count++;
	while (s1[count2] && s1[count2] != '\n')
		count2++;
	if (s1[count2] == '\n')
		count2++;
	if ((count - count2) <= 0)
		return (0);
	ptr = malloc((count - count2) + 2);
	if (!ptr)
		return (0);
	while (s1[count2])
		ptr[i++] = s1[count2++];
	ptr[i] = '\0';
	return (ptr);
}

char	*get_new_line(char *str)
{
	int		count;
	char	*ptr;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	if (str[count] == '\n')
		count++;
	ptr = malloc(count + 2);
	if (!ptr)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
	{
		ptr[count] = str[count];
		count++;
	}
	if (str[count] == '\n')
		ptr[count++] = '\n';
	ptr[count] = '\0';
	free(str);
	return (ptr);
}
