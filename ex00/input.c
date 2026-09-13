/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpastor <mpastor@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:27:37 by mpastor           #+#    #+#             */
/*   Updated: 2026/09/13 18:33:32 by mpastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// confirm if the input is valid
int	valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i >= 31)
			return (0);
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	save_clues(char *str, int clues[4][4])
{
	int	k;

	k = 0;
	while (k < 16)
	{
		clues[k / 4][k % 4] = str[k * 2] - '0';
		k++;
	}
}
