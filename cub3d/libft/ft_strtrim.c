/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:15 by namorgha          #+#    #+#             */
/*   Updated: 2022/10/12 15:02:25 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isit(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1) - 1;
	if (!(set))
		return (ft_strdup(s1));
	while (isit(s1[i], set) == 1)
		i++;
	if (len + 1 == i)
		return (ft_strdup(""));
	while (isit(s1[len], set) == 1)
		len--;
	ptr = malloc((len - i + 1) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	return (ft_strncpy(ptr, (char *)s1 + i, len - i + 1));
}
