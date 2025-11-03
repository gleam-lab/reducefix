H, W, Q = map(int, input().split())

# Use dictionaries to store next existing wall in each direction
# For each column, maintain top and bottom boundaries
col_top = [dict() for _ in range(W + 1)]  # col_top[c][r] = next wall above row r in column c
col_bottom = [dict() for _ in range(W + 1)]  # col_bottom[c][r] = next wall below row r in column c

# For each row, maintain left and right boundaries
row_left = [dict() for _ in range(H + 1)]  # row_left[r][c] = next wall to the left of column c in row r
row_right = [dict() for _ in range(H + 1)]  # row_right[r][c] = next wall to the right of column c in row r

def find_next_up(c, r):
    if r <= 0:
        return 0
    if r not in col_top[c]:
        return r
    col_top[c][r] = find_next_up(c, col_top[c][r])
    return col_top[c][r]

def find_next_down(c, r):
    if r > H:
        return H + 1
    if r not in col_bottom[c]:
        return r
    col_bottom[c][r] = find_next_down(c, col_bottom[c][r])
    return col_bottom[c][r]

def find_next_left(r, c):
    if c <= 0:
        return 0
    if c not in row_left[r]:
        return c
    row_left[r][c] = find_next_left(r, row_left[r][c])
    return row_left[r][c]

def find_next_right(r, c):
    if c > W:
        return W + 1
    if c not in row_right[r]:
        return c
    row_right[r][c] = find_next_right(r, row_right[r][c])
    return row_right[r][c]

total_walls = H * W

for _ in range(Q):
    R_q, C_q = map(int, input().split())
    
    # Check if there's a wall at (R_q, C_q)
    up_wall = find_next_up(C_q, R_q)
    down_wall = find_next_down(C_q, R_q)
    
    if up_wall == R_q and down_wall == R_q:
        # Wall exists at (R_q, C_q), destroy it
        total_walls -= 1
        
        # Update the union-find structures
        # In column C_q: connect R_q with R_q-1 and R_q+1
        if R_q > 1:
            col_top[C_q][R_q] = find_next_up(C_q, R_q - 1)
        if R_q < H:
            col_bottom[C_q][R_q] = find_next_down(C_q, R_q + 1)
            
        # In row R_q: connect C_q with C_q-1 and C_q+1
        if C_q > 1:
            row_left[R_q][C_q] = find_next_left(R_q, C_q - 1)
        if C_q < W:
            row_right[R_q][C_q] = find_next_right(R_q, C_q + 1)
    else:
        # No wall at (R_q, C_q), destroy first walls in each direction if they're adjacent
        destroyed = 0
        
        # Up direction
        up_candidate = find_next_up(C_q, R_q - 1)
        if up_candidate > 0 and up_candidate == R_q - 1:
            total_walls -= 1
            destroyed += 1
            # Update column structure for this wall
            col_top[C_q][up_candidate] = find_next_up(C_q, up_candidate - 1)
            col_bottom[C_q][up_candidate] = find_next_down(C_q, up_candidate + 1)
        
        # Down direction  
        down_candidate = find_next_down(C_q, R_q + 1)
        if down_candidate <= H and down_candidate == R_q + 1:
            total_walls -= 1
            destroyed += 1
            # Update column structure for this wall
            col_top[C_q][down_candidate] = find_next_up(C_q, down_candidate - 1)
            col_bottom[C_q][down_candidate] = find_next_down(C_q, down_candidate + 1)
            
        # Left direction
        left_candidate = find_next_left(R_q, C_q - 1)
        if left_candidate > 0 and left_candidate == C_q - 1:
            total_walls -= 1
            destroyed += 1
            # Update row structure for this wall
            row_left[R_q][left_candidate] = find_next_left(R_q, left_candidate - 1)
            row_right[R_q][left_candidate] = find_next_right(R_q, left_candidate + 1)
            
        # Right direction
        right_candidate = find_next_right(R_q, C_q + 1)
        if right_candidate <= W and right_candidate == C_q + 1:
            total_walls -= 1
            destroyed += 1
            # Update row structure for this wall
            row_left[R_q][right_candidate] = find_next_left(R_q, right_candidate - 1)
            row_right[R_q][right_candidate] = find_next_right(R_q, right_candidate + 1)

print(total_walls)