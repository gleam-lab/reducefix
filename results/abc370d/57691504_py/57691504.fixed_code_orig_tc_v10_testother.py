import sys
from collections import defaultdict

def main():
    H, W, Q = map(int, sys.stdin.readline().split())
    
    # Use dictionaries to store next wall positions for each row and column
    # For rows: left_wall[r][c] = next wall to the left of c in row r
    # For rows: right_wall[r][c] = next wall to the right of c in row r
    # For columns: up_wall[c][r] = next wall above r in column c
    # For columns: down_wall[c][r] = next wall below r in column c
    
    # Initialize with all walls present
    total_walls = H * W
    
    # For each row, maintain left and right boundaries
    left_bound = [defaultdict(lambda: 0) for _ in range(H + 1)]
    right_bound = [defaultdict(lambda: W + 1) for _ in range(H + 1)]
    
    # For each column, maintain up and down boundaries
    up_bound = [defaultdict(lambda: 0) for _ in range(W + 1)]
    down_bound = [defaultdict(lambda: H + 1) for _ in range(W + 1)]
    
    # Initialize boundaries - initially every cell has a wall
    for r in range(1, H + 1):
        left_bound[r][W + 1] = 0
        right_bound[r][0] = W + 1
        
    for c in range(1, W + 1):
        up_bound[c][H + 1] = 0
        down_bound[c][0] = H + 1
    
    def find_next_left(row, col):
        """Find the next wall to the left of (row, col)"""
        if col <= 1:
            return 0
        pos = col - 1
        while pos > 0 and pos in left_bound[row] and left_bound[row][pos] != pos:
            pos = left_bound[row][pos]
        return pos
    
    def find_next_right(row, col):
        """Find the next wall to the right of (row, col)"""
        if col >= W:
            return W + 1
        pos = col + 1
        while pos <= W and pos in right_bound[row] and right_bound[row][pos] != pos:
            pos = right_bound[row][pos]
        return pos
    
    def find_next_up(col, row):
        """Find the next wall above (row, col)"""
        if row <= 1:
            return 0
        pos = row - 1
        while pos > 0 and pos in up_bound[col] and up_bound[col][pos] != pos:
            pos = up_bound[col][pos]
        return pos
    
    def find_next_down(col, row):
        """Find the next wall below (row, col)"""
        if row >= H:
            return H + 1
        pos = row + 1
        while pos <= H and pos in down_bound[col] and down_bound[col][pos] != pos:
            pos = down_bound[col][pos]
        return pos
    
    for _ in range(Q):
        R_q, C_q = map(int, sys.stdin.readline().split())
        
        # Check if there's a wall at (R_q, C_q)
        # A wall exists if it hasn't been destroyed
        # We can check this by seeing if the position is reachable from boundaries
        
        has_wall = True
        
        # Check if we can reach this cell from any direction
        # If there's no direct path from boundary to this cell, wall exists
        left_cell = find_next_right(R_q, find_next_left(R_q, C_q))
        if left_cell == C_q:
            has_wall = False
            
        right_cell = find_next_left(R_q, find_next_right(R_q, C_q))
        if right_cell == C_q:
            has_wall = False
            
        up_cell = find_next_down(C_q, find_next_up(C_q, R_q))
        if up_cell == R_q:
            has_wall = False
            
        down_cell = find_next_up(C_q, find_next_down(C_q, R_q))
        if down_cell == R_q:
            has_wall = False
        
        if has_wall:
            # Destroy the wall at (R_q, C_q)
            total_walls -= 1
            
            # Update boundaries - merge segments
            left_neighbor = find_next_left(R_q, C_q)
            right_neighbor = find_next_right(R_q, C_q)
            up_neighbor = find_next_up(C_q, R_q)
            down_neighbor = find_next_down(C_q, R_q)
            
            # Update row R_q: connect left and right segments
            if left_neighbor > 0:
                right_bound[R_q][left_neighbor] = right_neighbor
            if right_neighbor <= W:
                left_bound[R_q][right_neighbor] = left_neighbor
                
            # Update column C_q: connect up and down segments  
            if up_neighbor > 0:
                down_bound[C_q][up_neighbor] = down_neighbor
            if down_neighbor <= H:
                up_bound[C_q][down_neighbor] = up_neighbor
                
        else:
            # No wall at (R_q, C_q), destroy first walls in each direction
            walls_destroyed = 0
            
            # Up direction
            up_wall = find_next_up(C_q, R_q)
            if up_wall > 0:
                # Verify there are no walls between up_wall and R_q
                next_down_from_up = find_next_down(C_q, up_wall)
                if next_down_from_up == R_q:
                    # Clear path, destroy the wall
                    total_walls -= 1
                    walls_destroyed += 1
                    
                    # Update column C_q boundaries
                    down_from_up = find_next_down(C_q, up_wall)
                    up_from_up = find_next_up(C_q, up_wall)
                    
                    if up_from_up > 0:
                        down_bound[C_q][up_from_up] = down_from_up
                    if down_from_up <= H:
                        up_bound[C_q][down_from_up] = up_from_up
            
            # Down direction
            down_wall = find_next_down(C_q, R_q)
            if down_wall <= H:
                next_up_from_down = find_next_up(C_q, down_wall)
                if next_up_from_down == R_q:
                    total_walls -= 1
                    walls_destroyed += 1
                    
                    down_from_down = find_next_down(C_q, down_wall)
                    up_from_down = find_next_up(C_q, down_wall)
                    
                    if up_from_down > 0:
                        down_bound[C_q][up_from_down] = down_from_down
                    if down_from_down <= H:
                        up_bound[C_q][down_from_down] = up_from_down
            
            # Left direction
            left_wall = find_next_left(R_q, C_q)
            if left_wall > 0:
                next_right_from_left = find_next_right(R_q, left_wall)
                if next_right_from_left == C_q:
                    total_walls -= 1
                    walls_destroyed += 1
                    
                    right_from_left = find_next_right(R_q, left_wall)
                    left_from_left = find_next_left(R_q, left_wall)
                    
                    if left_from_left > 0:
                        right_bound[R_q][left_from_left] = right_from_left
                    if right_from_left <= W:
                        left_bound[R_q][right_from_left] = left_from_left
            
            # Right direction
            right_wall = find_next_right(R_q, C_q)
            if right_wall <= W:
                next_left_from_right = find_next_left(R_q, right_wall)
                if next_left_from_right == C_q:
                    total_walls -= 1
                    walls_destroyed += 1
                    
                    right_from_right = find_next_right(R_q, right_wall)
                    left_from_right = find_next_left(R_q, right_wall)
                    
                    if left_from_right > 0:
                        right_bound[R_q][left_from_right] = right_from_right
                    if right_from_right <= W:
                        left_bound[R_q][right_from_right] = left_from_right
    
    print(total_walls)

if __name__ == "__main__":
    main()