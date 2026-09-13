/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpastor <mpastor@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:44:52 by mpastor           #+#    #+#             */
/*   Updated: 2026/09/13 20:26:21 by mpastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	assing(int grid[4][4], int i, int j, int clu[4][4]);

void	clear_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

// Start the grid
// if the clue is 1 or 4
// if it is 3 or 2 dont do nothing
void	start_grid(int grid[4][4], int clu[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (clu[i][j] == 4 || clu[i][j] == 1)
				assing(grid, i, j, clu);
			j++;
		}
		i++;
	}
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		k;
	char	number;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			number = grid[i][k] + '0';
			write(1, &number, 1);
			if (k < 3)
				write(1, " ", 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}
