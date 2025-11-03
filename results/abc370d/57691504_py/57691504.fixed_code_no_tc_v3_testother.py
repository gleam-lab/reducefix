import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    H, W, Q = map(int, input().split())
    
    # Use union-find style dictionaries to track next existing wall in each direction
    # For each column c, up[c][r] points to the next row above r that has a wall (or None if none)
    # We'll use path compression for efficiency
    up = [dict() for _ in range(W + 1)]      # up[c][r] = next wall above row r in column c
    down = [dict() for _ in range(W + 1)]    # down[c][r] = next wall below row r in column c
    left = [dict() for _ in range(H + 1)]    # left[r][c] = next wall left of col c in row r
    right = [dict() for _ in range(H + 1)]   # right[r][c] = next wall right of col c in row r
    
    def find_up(c, r):
        if r <= 0:
            return 0
        if r not in up[c]:
            return r
        up[c][r] = find_up(c, up[c][r])
        return up[c][r]
    
    def find_down(c, r):
        if r > H:
            return H + 1
        if r not in down[c]:
            return r
        down[c][r] = find_down(c, down[c][r])
        return down[c][r]
    
    def find_left(r, c):
        if c <= 0:
            return 0
        if c not in left[r]:
            return c
        left[r][c] = find_left(r, left[r][c])
        return left[r][c]
    
    def find_right(r, c):
        if c > W:
            return W + 1
        if c not in right[r]:
            return c
        right[r][c] = find_right(r, right[r][c])
        return right[r][c]
    
    total_walls = H * W
    
    for _ in range(Q):
        R, C = map(int, input().split())
        
        # Check if there's a wall at (R, C)
        # A wall exists if we can "find" it from itself
        if find_up(C, R) == R and find_down(C, R) == R and find_left(R, C) == C and find_right(R, C) == C:
            # Wall exists at (R,C), destroy it
            total_walls -= 1
            
            # Update the pointers: connect neighbors around this destroyed wall
            up[C][R] = find_up(C, R - 1)
            down[C][R] = find_down(C, R + 1)
            left[R][C] = find_left(R, C - 1)
            right[R][C] = find_right(R, C + 1)
        else:
            # No wall at (R,C), try to destroy first wall in each direction
            destroyed = set()
            
            # Up direction: find first wall above R in column C
            u = find_up(C, R - 1)
            if u > 0 and u < R:
                # Verify there are no walls between u and R
                if find_down(C, u) == R:
                    destroyed.add((u, C))
            
            # Down direction: find first wall below R in column C
            d = find_down(C, R + 1)
            if d <= H and d > R:
                if find_up(C, d) == R:
                    destroyed.add((d, C))
            
            # Left direction: find first wall left of C in row R
            l = find_left(R, C - 1)
            if l > 0 and l < C:
                if find_right(R, l) == C:
                    destroyed.add((R, l))
            
            # Right direction: find first wall right of C in row R
            r_val = find_right(R, C + 1)
            if r_val <= W and r_val > C:
                if find_left(R, r_val) == C:
                    destroyed.add((R, r_val))
            
            # Destroy all valid walls found
            for r_wall, c_wall in destroyed:
                if find_up(c_wall, r_wall) == r_wall:  # Only destroy if wall still exists
                    total_walls -= 1
                    # Update pointers for this destroyed wall
                    up[c_wall][r_wall] = find_up(c_wall, r_wall - 1)
                    down[c_wall][r_wall] = find_down(c_wall, r_wall + 1)
                    left[r_wall][c_wall] = find_left(r_wall, c_wall - 1)
                    right[r_wall][c_wall] = find_right(r_wall, c_wall + 1)
    
    print(total_walls)

if __name__ == "__main__":
    main()