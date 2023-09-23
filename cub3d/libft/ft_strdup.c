/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:58:25 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 01:40:25 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*part0(char *s1, char *ptr, int s, int i)
{
	while (s1[s] != '\n')
	{
		if (s1[s] == ',')
		{
			ptr[i] = ' ';
			i++;
			s++;
		}
		else if (s1[s] == ' ')
			s++;
		else
		{
			ptr[i] = s1[s];
			i++;
			s++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdupp(char *s1, int s)
{
	char	*ptr;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(s1);
	if (!s1)
		return (0);
	ptr = malloc(((l + 1) - s) * sizeof(char));
	if (!ptr)
		return (0);
	ptr = part0(s1, ptr, s, i);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(s1);
	if (!s1)
		return (0);
	ptr = malloc((l + 3) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
