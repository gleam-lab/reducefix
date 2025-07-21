Initialize a grid of size N x N with all cells empty.
For each piece (a, b):
    For each possible move from (a, b):
        If the move is within bounds and the cell is not occupied:
            Mark the cell as captured.
For each empty cell in the grid:
    If the cell is not marked as captured:
        Increment the count of safe cells.
Output the count of safe cells.