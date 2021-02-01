/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 00:31:37 by keuclide          #+#    #+#             */
/*   Updated: 2021/02/02 00:48:04 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_base_ten(char *str, char c, int i, int n)
{
	while (n)
	{
		c = n % 10 + '0';
		str[i] = c;
		n /= 10;
		i++;
	}
}

int			ft_putnbr_base(int n, int base)
{
	unsigned int	x;
	char			str[30];
	int				i;
	int				j;
	char			c;

	i = 0;
	j = 0;
	x = n;
	if (base == 16)
	{
		while (x)
		{
			(x % 16 >= 10) ? (c = (x % 16) - 10 + 'a') :
			(c = (x % 16) + '0');
			str[i] = c;
			x /= 16;
			i++;
		}
	}
	else
		ft_base_ten(str, c, i, n);
	while (i > 0)
		j += write(1, &str[--i], 1);
	return (j);
}
