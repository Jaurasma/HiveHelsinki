/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:53:46 by jaurasma          #+#    #+#             */
/*   Updated: 2022/07/16 12:53:50 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

void	ft_first_line(int x)
{
	int	width;

	width = 1;
	ft_putchar('A');
	while (width < x - 1)
	{
		ft_putchar('B');
		width++;
	}
	if (x > 1)
		ft_putchar('A');
	ft_putchar('\n');
}

void	ft_middle_line(int x, int y)
{
	int	width;
	int	height;

	width = 1;
	height = 1;
	while (height < y -1)
	{
		ft_putchar('B');
		while (width < x - 1)
		{
			ft_putchar(' ');
			width++;
		}
		if (x > 1)
			ft_putchar('B');
		width = 1;
		ft_putchar('\n');
		height++;
	}
}

void	ft_last_line(int x, int y)
{
	int	width;

	width = 1;
	if (y > 1)
	{
		ft_putchar('C');
		while (width < x - 1)
		{
			ft_putchar('B');
			width++;
		}
		if (x > 1)
			ft_putchar('C');
		ft_putchar('\n');
	}
}

int	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return (0);
	ft_first_line(x);
	ft_middle_line(x, y);
	ft_last_line(x, y);
	return (0);
}
