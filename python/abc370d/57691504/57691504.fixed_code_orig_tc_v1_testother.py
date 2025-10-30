import sys
from collections import defaultdict

def main():
    H, W, Q = map(int, input().split())
    
    # Use dictionaries to track the next wall in each direction
    # For each row, maintain left and right neighbors
    row_left = [dict() for _ in range(H+1)]  # row_left[r][c] = next wall to the left of c in row r
    row_right = [dict() for _ in range(H+1)]  # row_right[r][c] = next wall to the right of c in row r
    
    # For each column, maintain up and down neighbors
    col_up = [dict() for _ in range(W+1)]     # col_up[c][r] = next wall above r in column c
    col_down = [dict() for _ in range(W+1)]   # col_down[c][r] = next wall below r in column c
    
    # Initialize: each cell has a wall, so neighbors are adjacent cells
    for r in range(1, H+1):
        for c in range(1, W+1):
            # In row r, cell (r,c) has left neighbor at c-1 and right at c+1
            if c > 1:
                row_left[r][c] = c - 1
            if c < W:
                row_right[r][c] = c + 1
                
    for c in range(1, W+1):
        for r in range(1, H+1):
            # In column c, cell (r,c) has up neighbor at r-1 and down at r+1
            if r > 1:
                col_up[c][r] = r - 1
            if r < H:
                col_down[c][r] = r + 1
    
    total_walls = H * W
    
    def find_next_in_row(r, c, is_left):
        """Find the next existing wall in the row r from position c in given direction"""
        current = c
        visited = set()
        
        while current in (row_left[r] if is_left else row_right[r]):
            if current in visited:
                break
            visited.add(current)
            current = (row_left[r] if is_left else row_right[r])[current]
            
        return current if current >= 1 and current <= W else None
    
    def find_next_in_col(c, r, is_up):
        """Find the next existing wall in the column c from position r in given direction"""
        current = r
        visited = set()
        
        while current in (col_up[c] if is_up else col_down[c]):
            if current in visited:
                break
            visited.add(current)
            current = (col_up[c] if is_up else col_down[c])[current]
            
        return current if current >= 1 and current <= H else None
    
    def remove_wall(r, c):
        nonlocal total_walls
        if total_walls <= 0:
            return
            
        total_walls -= 1
        
        # Update horizontal links
        left_neighbor = row_left[r].get(c)
        right_neighbor = row_right[r].get(c)
        
        if left_neighbor is not None:
            row_right[r][left_neighbor] = right_neighbor
        if right_neighbor is not None:
            row_left[r][right_neighbor] = left_neighbor
            
        # Remove the wall from row dictionaries
        if c in row_left[r]:
            del row_left[r][c]
        if c in row_right[r]:
            del row_right[r][c]
            
        # Update vertical links
        up_neighbor = col_up[c].get(r)
        down_neighbor = col_down[c].get(r)
        
        if up_neighbor is not None:
            col_down[c][up_neighbor] = down_neighbor
        if down_neighbor is not None:
            col_up[c][down_neighbor] = up_neighbor
            
        # Remove the wall from column dictionaries
        if r in col_up[c]:
            del col_up[c][r]
        if r in col_down[c]:
            del col_down[c][r]
    
    for _ in range(Q):
        R_q, C_q = map(int, input().split())
        
        # Check if there's a wall at (R_q, C_q)
        has_wall = (C_q in row_left[R_q] or C_q in row_right[R_q] or 
                   (C_q not in row_left[R_q] and C_q not in row_right[R_q] and 
                    (R_q in col_up[C_q] or R_q in col_down[C_q])))
        
        # Actually, simpler: if it has any neighbor or is within bounds and hasn't been removed
        # We can check if it still exists by seeing if it has any connections
        if (C_q in row_left[R_q] or C_q in row_right[R_q] or
            R_q in col_up[C_q] or R_q in col_down[C_q] or
            (R_q == 1 and R_q in col_down[C_q]) or (R_q == H and R_q in col_up[C_q]) or
            (C_q == 1 and C_q in row_right[R_q]) or (C_q == W and C_q in row_left[R_q])):
            
            # Wall exists, destroy it
            remove_wall(R_q, C_q)
        else:
            # No wall at (R_q, C_q), destroy first walls in four directions
            destroyed = set()
            
            # Up
            r_up = find_next_in_col(C_q, R_q, True)
            if r_up is not None and r_up < R_q:
                destroyed.add((r_up, C_q))
                
            # Down  
            r_down = find_next_in_col(C_q, R_q, False)
            if r_down is not None and r_down > R_q:
                destroyed.add((r_down, C_q))
                
            # Left
            c_left = find_next_in_row(R_q, C_q, True)
            if c_left is not None and c_left < C_q:
                destroyed.add((R_q, c_left))
                
            # Right
            c_right = find_next_in_row(R_q, C_q, False)
            if c_right is not None and c_right > C_q:
                destroyed.add((R_q, c_right))
            
            # Remove all destroyed walls
            for r, c in destroyed:
                remove_wall(r, c)
    
    print(total_walls)

if __name__ == "__main__":
    main()