/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:19:11 by keuclide          #+#    #+#             */
/*   Updated: 2020/11/13 16:16:34 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	del_spaces(const char *s, int i)
{
	if (i == 0)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
	}
	else
		while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			if (i == 0)
				return (0);
			i--;
		}
	return (i);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	char	*mem;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = del_spaces(s1, (ft_strlen(s1) - 1));
	if (end == 0)
	{
		mem = (ft_substr("", 0, 1));
		return (mem);
	}
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	start = del_spaces(s1, 0);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	mem = (ft_substr((char *)s1, start, end - start + 1));
	return (mem);
}
