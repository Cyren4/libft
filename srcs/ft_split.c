/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:37:28 by cramdani          #+#    #+#             */
/*   Updated: 2019/11/24 20:49:53 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		nb_w(char const *s, char c)
{
	size_t len;
	size_t i;

	i = -1;
	len = 1;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

static size_t		check_len(char const *s, char c, size_t start)
{
	size_t len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
	{
		len++;
	}
	return (len);
}

static void			*clear(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	j;
	size_t	i;
	size_t	len;

	if (!s || !(str = ft_strtrim(s, &c)))
		return (NULL);
	j = -1;
	i = 0;
	if (!(strs = malloc(sizeof(char*) * (nb_w(str, c) + 1))))
		return (NULL);
	while (++j < nb_w(str, c))
	{
		len = check_len(str, c, i);
		if (!(strs[j] = ft_substr(str, i, len)))
			return (clear(strs));
		i = i + len;
		while (str[i] == c && str[i])
			i++;
	}
	strs[j] = NULL;
	free((void *)str);
	return (strs);
}
