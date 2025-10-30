import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().split()
    if not data:
        print(0)
        return
    
    H = int(data[0]); W = int(data[1]); Q = int(data[2])
    total_walls = H * W
    
    # For each row, maintain left and right nearest walls
    left_wall = [list(range(-1, W+1)) for _ in range(H+1)]   # left_wall[r][c] = farthest left wall at or before c in row r
    right_wall = [list(range(W+2)) for _ in range(H+1)]      # right_wall[r][c] = farthest right wall at or after c in row r
    
    # For each column, maintain up and down nearest walls
    up_wall = [list(range(-1, H+1)) for _ in range(W+1)]     # up_wall[c][r] = farthest up wall at or above r in col c
    down_wall = [list(range(H+2)) for _ in range(W+1)]       # down_wall[c][r] = farthest down wall at or below r in col c
    
    def find_left(r, c):
        if left_wall[r][c] != c:
            left_wall[r][c] = find_left(r, left_wall[r][c])
        return left_wall[r][c]
    
    def find_right(r, c):
        if right_wall[r][c] != c:
            right_wall[r][c] = find_right(r, right_wall[r][c])
        return right_wall[r][c]
    
    def find_up(c, r):
        if up_wall[c][r] != r:
            up_wall[c][r] = find_up(c, up_wall[c][r])
        return up_wall[c][r]
    
    def find_down(c, r):
        if down_wall[c][r] != r:
            down_wall[c][r] = find_down(c, down_wall[c][r])
        return down_wall[c][r]
    
    index = 3
    for _ in range(Q):
        R = int(data[index]); C = int(data[index+1]); index += 2
        
        # Check if there's a wall at (R, C)
        # In row R, check if C is between the nearest walls
        left_neighbor = find_left(R, C-1)
        right_neighbor = find_right(R, C+1)
        up_neighbor = find_up(C, R-1)
        down_neighbor = find_down(C, R+1)
        
        has_wall_here = (left_neighbor == C-1) and (right_neighbor == C+1) and \
                        (up_neighbor == R-1) and (down_neighbor == R+1)
        
        if has_wall_here:
            # Destroy the wall at (R, C)
            total_walls -= 1
            
            # Update structures: merge C into both sides in row R
            left_boundary = find_left(R, C-1)
            right_boundary = find_right(R, C+1)
            left_wall[R][C] = left_boundary
            right_wall[R][C] = right_boundary
            if left_boundary != -1:
                right_wall[R][left_boundary] = right_boundary
            if right_boundary <= W:
                left_wall[R][right_boundary] = left_boundary
                
            # Update structures: merge R into both sides in column C
            up_boundary = find_up(C, R-1)
            down_boundary = find_down(C, R+1)
            up_wall[C][R] = up_boundary
            down_wall[C][R] = down_boundary
            if up_boundary != -1:
                down_wall[C][up_boundary] = down_boundary
            if down_boundary <= H:
                up_wall[C][down_boundary] = up_boundary
                
        else:
            # No wall at (R, C), destroy first walls in each direction if visible
            destroyed = set()
            
            # Up direction: first wall above R in column C
            wall_r = find_up(C, R-1)
            if wall_r > 0 and wall_r < R:
                # Check if path is clear (no walls between wall_r and R)
                next_below = find_down(C, wall_r+1)
                if next_below > R:
                    destroyed.add((wall_r, C))
            
            # Down direction: first wall below R in column C
            wall_r = find_down(C, R+1)
            if wall_r <= H and wall_r > R:
                next_above = find_up(C, wall_r-1)
                if next_above < R:
                    destroyed.add((wall_r, C))
            
            # Left direction: first wall to the left of C in row R
            wall_c = find_left(R, C-1)
            if wall_c > 0 and wall_c < C:
                next_right = find_right(R, wall_c+1)
                if next_right > C:
                    destroyed.add((R, wall_c))
            
            # Right direction: first wall to the right of C in row R
            wall_c = find_right(R, C+1)
            if wall_c <= W and wall_c > C:
                next_left = find_left(R, wall_c-1)
                if next_left < C:
                    destroyed.add((R, wall_c))
            
            total_walls -= len(destroyed)
            
            # Update union-find structures for each destroyed wall
            for r, c in destroyed:
                # Update row r
                left_boundary = find_left(r, c-1)
                right_boundary = find_right(r, c+1)
                left_wall[r][c] = left_boundary
                right_wall[r][c] = right_boundary
                if left_boundary >= 0:
                    right_wall[r][left_boundary] = right_boundary
                if right_boundary <= W:
                    left_wall[r][right_boundary] = left_boundary
                
                # Update column c
                up_boundary = find_up(c, r-1)
                down_boundary = find_down(c, r+1)
                up_wall[c][r] = up_boundary
                down_wall[c][r] = down_boundary
                if up_boundary >= 0:
                    down_wall[c][up_boundary] = down_boundary
                if down_boundary <= H:
                    up_wall[c][down_boundary] = up_boundary
    
    print(total_walls)

if __name__ == "__main__":
    main()