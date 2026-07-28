/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:05:05 by rafcrist          #+#    #+#             */
/*   Updated: 2026/07/28 14:05:05 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	long	nl;

	count = 0;
	nl = n;
	if (nl < 0)
	{
		nl *= -1;
		count += ft_putchar('-');
	}
	if (nl >= 10)
		count += ft_putnbr(nl / 10);
	count += ft_putchar(nl % 10 + '0');
	return (count);
}
