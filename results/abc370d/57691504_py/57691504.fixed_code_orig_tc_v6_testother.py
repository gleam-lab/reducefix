import sys
from typing import Dict, Tuple

def main():
    H, W, Q = map(int, sys.stdin.readline().split())
    
    # Use dictionaries to store next wall positions for each row and column
    # For each row, store the next wall to the left and right
    left_wall: Dict[int, Dict[int, int]] = {}
    right_wall: Dict[int, Dict[int, int]] = {}
    
    # For each column, store the next wall above and below
    up_wall: Dict[int, Dict[int, int]] = {}
    down_wall: Dict[int, Dict[int, int]] = {}
    
    # Initialize data structures
    for r in range(1, H + 1):
        left_wall[r] = {}
        right_wall[r] = {}
    
    for c in range(1, W + 1):
        up_wall[c] = {}
        down_wall[c] = {}
    
    # Union-Find style path compression functions
    def find_left(r: int, c: int) -> int:
        if c <= 0:
            return 0
        if c not in left_wall[r]:
            return c
        left_wall[r][c] = find_left(r, left_wall[r][c])
        return left_wall[r][c]
    
    def find_right(r: int, c: int) -> int:
        if c > W:
            return W + 1
        if c not in right_wall[r]:
            return c
        right_wall[r][c] = find_right(r, right_wall[r][c])
        return right_wall[r][c]
    
    def find_up(c: int, r: int) -> int:
        if r <= 0:
            return 0
        if r not in up_wall[c]:
            return r
        up_wall[c][r] = find_up(c, up_wall[c][r])
        return up_wall[c][r]
    
    def find_down(c: int, r: int) -> int:
        if r > H:
            return H + 1
        if r not in down_wall[c]:
            return r
        down_wall[c][r] = find_down(c, down_wall[c][r])
        return down_wall[c][r]
    
    total_walls = H * W
    
    for _ in range(Q):
        R_q, C_q = map(int, sys.stdin.readline().split())
        
        # Check if there's a wall at (R_q, C_q)
        # A wall exists if it hasn't been destroyed (i.e., not in the union-find structure)
        up_pos = find_up(C_q, R_q)
        if up_pos == R_q:
            # Wall exists at (R_q, C_q), destroy it
            total_walls -= 1
            
            # Update the connectivity structures
            # Connect this position to adjacent positions
            up_wall[C_q][R_q] = find_up(C_q, R_q - 1)
            down_wall[C_q][R_q] = find_down(C_q, R_q + 1)
            left_wall[R_q][C_q] = find_left(R_q, C_q - 1)
            right_wall[R_q][C_q] = find_right(R_q, C_q + 1)
        else:
            # No wall at (R_q, C_q), destroy first walls in each direction
            destroyed = 0
            
            # Look up
            up_target = find_up(C_q, R_q - 1)
            if up_target > 0 and up_target == R_q - 1:
                total_walls -= 1
                up_wall[C_q][up_target] = find_up(C_q, up_target - 1)
                down_wall[C_q][up_target] = find_down(C_q, up_target + 1)
                left_wall[up_target][C_q] = find_left(up_target, C_q - 1)
                right_wall[up_target][C_q] = find_right(up_target, C_q + 1)
                destroyed += 1
            
            # Look down
            down_target = find_down(C_q, R_q + 1)
            if down_target <= H and down_target == R_q + 1:
                # Avoid double counting if same cell is targeted from multiple directions
                if down_target != up_target:
                    total_walls -= 1
                    up_wall[C_q][down_target] = find_up(C_q, down_target - 1)
                    down_wall[C_q][down_target] = find_down(C_q, down_target + 1)
                    left_wall[down_target][C_q] = find_left(down_target, C_q - 1)
                    right_wall[down_target][C_q] = find_right(down_target, C_q + 1)
                    destroyed += 1
            
            # Look left
            left_target = find_left(R_q, C_q - 1)
            if left_target > 0 and left_target == C_q - 1:
                # Check if this cell was already destroyed by vertical blast
                if (left_target != up_target or C_q != C_q) and (left_target != down_target or C_q != C_q):
                    total_walls -= 1
                    up_wall[left_target][R_q] = find_up(left_target, R_q - 1)
                    down_wall[left_target][R_q] = find_down(left_target, R_q + 1)
                    left_wall[R_q][left_target] = find_left(R_q, left_target - 1)
                    right_wall[R_q][left_target] = find_right(R_q, left_target + 1)
                    destroyed += 1
            
            # Look right
            right_target = find_right(R_q, C_q + 1)
            if right_target <= W and right_target == C_q + 1:
                # Check if this cell was already destroyed
                valid = True
                if right_target == up_target and C_q + 1 == C_q:
                    valid = False
                if right_target == down_target and C_q + 1 == C_q:
                    valid = False
                if right_target == left_target and R_q == R_q:
                    valid = False
                
                if valid:
                    total_walls -= 1
                    up_wall[right_target][R_q] = find_up(right_target, R_q - 1)
                    down_wall[right_target][R_q] = find_down(right_target, R_q + 1)
                    left_wall[R_q][right_target] = find_left(R_q, right_target - 1)
                    right_wall[R_q][right_target] = find_right(R_q, right_target + 1)
                    destroyed += 1
    
    print(total_walls)

if __name__ == "__main__":
    main()