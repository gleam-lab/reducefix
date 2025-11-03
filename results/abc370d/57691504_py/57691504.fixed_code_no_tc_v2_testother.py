import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().split()
    H = int(data[0])
    W = int(data[1])
    Q = int(data[2])
    
    # Union-Find like structure for each row and column to track next existing wall
    # For each row, we maintain left and right nearest walls
    # For each column, we maintain up and down nearest walls
    row_left = [list(range(W+1)) for _ in range(H+1)]  # row_left[r][c] = the closest column <= c that has a wall
    row_right = [list(range(W+1)) for _ in range(H+1)] # row_right[r][c] = the closest column >= c that has a wall
    col_up = [list(range(H+1)) for _ in range(W+1)]    # col_up[c][r] = the closest row <= r that has a wall
    col_down = [list(range(H+1)) for _ in range(W+1)]  # col_down[c][r] = the closest row >= r that has a wall
    
    # Initialize: initially every cell has a wall
    for r in range(1, H+1):
        for c in range(1, W+1):
            row_left[r][c] = c
            row_right[r][c] = c
            col_up[c][r] = r
            col_down[c][r] = r
    
    def find_row_left(r, c):
        if row_left[r][c] != c:
            row_left[r][c] = find_row_left(r, row_left[r][c])
        return row_left[r][c]
    
    def find_row_right(r, c):
        if row_right[r][c] != c:
            row_right[r][c] = find_row_right(r, row_right[r][c])
        return row_right[r][c]
    
    def find_col_up(c, r):
        if col_up[c][r] != r:
            col_up[c][r] = find_col_up(c, col_up[c][r])
        return col_up[c][r]
    
    def find_col_down(c, r):
        if col_down[c][r] != r:
            col_down[c][r] = find_col_down(c, col_down[c][r])
        return col_down[c][r]
    
    total_walls = H * W
    idx = 3
    
    for _ in range(Q):
        R_q = int(data[idx])
        C_q = int(data[idx + 1])
        idx += 2
        
        # Check if there's a wall at (R_q, C_q)
        # If the representative of C_q in row R_q is C_q itself, then wall exists
        if find_row_left(R_q, C_q) == C_q and find_row_right(R_q, C_q) == C_q:
            # Wall exists at (R_q, C_q), destroy it
            total_walls -= 1
            
            # Update row R_q: merge C_q with neighbors
            left_neighbor = find_row_left(R_q, C_q - 1)
            right_neighbor = find_row_right(R_q, C_q + 1)
            
            # Pointers should skip C_q now
            row_left[R_q][C_q] = left_neighbor
            row_right[R_q][C_q] = right_neighbor
            
            # Update the boundaries so they point around C_q
            if left_neighbor >= 1:
                row_right[R_q][left_neighbor] = right_neighbor
            if right_neighbor <= W:
                row_left[R_q][right_neighbor] = left_neighbor
            
            # Update column C_q similarly
            up_neighbor = find_col_up(C_q, R_q - 1)
            down_neighbor = find_col_down(C_q, R_q + 1)
            
            col_up[C_q][R_q] = up_neighbor
            col_down[C_q][R_q] = down_neighbor
            
            if up_neighbor >= 1:
                col_down[C_q][up_neighbor] = down_neighbor
            if down_neighbor <= H:
                col_up[C_q][down_neighbor] = up_neighbor
        else:
            # No wall at (R_q, C_q), check four directions
            destroyed = set()
            
            # Up direction: find the first wall above R_q in column C_q
            r_up = find_col_up(C_q, R_q - 1)
            if r_up >= 1 and r_up < R_q:
                # Check if path is clear (no walls between r_up and R_q)
                if find_col_down(C_q, r_up + 1) == R_q:
                    destroyed.add((r_up, C_q))
            
            # Down direction: find the first wall below R_q in column C_q
            r_down = find_col_down(C_q, R_q + 1)
            if r_down <= H and r_down > R_q:
                if find_col_up(C_q, r_down - 1) == R_q:
                    destroyed.add((r_down, C_q))
            
            # Left direction: find the first wall to the left of C_q in row R_q
            c_left = find_row_left(R_q, C_q - 1)
            if c_left >= 1 and c_left < C_q:
                if find_row_right(R_q, c_left + 1) == C_q:
                    destroyed.add((R_q, c_left))
            
            # Right direction: find the first wall to the right of C_q in row R_q
            c_right = find_row_right(R_q, C_q + 1)
            if c_right <= W and c_right > C_q:
                if find_row_left(R_q, c_right - 1) == C_q:
                    destroyed.add((R_q, c_right))
            
            # Destroy all valid walls found
            for r, c in destroyed:
                # Only destroy if still exists (avoid double counting)
                if (find_row_left(r, c) == c and find_row_right(r, c) == c and
                    find_col_up(c, r) == r and find_col_down(c, r) == r):
                    total_walls -= 1
                    
                    # Update row r
                    left_neighbor = find_row_left(r, c - 1)
                    right_neighbor = find_row_right(r, c + 1)
                    
                    row_left[r][c] = left_neighbor
                    row_right[r][c] = right_neighbor
                    
                    if left_neighbor >= 1:
                        row_right[r][left_neighbor] = right_neighbor
                    if right_neighbor <= W:
                        row_left[r][right_neighbor] = left_neighbor
                    
                    # Update column c
                    up_neighbor = find_col_up(c, r - 1)
                    down_neighbor = find_col_down(c, r + 1)
                    
                    col_up[c][r] = up_neighbor
                    col_down[c][r] = down_neighbor
                    
                    if up_neighbor >= 1:
                        col_down[c][up_neighbor] = down_neighbor
                    if down_neighbor <= H:
                        col_up[c][down_neighbor] = up_neighbor
    
    print(total_walls)

if __name__ == "__main__":
    main()