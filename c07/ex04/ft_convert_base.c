/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:47:33 by bazaluga          #+#    #+#             */
/*   Updated: 2023/08/24 15:41:20 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_itoa_base(int n, char *base);

int	valid_base(char *base, int *len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| (base[i] >= 9 && base[i] <= 13)))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
		i++;
	}
	*len = i;
	if (i >= 2)
		return (1);
	return (0);
}

int	find(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	nb;
	int	sign;
	int	index;

	len = ft_strlen(base);
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	sign = 1;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			sign = -sign;
	nb = 0;
	while (*str)
	{
		index = find(*str, base);
		if (index == -1)
			return (nb * sign);
		nb = nb * len + index;
		str++;
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		nb;
	int		len_from;
	int		len_to;

	if (!valid_base(base_from, &len_from) || !valid_base(base_to, &len_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(nb, base_to);
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	char	*n = argv[1];
	char	*base_f = argv[2];
	char	*base_t = argv[3];
	char	*res;

	res = ft_convert_base(n, base_f, base_t);
	printf("%s in base %s becomes\n%s in base %s\n", n, base_f, res, base_t);
	free(res);
	return (0);
}*/
