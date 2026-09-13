/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpastor <mpastor@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:34:03 by mpastor           #+#    #+#             */
/*   Updated: 2026/09/13 20:23:11 by mpastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	save_clues(char *str, int clues[4][4]);
int		valid_input(char *str);
void	clear_grid(int grid[4][4]);
void	print_grid(int grid[4][4]);
void	start_grid(int grid[4][4], int clu[4][4]);
int		solve_grid(int grid[4][4], int clues[4][4], int position);

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[4][4];

	if (argc != 2 || valid_input(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	save_clues(argv[1], clues);
	clear_grid(grid);
	start_grid(grid, clues);
	if (solve_grid(grid, clues, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
