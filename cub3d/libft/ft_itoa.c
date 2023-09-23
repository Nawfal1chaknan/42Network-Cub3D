/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:47:57 by namorgha          #+#    #+#             */
/*   Updated: 2023/03/07 15:24:12 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_counter(long i)
{
	int	l;

	if (i == 0)
		return (1);
	l = 0;
	if (i < 0)
	{
		i = i * -1;
		l++;
	}
	while (i > 0)
	{
		i = i / 10;
		l++;
	}
	return (l);
}

char	*toi(long nb, char *ptr, int i)
{
	if (nb == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		ptr[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	nb;

	nb = n;
	i = nb_counter(nb);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i--] = '\0';
	return (toi(nb, ptr, i));
}
