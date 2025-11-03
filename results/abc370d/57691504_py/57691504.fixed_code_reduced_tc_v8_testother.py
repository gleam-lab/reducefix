import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().split()
    if not data:
        print(0)
        return
        
    H = int(data[0]); W = int(data[1]); Q = int(data[2])
    total_walls = H * W
    
    # For each row, maintain left and right next walls using union-find style path compression
    left_wall = [dict() for _ in range(H+1)]   # left_wall[r][c] = next existing wall to the left in row r
    right_wall = [dict() for _ in range(H+1)]  # right_wall[r][c] = next existing wall to the right in row r
    
    # For each column, maintain up and down next walls
    up_wall = [dict() for _ in range(W+1)]     # up_wall[c][r] = next existing wall above in column c
    down_wall = [dict() for _ in range(W+1)]   # down_wall[c][r] = next existing wall below in column c
    
    def find_left(r, c):
        if c <= 0:
            return 0
        if c not in left_wall[r]:
            return c
        left_wall[r][c] = find_left(r, left_wall[r][c])
        return left_wall[r][c]
    
    def find_right(r, c):
        if c > W:
            return W + 1
        if c not in right_wall[r]:
            return c
        right_wall[r][c] = find_right(r, right_wall[r][c])
        return right_wall[r][c]
    
    def find_up(c, r):
        if r <= 0:
            return 0
        if r not in up_wall[c]:
            return r
        up_wall[c][r] = find_up(c, up_wall[c][r])
        return up_wall[c][r]
    
    def find_down(c, r):
        if r > H:
            return H + 1
        if r not in down_wall[c]:
            return r
        down_wall[c][r] = find_down(c, down_wall[c][r])
        return down_wall[c][r]
    
    index = 3
    for _ in range(Q):
        R_q = int(data[index]); C_q = int(data[index+1]); index += 2
        
        # Check if there's a wall at (R_q, C_q)
        # We check by seeing if the next wall to the left from C_q is exactly C_q
        # But easier: if we can reach R_q when looking up from R_q in column C_q?
        if find_up(C_q, R_q) == R_q:
            # Wall exists at (R_q, C_q), destroy it
            total_walls -= 1
            
            # Update links: connect this cell to its neighbors
            up_wall[C_q][R_q] = find_up(C_q, R_q - 1)
            down_wall[C_q][R_q] = find_down(C_q, R_q + 1)
            left_wall[R_q][C_q] = find_left(R_q, C_q - 1)
            right_wall[R_q][C_q] = find_right(R_q, C_q + 1)
        else:
            # No wall at (R_q, C_q): try to destroy first walls in each direction
            destroyed = set()
            
            # Up direction: find the first wall above
            up_pos = find_up(C_q, R_q - 1)
            if up_pos >= 1 and up_pos <= H:
                # Check if there are no walls between up_pos and R_q
                if find_down(C_q, up_pos) == R_q:
                    destroyed.add((up_pos, C_q))
            
            # Down direction
            down_pos = find_down(C_q, R_q + 1)
            if down_pos >= 1 and down_pos <= H:
                if find_up(C_q, down_pos) == R_q:
                    destroyed.add((down_pos, C_q))
            
            # Left direction
            left_pos = find_left(R_q, C_q - 1)
            if left_pos >= 1 and left_pos <= W:
                if find_right(R_q, left_pos) == C_q:
                    destroyed.add((R_q, left_pos))
            
            # Right direction
            right_pos = find_right(R_q, C_q + 1)
            if right_pos >= 1 and right_pos <= W:
                if find_left(R_q, right_pos) == C_q:
                    destroyed.add((R_q, right_pos))
            
            # Destroy all valid walls found
            total_walls -= len(destroyed)
            
            # Update the union-find structures for each destroyed wall
            for r, c in destroyed:
                # Only update if not already destroyed (shouldn't happen due to set)
                up_wall[c][r] = find_up(c, r - 1)
                down_wall[c][r] = find_down(c, r + 1)
                left_wall[r][c] = find_left(r, c - 1)
                right_wall[r][c] = find_right(r, c + 1)
    
    print(total_walls)

if __name__ == "__main__":
    main()