/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:38:17 by cramdani          #+#    #+#             */
/*   Updated: 2020/04/26 23:44:39 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_len(int n)
{
	int	size;

	size = 0;
	if (n < 0 || n == 0)
		size += 1;
	while (n != 0)
	{
		n = n / 10;
		size += 1;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			stop;
	long int	nbr;

	len = int_len(n);
	nbr = n;
	if (!((str = malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		stop = 1;
	}
	else
		stop = 0;
	str[len] = 0;
	while (len > stop)
	{
		str[--len] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}
