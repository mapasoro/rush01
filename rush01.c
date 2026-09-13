#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// FILL THE GRID

void grid_assing(int grid[4][4], int constant, int roworcolum, int cres_or_decre)
{
	int x = 0; // counter
	while(x < 4) // to count from 0 to 3
	{
		if(roworcolum == 0) // is it column or row? if == 0 is row
		{
			if (cres_or_decre== 0) // direction?
				grid[constant][x] = x + 1; // top -> bottom
			else
				grid[constant][x] = 4 - x; // bottom -> top
		}
		else // (roworcolumn == 1, if == 1 is column)
		{
			if (cres_or_decre == 0)
				grid[x][constant] = x + 1; // left -> right
			else
				grid[x][constant] = 4 - x; // right -> left
		}
		x++;
	}
}

// CLUES
// i = direction &&  j = Collum or row 
// // Put the 4 in place where clue equals 1

void clue_1(int grid[4][4], int i, int j)
{
	if (i == 0)
		grid[0][j] = 4; // put building 4 top -> bottom
	else if (i == 1)
		grid[3][j] = 4; // put building 4 bottom -> top
	else if (i == 2)
		grid[j][0] = 4; // put building 4 left -> right
	else
		grid[j][3] = 4; // put building 4 right -> left
}

void assing(int grid[4][4], int i, int j, int arr[4][4])
{
	if (arr[i][j] == 1)
		clue_1(grid, i, j); // put building 4
	else if (arr[i][j] == 4)
		grid_assing(grd, j, i < 2, 1 % 2); // fill the complete row or column with building 1, 2, 3 and 4 (this order)

int permutations[24][4] =
{
	{1,2,3,4}, {1,2,4,3}, {1,3,2,4}, {1,3,4,2}, {1,4,2,3}, {1,4,3,2},
	{2,1,3,4}, {2,1,4,3}, {2,3,1,4}, {2,3,4,1}, {2,4,1,3}, {2,4,3,1},
	{3,1,2,4}, {3,1,4,2}, {3,2,1,4}, {3,2,4,1}, {3,4,1,2}, {3,4,2,1},
	{4,1,2,3}, {4,1,3,2}, {4,2,1,3}, {4,2,3,1}, {4,3,1,2}, {4,3,2,1}
}

void start_grid(int grid[4][4], int arr[4][4])
{
	int i = 0; // counting the pov
	while (i < 4)
	{
		int j = 0; // counting the row or column
		while(j < 4)
		{
			// if the clue is 1 or 4
			// // if it is 3 or 2 dont do nothing 
			if(arr[i][j] == 4  || arr[i][j] == 1)
				assing(grid, i, j, arr);
				j++;
		}
	i++;
	}
}

int count_visible(int line[4]) // looking to a row/column from one pov and check how many buildings are visible
{
	int i = 0; // starting into the row/column
	int max = 0; // starting the max higher as 0
	int count = 0; // starting the count
	while (i < 4) // going through the row/column
	{
		if (line[i] > max)      // is this building higher than the previous ones?
		{
			max = line[i];      // if yes, max value is updated with that height
			count++;            // count as visible and go to the next one
		}
		i++;
	}
	return count; // return the last value of count (total visible buildings)
}

void get_line(int grid[4][4], int i, int j, int line[4]) // from a pov (i) where j is a row/column, get the 4 values from grid in the order they are visible from that pov
{
	int x = 0; // counter, starting by 0
	while (x < 4)
	{
		if (i == 0)
			line[x] = grid[x][j]; // top -> bottom in column j
		else if (i == 1)
			line[x] = grid[3 - x][j]; // bottom -> top in column j
		else if (i == 2)
			line[x] = grid[j][x]; // left -> right in row j
		else
			line[x] = grid[j][3 - x]; // right -> left in row j
		x++;
	}
}

void set_line(int grid[4][4], int i, int j, int line[4]) // get the array, already with the orders done, and write the values back to the grid, in the correct places, following the directions
{
	int x = 0;
	while (x < 4)
	{
		if (i == 0)
			grid[x][j] = line[x]; // top -> bottom, in column j
		else if (i == 1)
			grid[3 - x][j] = line[x]; // bottom -> top, in column j
		else if (i == 2)
			grid[j][x] = line[x]; // left -> right, in row j
		else
			grid[j][3 - x] = line[x]; // right -> left, in row j
		x++;
	}
}

int compatible(int perm[4], int line[4]) // check if a possible permute (ex: {3,4,1,2}) is compatible with what we already know about that row/column (line), where line == 0 means "still don't know the correct value to put here")
{
	int x = 0;
	while (x < 4)
	{
		if (line[x] != 0 && line[x] != perm[x])  // if there is a value here AND is different from permute
			return 0; // then do nothing
		x++;
	}
	return 1;   // passed all the positions of the grid, is compatible
}

void solve_23(int grid[4][4], int i, int j, int clue) // to get the grid, line by line, with actual values, in the correct order
{
	int line[4]; // counter for the lines
	int result[4] = {0, 0, 0, 0}; // initial permute, all free spaces
	int found = 0; // inicial found
	int p = 0;
	
	get_line(grid, i, j, line);   // step 1: get the actual line, in the correct order, with 0 in the places where we still don't know which value will be
	
	while (p < 24) // go through all the 24 possible permutes
	{
		if (compatible(permutations[p], line) && count_visible(permutations[p]) == clue) //if is compatible with what is already placed AND is visible buildings are == input clue
		// if fails one of these conditions, ignore this permute and pass to the next
		{
			int x = 0; // counter into the lines
			if (!found)
			{
				while (x < 4) // go through the line
				{
					result[x] = permutations[p][x]; // first compatible permute: save it as initial candidate
					x++; // increment to check compatibility of next permute
				}
				found = 1;
			}
			else
			{
				while (x < 4)
				{
					if (result[x] != permutations[p][x]) //permute not compatible
						result[x] = 0;    // mark as unknown "still don't know"
						x++; // increment to check compatibility of the next permute
				}
			}
			p++;
			// at the end of these whiles, result will only have values != zero in the position where all compatible permutes agreed
			if (found)
			{
			        int x = 0; // counter into the line
			        while (x < 4)
			        {
					if (result[x] != 0 && line[x] != result[x]) // only counts as changed if its a new value
					line[x] = result[x]; // only update positions that we know the correct building, the unknow are left 0
					changed = 1;
					x++; // increment the counter
				}
				set_line(grid, i, j, line); // write the line updated back to the grid
			}
		}

void second_pass(int grid[4][4], int arr[4][4])
{
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			if (arr[i][j] == 2 || arr[i][j] == 3) // now the clues == to 2 or 3
			solve_23(grid, i, j, arr[i][j]); // call the function solve_23 to check deduzir the possible max to that line
			j++; // increment position into the line
		}
		i++; // increment the line
	}
}



