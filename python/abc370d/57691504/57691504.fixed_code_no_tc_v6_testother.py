import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().split()
    H = int(data[0]); W = int(data[1]); Q = int(data[2])
    total_walls = H * W
    
    # For each row, maintain the next wall to the left and right using union-find (DSU) style path compression
    # We'll use dictionaries to simulate DSU for each row and column
    left_parent = [dict() for _ in range(H+1)]  # left_parent[r][c] = furthest consecutive destroyed cell to the left
    right_parent = [dict() for _ in range(H+1)]  # right_parent[r][c] = furthest consecutive destroyed cell to the right
    up_parent = [dict() for _ in range(W+1)]    # up_parent[c][r] = furthest consecutive destroyed cell upward
    down_parent = [dict() for _ in range(W+1)]  # down_parent[c][r] = furthest consecutive destroyed cell downward
    
    def find_left(r, c):
        if c <= 0:
            return 0
        if c not in left_parent[r]:
            return c
        left_parent[r][c] = find_left(r, left_parent[r][c])
        return left_parent[r][c]
    
    def find_right(r, c):
        if c > W:
            return W + 1
        if c not in right_parent[r]:
            return c
        right_parent[r][c] = find_right(r, right_parent[r][c])
        return right_parent[r][c]
    
    def find_up(c, r):
        if r <= 0:
            return 0
        if r not in up_parent[c]:
            return r
        up_parent[c][r] = find_up(c, up_parent[c][r])
        return up_parent[c][r]
    
    def find_down(c, r):
        if r > H:
            return H + 1
        if r not in down_parent[c]:
            return r
        down_parent[c][r] = find_down(c, down_parent[c][r])
        return down_parent[c][r]
    
    index = 3
    for _ in range(Q):
        R_q = int(data[index]); C_q = int(data[index+1]); index += 2
        
        # Check if there's a wall at (R_q, C_q)
        # A wall exists if it hasn't been destroyed, i.e., 
        # it is still reachable from itself in all directions
        has_wall = (find_up(C_q, R_q) == R_q and 
                   find_down(C_q, R_q) == R_q and 
                   find_left(R_q, C_q) == C_q and 
                   find_right(R_q, C_q) == C_q)
        
        if has_wall:
            # Destroy the wall at (R_q, C_q)
            total_walls -= 1
            
            # Update DSU structures: merge with neighbors
            left_parent[R_q][C_q] = find_left(R_q, C_q - 1)
            right_parent[R_q][C_q] = find_right(R_q, C_q + 1)
            up_parent[C_q][R_q] = find_up(C_q, R_q - 1)
            down_parent[C_q][R_q] = find_down(C_q, R_q + 1)
            
        else:
            # No wall at bomb location, so try to destroy first walls in each direction
            destroyed = set()
            
            # Look up: find the first wall above R_q in column C_q
            r_up = find_up(C_q, R_q - 1)
            if r_up > 0 and find_down(C_q, r_up) == r_up:  # wall exists at (r_up, C_q)
                # Check if path is clear (no walls between r_up and R_q)
                if find_down(C_q, r_up + 1) >= R_q:
                    destroyed.add((r_up, C_q))
            
            # Look down: find the first wall below R_q in column C_q
            r_down = find_down(C_q, R_q + 1)
            if r_down <= H and find_up(C_q, r_down) == r_down:  # wall exists at (r_down, C_q)
                if find_up(C_q, r_down - 1) <= R_q:
                    destroyed.add((r_down, C_q))
            
            # Look left: find the first wall to the left of C_q in row R_q
            c_left = find_left(R_q, C_q - 1)
            if c_left > 0 and find_right(R_q, c_left) == c_left:  # wall exists at (R_q, c_left)
                if find_right(R_q, c_left + 1) >= C_q:
                    destroyed.add((R_q, c_left))
            
            # Look right: find the first wall to the right of C_q in row R_q
            c_right = find_right(R_q, C_q + 1)
            if c_right <= W and find_left(R_q, c_right) == c_right:  # wall exists at (R_q, c_right)
                if find_left(R_q, c_right - 1) <= C_q:
                    destroyed.add((R_q, c_right))
            
            # Destroy all valid walls found
            for r, c in destroyed:
                total_walls -= 1
                # Update the DSU structures for this destroyed wall
                left_parent[r][c] = find_left(r, c - 1)
                right_parent[r][c] = find_right(r, c + 1)
                up_parent[c][r] = find_up(c, r - 1)
                down_parent[c][r] = find_down(c, r + 1)
    
    print(total_walls)

if __name__ == "__main__":
    main()