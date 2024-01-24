#!/usr/bin/python3

"""
This module contains the function island_perimeter that
returns the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Parameters:
    - grid (list): A list of lists of integers where:
        - 0 represents a water zone.
        - 1 represents a land zone.
        - One cell is a square with side length 1.
        - Grid cells are connected horizontally/vertically (not diagonally).
        - The grid is rectangular with width and height not exceeding 100.
        - The grid is completely surrounded by water,
            and there is one island (or nothing)
        - The island doesn't have lakes
            (water inside that isn't connected to the water around the island).
    """

    length = 0
    width = 0
    temp = 0

    for row in grid:
        if 1 in row:
            length += 1
        for cell in row:
            if cell == 1:
                temp += 1
        if temp > width:
            width = temp
        temp = 0

    perimeter = 2 * (length + width)
    return perimeter
