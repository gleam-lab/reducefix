import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().split()
    if not data:
        print(0)
        return
    
    H = int(data[0]); W = int(data[1]); Q = int(data[2])
    total_walls = H * W
    
    # For each row, maintain left and right next walls
    next_left = [list(range(W+1)) for _ in range(H+1)]  # next_left[r][c] = next existing wall to the left in row r
    next_right = [list(range(W+1)) for _ in range(H+1)] # next_right[r][c] = next existing wall to the right in row r
    
    # For each column, maintain up and down next walls
    next_up = [list(range(H+1)) for _ in range(W+1)]    # next_up[c][r] = next existing wall above in column c
    next_down = [list(range(H+1)) for _ in range(W+1)]  # next_down[c][r] = next existing wall below in column c
    
    def find_left(r, c):
        if c < 0 or c > W:
            return -1
        if next_left[r][c] != c:
            next_left[r][c] = find_left(r, next_left[r][c])
        return next_left[r][c]
    
    def find_right(r, c):
        if c < 0 or c > W:
            return W+1
        if next_right[r][c] != c:
            next_right[r][c] = find_right(r, next_right[r][c])
        return next_right[r][c]
    
    def find_up(c, r):
        if r < 0 or r > H:
            return -1
        if next_up[c][r] != r:
            next_up[c][r] = find_up(c, next_up[c][r])
        return next_up[c][r]
    
    def find_down(c, r):
        if r < 0 or r > H:
            return H+1
        if next_down[c][r] != r:
            next_down[c][r] = find_down(c, next_down[c][r])
        return next_down[c][r]
    
    index = 3
    for _ in range(Q):
        R_q = int(data[index]); C_q = int(data[index+1]); index += 2
        
        # Check if there's a wall at (R_q, C_q)
        # In our DS, if find_left(R_q, C_q) == C_q, then wall exists
        has_wall = (find_left(R_q, C_q) == C_q)
        
        if has_wall:
            # Destroy the wall at (R_q, C_q)
            total_walls -= 1
            
            # Update the DS: merge with left and right in row
            left_neighbor = find_left(R_q, C_q - 1)
            right_neighbor = find_right(R_q, C_q + 1)
            if left_neighbor >= 1:
                next_right[R_q][C_q] = right_neighbor
            if right_neighbor <= W:
                next_left[R_q][right_neighbor] = left_neighbor
                next_left[R_q][C_q] = left_neighbor  # path compression
            
            # Update the DS: merge with up and down in column
            up_neighbor = find_up(C_q, R_q - 1)
            down_neighbor = find_down(C_q, R_q + 1)
            if up_neighbor >= 1:
                next_down[C_q][R_q] = down_neighbor
            if down_neighbor <= H:
                next_up[C_q][down_neighbor] = up_neighbor
                next_up[C_q][R_q] = up_neighbor  # path compression
                
        else:
            # No wall at (R_q, C_q), so try to destroy first wall in each direction
            destroyed = set()
            
            # Up direction: find first wall above R_q in column C_q
            wall_up = find_up(C_q, R_q - 1)
            if wall_up >= 1:
                # Check if no wall between wall_up and R_q (which is guaranteed by union-find)
                # But we need to ensure it's the immediate one, which our DS provides
                destroyed.add((wall_up, C_q))
            
            # Down direction: find first wall below R_q in column C_q
            wall_down = find_down(C_q, R_q + 1)
            if wall_down <= H:
                destroyed.add((wall_down, C_q))
            
            # Left direction: find first wall left of C_q in row R_q
            wall_left = find_left(R_q, C_q - 1)
            if wall_left >= 1:
                destroyed.add((R_q, wall_left))
            
            # Right direction: find first wall right of C_q in row R_q
            wall_right = find_right(R_q, C_q + 1)
            if wall_right <= W:
                destroyed.add((R_q, wall_right))
            
            # Destroy all unique walls found
            total_walls -= len(destroyed)
            
            # Update the data structures for each destroyed wall
            for r, c in destroyed:
                # Update row r
                left_neighbor = find_left(r, c - 1)
                right_neighbor = find_right(r, c + 1)
                if left_neighbor >= 1:
                    next_right[r][c] = right_neighbor
                if right_neighbor <= W:
                    next_left[r][right_neighbor] = left_neighbor
                    next_left[r][c] = left_neighbor
                
                # Update column c
                up_neighbor = find_up(c, r - 1)
                down_neighbor = find_down(c, r + 1)
                if up_neighbor >= 1:
                    next_down[c][r] = down_neighbor
                if down_neighbor <= H:
                    next_up[c][down_neighbor] = up_neighbor
                    next_up[c][r] = up_neighbor
    
    print(total_walls)

if __name__ == "__main__":
    main()