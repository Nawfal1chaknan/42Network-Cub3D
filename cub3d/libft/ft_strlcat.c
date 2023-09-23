/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:59:52 by namorgha          #+#    #+#             */
/*   Updated: 2022/10/12 14:59:56 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	j;
	size_t	lens;

	lens = ft_strlen(src);
	if (dstsize == 0)
		return (lens);
	lendst = ft_strlen(dst);
	if (dstsize <= lendst)
		lens += dstsize;
	else
		lens += lendst;
	j = 0;
	while (src[j] != '\0' && lendst + 1 < dstsize)
		dst[lendst++] = src[j++];
	dst[lendst] = '\0';
	return (lens);
}
