#!/usr/bin/python3
"""
5-island_perimeter.py

Contains a function that returns the perimeter of the island described in grid
grid is a list of list of integers:
    0 represents a water zone
    1 represents a land zone
    One cell is a square with side length 1
    Grid cells are connected horizontally/vertically (not diagonally).
    Grid is rectangular, width and height don’t exceed 100
Grid is completely surrounded by water, and there is one island (or nothing).
The island doesn’t have “lakes” (water inside that isn’t connected to the water
around the island).
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid
    """
    grid_size_y = len(grid)
    grid_size_x = len(grid[0])
    perimeter = 0
    for i in range(grid_size_y):
        for j in range(grid_size_x):
            if grid[i][j] == 1:
                perimeter += 4
                if (j + 1) < grid_size_x and grid[i][j+1] == 1:
                    perimeter -= 1
                if j != 0 and grid[i][j-1] == 1:
                    perimeter -= 1
                if (i + 1) < grid_size_y and grid[i+1][j] == 1:
                    perimeter -= 1
                if i != 0 and grid[i-1][j] == 1:
                    perimeter -= 1
    return perimeter
