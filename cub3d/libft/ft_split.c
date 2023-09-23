/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:57:45 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 06:29:37 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static int	count_chars(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i])
	{
		if ((*i == 2 && s[*i] != c) || (s[*i] != c && s[*i - 1] == c))
		{
			while (s[*i] != c && s[*i] != '\0')
			{
				len++;
				*i = *i + 1;
			}
			return (len);
		}
		*i = *i + 1;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		chars;
	int		p;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	ptr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (j < count_words(s, c))
	{
		chars = count_chars(s, c, &i);
		p = i - chars;
		ptr[j++] = ft_substr(s, p, chars);
	}
	ptr[count_words(s, c)] = 0;
	return (ptr);
}
