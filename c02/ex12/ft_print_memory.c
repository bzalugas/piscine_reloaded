/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:53:59 by bazaluga          #+#    #+#             */
/*   Updated: 2023/08/11 13:46:33 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(unsigned long addr, int i)
{
	if (addr > 15)
		print_addr(addr / 16, i - 1);
	if (addr <= 15)
		while (--i > 0)
			write(1, "0", 1);
	ft_putchar("0123456789abcdef"[addr % 16]);
	if (i == 16)
		write(1, ": ", 2);
}

void	print_char_hex(unsigned char c)
{
	char	hex[2];

	hex[0] = "0123456789abcdef"[c / 16];
	hex[1] = "0123456789abcdef"[c % 16];
	write(1, hex, 2);
}

void	print_str(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] < 32 || str[i] > 126 || !str[i])
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < size || j - i < 16)
	{
		if (j > 0 && j % 16 == 0)
			print_str((char *)addr + i, 16);
		if (j % 16 == 0)
		{
			print_addr((unsigned long)addr + j, 16);
			i = j;
		}
		if (j >= size)
			write(1, "  ", 2);
		else
			print_char_hex(((char *)addr)[j]);
		if (j % 2 != 0)
			ft_putchar(' ');
		j++;
	}
	if (j - i == 16)
		print_str((char *)addr + i, size - i);
	return (addr);
}

/*#include <stdio.h>
int	main(void)
{
	char	s[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut \
	faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	char s[] = {'B','o','n','j','o','u','r',-0x7f, 0x7f, 'a','b','c','d'};
	ft_print_memory(s, 15);
	return (0);
}*/
