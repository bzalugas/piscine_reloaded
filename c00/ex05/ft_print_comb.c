/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:51:51 by bazaluga          #+#    #+#             */
/*   Updated: 2023/08/02 20:50:16 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(int nb)
{
	char	tmp[3];

	tmp[2] = nb % 10 + '0';
	tmp[1] = nb % 100 / 10 + '0';
	tmp[0] = nb / 100 + '0';
	write(1, tmp, 3);
	if (nb < 789)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	nb;

	nb = 12;
	while (nb < 999)
	{
		if (nb / 100 < nb % 100 / 10 && nb % 100 / 10 < nb % 10)
			display(nb);
		nb++;
	}
}
