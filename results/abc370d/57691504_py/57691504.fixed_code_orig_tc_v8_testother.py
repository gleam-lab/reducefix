import sys
from collections import defaultdict

def main():
    H, W, Q = map(int, sys.stdin.readline().split())
    
    # Initialize data structures to keep track of next existing wall in each direction
    # For each row, maintain left and right walls using sets or linked lists
    # For each column, maintain up and down walls similarly
    
    # Use dictionaries to store the next existing wall in each direction
    # row_left[r][c] = the next column to the left that has a wall (or 0 if none)
    # row_right[r][c] = the next column to the right that has a wall (or W+1 if none)
    # col_up[c][r] = the next row above that has a wall (or 0 if none)
    # col_down[c][r] = the next row below that has a wall (or H+1 if none)
    
    # Instead, use union-find like approach with dictionaries for each row and column
    row_next_left = [dict() for _ in range(H + 1)]
    row_next_right = [dict() for _ in range(H + 1)]
    col_next_up = [dict() for _ in range(W + 1)]
    col_next_down = [dict() for _ in range(W + 1)]
    
    # Initially, all cells have walls
    total_walls = H * W
    
    # Helper functions to find the next existing wall
    def find_next_left(row, col):
        if col <= 1:
            return 0
        if col not in row_next_left[row]:
            return col - 1
        if row_next_left[row][col] == col - 1:
            return col - 1
        row_next_left[row][col] = find_next_left(row, row_next_left[row][col])
        return row_next_left[row][col]
    
    def find_next_right(row, col):
        if col >= W:
            return W + 1
        if col not in row_next_right[row]:
            return col + 1
        if row_next_right[row][col] == col + 1:
            return col + 1
        row_next_right[row][col] = find_next_right(row, row_next_right[row][col])
        return row_next_right[row][col]
    
    def find_next_up(col, row):
        if row <= 1:
            return 0
        if row not in col_next_up[col]:
            return row - 1
        if col_next_up[col][row] == row - 1:
            return row - 1
        col_next_up[col][row] = find_next_up(col, col_next_up[col][row])
        return col_next_up[col][row]
    
    def find_next_down(col, row):
        if row >= H:
            return H + 1
        if row not in col_next_down[col]:
            return row + 1
        if col_next_down[col][row] == row + 1:
            return row + 1
        col_next_down[col][row] = find_next_down(col, col_next_down[col][row])
        return col_next_down[col][row]
    
    # Process each query
    for _ in range(Q):
        R, C = map(int, sys.stdin.readline().split())
        
        # Check if there's a wall at (R, C)
        # Look for adjacent walls to determine if (R,C) is intact
        left = find_next_right(R, C - 1) if C > 1 else 0
        right = find_next_left(R, C + 1) if C < W else W + 1
        up = find_next_down(C, R - 1) if R > 1 else 0
        down = find_next_up(C, R + 1) if R < H else H + 1
        
        has_wall_at_rc = (left == C or right == C or up == R or down == R)
        
        if has_wall_at_rc:
            # Destroy the wall at (R, C)
            total_walls -= 1
            
            # Update the neighbor pointers
            # For row R: connect left and right neighbors
            if C > 1:
                row_next_right[R][C] = find_next_right(R, C - 1)
            if C < W:
                row_next_left[R][C] = find_next_left(R, C + 1)
            
            # For column C: connect up and down neighbors  
            if R > 1:
                col_next_down[C][R] = find_next_down(C, R - 1)
            if R < H:
                col_next_up[C][R] = find_next_up(C, R + 1)
                
        else:
            # No wall at (R, C), destroy first walls in each direction
            destroyed = 0
            
            # Up direction
            r_up = find_next_up(C, R - 1)
            if r_up > 0:
                # Verify path is clear (no walls between r_up and R)
                next_below = find_next_down(C, r_up + 1)
                if next_below == R:
                    total_walls -= 1
                    destroyed += 1
                    # Update column C connections
                    if r_up > 1:
                        col_next_down[C][r_up] = find_next_down(C, r_up - 1)
                    if r_up < H:
                        col_next_up[C][r_up] = find_next_up(C, r_up + 1)
            
            # Down direction
            r_down = find_next_down(C, R + 1)
            if r_down <= H:
                # Verify path is clear
                next_above = find_next_up(C, r_down - 1)
                if next_above == R:
                    total_walls -= 1
                    destroyed += 1
                    # Update column C connections
                    if r_down > 1:
                        col_next_down[C][r_down] = find_next_down(C, r_down - 1)
                    if r_down < H:
                        col_next_up[C][r_down] = find_next_up(C, r_down + 1)
            
            # Left direction
            c_left = find_next_left(R, C - 1)
            if c_left > 0:
                # Verify path is clear
                next_right = find_next_right(R, c_left + 1)
                if next_right == C:
                    total_walls -= 1
                    destroyed += 1
                    # Update row R connections
                    if c_left > 1:
                        row_next_right[R][c_left] = find_next_right(R, c_left - 1)
                    if c_left < W:
                        row_next_left[R][c_left] = find_next_left(R, c_left + 1)
            
            # Right direction
            c_right = find_next_right(R, C + 1)
            if c_right <= W:
                # Verify path is clear
                next_left = find_next_left(R, c_right - 1)
                if next_left == C:
                    total_walls -= 1
                    destroyed += 1
                    # Update row R connections
                    if c_right > 1:
                        row_next_right[R][c_right] = find_next_right(R, c_right - 1)
                    if c_right < W:
                        row_next_left[R][c_right] = find_next_left(R, c_right + 1)
    
    print(total_walls)

if __name__ == "__main__":
    main()