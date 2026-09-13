/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpastor <mpastor@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:00:56 by mpastor           #+#    #+#             */
/*   Updated: 2026/09/13 19:08:30 by mpastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int line[4]);
int	count_visible_reverse(int line[4]);

int	check_row(int grid[4][4], int clues[4][4], int row)
{
	int	line[4];
	int	x;

	x = 0;
	while (x < 4)
	{
		line[x] = grid[row][x];
		x++;
	}
	if (count_visible(line) != clues[2][row])
		return (0);
	if (count_visible_reverse(line) != clues[3][row])
		return (0);
	return (1);
}

int	check_column(int grid[4][4], int clues[4][4], int col)
{
	int	column[4];
	int	x;

	x = 0;
	while (x < 4)
	{
		column[x] = grid[x][col];
		x++;
	}
	if (count_visible(column) != clues[0][col])
		return (0);
	if (count_visible_reverse(column) != clues[1][col])
		return (0);
	return (1);
}

int	check_all_clues(int grid[4][4], int clues[4][4])
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (!check_row(grid, clues, index))
			return (0);
		if (!check_column(grid, clues, index))
			return (0);
		index++;
	}
	return (1);
}
