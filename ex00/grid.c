/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpastor <mpastor@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:51:01 by mpastor           #+#    #+#             */
/*   Updated: 2026/09/13 20:05:09 by mpastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// Fill the grid 

void	grid_assing(int grid[4][4], int cons, int rorc, int cord)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (rorc == 0)
		{
			if (cord == 0)
				grid[cons][x] = x + 1;
			else
				grid[cons][x] = 4 - x;
		}
		else
		{
			if (cord == 0)
				grid[x][cons] = x + 1;
			else
				grid[x][cons] = 4 - x;
		}
		x++;
	}
}

// i = direction &&  j = Collum or row 
// Put the 4 in place where clue equals 1

void	clue_1(int grid[4][4], int i, int j)
{
	if (i == 0)
		grid[0][j] = 4;
	else if (i == 1)
		grid[3][j] = 4;
	else if (i == 2)
		grid[j][0] = 4;
	else
		grid[j][3] = 4;
}

void	assing(int grid[4][4], int i, int j, int clu[4][4])
{
	if (clu[i][j] == 1)
		clue_1(grid, i, j);
	else if (clu[i][j] == 4)
		grid_assing(grid, j, i < 2, i % 2);
}
