import sys
from bisect import bisect_left, bisect_right

def main():
    H, W, Q = map(int, sys.stdin.readline().split())
    
    # Initialize sets for walls in each row and column
    rows = [set(range(1, W + 1)) for _ in range(H + 1)]  # rows[i] = set of columns with walls in row i
    cols = [set(range(1, H + 1)) for _ in range(W + 1)]  # cols[j] = set of rows with walls in column j
    
    total_walls = H * W
    
    for _ in range(Q):
        R_q, C_q = map(int, sys.stdin.readline().split())
        
        if C_q in rows[R_q]:
            # Wall exists at (R_q, C_q), destroy it
            rows[R_q].remove(C_q)
            cols[C_q].remove(R_q)
            total_walls -= 1
        else:
            # No wall at (R_q, C_q), destroy first walls in four directions
            destroyed = set()
            
            # Up: find the largest row index < R_q that has a wall in column C_q
            col_walls = sorted(cols[C_q])
            pos = bisect_left(col_walls, R_q)
            if pos > 0:
                up_wall = col_walls[pos - 1]
                destroyed.add((up_wall, C_q))
            
            # Down: find the smallest row index > R_q that has a wall in column C_q
            if pos < len(col_walls):
                down_wall = col_walls[pos]
                destroyed.add((down_wall, C_q))
            
            # Left: find the largest column index < C_q that has a wall in row R_q
            row_walls = sorted(rows[R_q])
            pos = bisect_left(row_walls, C_q)
            if pos > 0:
                left_wall = row_walls[pos - 1]
                destroyed.add((R_q, left_wall))
            
            # Right: find the smallest column index > C_q that has a wall in row R_q
            if pos < len(row_walls):
                right_wall = row_walls[pos]
                destroyed.add((R_q, right_wall))
            
            # Remove all destroyed walls
            for r, c in destroyed:
                if c in rows[r]:
                    rows[r].remove(c)
                    cols[c].remove(r)
                    total_walls -= 1
    
    print(total_walls)

if __name__ == "__main__":
    main()