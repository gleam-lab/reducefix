import sys
from typing import Dict, List

def main():
    data = sys.stdin.read().split()
    if not data:
        print(0)
        return
    
    H = int(data[0])
    W = int(data[1])
    Q = int(data[2])
    total_walls = H * W
    
    # For each column c, maintain union-find style pointers for vertical directions
    # next_up[c][r] points to the next existing wall above row r in column c
    # next_down[c][r] points to the next existing wall below row r in column c
    next_up: Dict[int, Dict[int, int]] = {}
    next_down: Dict[int, Dict[int, int]] = {}
    
    # For each row r, maintain union-find style pointers for horizontal directions
    # next_left[r][c] points to the next existing wall to the left of column c in row r
    # next_right[r][c] points to the next existing wall to the right of column c in row r
    next_left: Dict[int, Dict[int, int]] = {}
    next_right: Dict[int, Dict[int, int]] = {}
    
    # Initialize structures
    for c in range(1, W + 1):
        next_up[c] = {}
        next_down[c] = {}
        
    for r in range(1, H + 1):
        next_left[r] = {}
        next_right[r] = {}
    
    def find_up(c: int, r: int) -> int:
        if r <= 0:
            return 0
        if r not in next_up[c]:
            return r
        next_up[c][r] = find_up(c, next_up[c][r])
        return next_up[c][r]
    
    def find_down(c: int, r: int) -> int:
        if r > H:
            return H + 1
        if r not in next_down[c]:
            return r
        next_down[c][r] = find_down(c, next_down[c][r])
        return next_down[c][r]
    
    def find_left(r: int, c: int) -> int:
        if c <= 0:
            return 0
        if c not in next_left[r]:
            return c
        next_left[r][c] = find_left(r, next_left[r][c])
        return next_left[r][c]
    
    def find_right(r: int, c: int) -> int:
        if c > W:
            return W + 1
        if c not in next_right[r]:
            return c
        next_right[r][c] = find_right(r, next_right[r][c])
        return next_right[r][c]
    
    index = 3
    for _ in range(Q):
        R_q = int(data[index])
        C_q = int(data[index + 1])
        index += 2
        
        # Check if there's a wall at (R_q, C_q)
        # Use up pointer to check existence
        pos_up = find_up(C_q, R_q)
        
        if pos_up == R_q:
            # Wall exists at (R_q, C_q), destroy it
            total_walls -= 1
            
            # Update pointers: this cell now has no wall
            # Link above and below in column C_q
            up_neighbor = find_up(C_q, R_q - 1)
            down_neighbor = find_down(C_q, R_q + 1)
            next_up[C_q][R_q] = up_neighbor
            next_down[C_q][R_q] = down_neighbor
            
            # Link left and right in row R_q
            left_neighbor = find_left(R_q, C_q - 1)
            right_neighbor = find_right(R_q, C_q + 1)
            next_left[R_q][C_q] = left_neighbor
            next_right[R_q][C_q] = right_neighbor
        else:
            # No wall at (R_q, C_q), so try to destroy first walls in each direction
            destroyed = set()
            
            # Up direction: find the first wall above R_q in column C_q
            up_wall = find_up(C_q, R_q - 1)
            if up_wall >= 1 and up_wall < R_q:
                # Check if path is clear (i.e., up_wall is adjacent or all between are gone)
                # We need to verify that there's no wall between up_wall and R_q
                # But our union-find ensures that if up_wall is returned, then all between are gone
                # So we can destroy it if it's reachable
                next_in_col = find_down(C_q, up_wall + 1)
                if next_in_col > R_q:  # No wall between up_wall and R_q
                    destroyed.add((up_wall, C_q))
            
            # Down direction: find the first wall below R_q in column C_q
            down_wall = find_down(C_q, R_q + 1)
            if down_wall <= H and down_wall > R_q:
                next_in_col = find_up(C_q, down_wall - 1)
                if next_in_col < R_q:  # No wall between R_q and down_wall
                    destroyed.add((down_wall, C_q))
            
            # Left direction: find the first wall to the left of C_q in row R_q
            left_wall = find_left(R_q, C_q - 1)
            if left_wall >= 1 and left_wall < C_q:
                next_in_row = find_right(R_q, left_wall + 1)
                if next_in_row > C_q:  # No wall between left_wall and C_q
                    destroyed.add((R_q, left_wall))
            
            # Right direction: find the first wall to the right of C_q in row R_q
            right_wall = find_right(R_q, C_q + 1)
            if right_wall <= W and right_wall > C_q:
                next_in_row = find_left(R_q, right_wall - 1)
                if next_in_row < C_q:  # No wall between C_q and right_wall
                    destroyed.add((R_q, right_wall))
            
            # Destroy all valid walls
            for r, c in destroyed:
                total_walls -= 1
                
                # Update the union-find structures
                # Column c
                up_neighbor = find_up(c, r - 1)
                down_neighbor = find_down(c, r + 1)
                next_up[c][r] = up_neighbor
                next_down[c][r] = down_neighbor
                
                # Row r
                left_neighbor = find_left(r, c - 1)
                right_neighbor = find_right(r, c + 1)
                next_left[r][c] = left_neighbor
                next_right[r][c] = right_neighbor
    
    print(total_walls)

if __name__ == "__main__":
    main()