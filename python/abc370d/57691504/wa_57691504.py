H, W, Q = map(int, input().split())
total_walls = H * W

import sys
import threading

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    input = sys.stdin.readline

    Q = int(Q)
    total_walls = H * W

    next_wall_up = {}
    next_wall_down = {}
    next_wall_left = {}
    next_wall_right = {}

    for c in range(1, W + 1):
        next_wall_up[c] = {}
        next_wall_down[c] = {}

    for r in range(1, H + 1):
        next_wall_left[r] = {}
        next_wall_right[r] = {}

    def find_next_wall_up(c, i):
        if i <= 0:
            return 0
        if i not in next_wall_up[c]:
            return i
        else:
            next_wall_up[c][i] = find_next_wall_up(c, next_wall_up[c][i])
            return next_wall_up[c][i]

    def find_next_wall_down(c, i):
        if i > H:
            return H + 1
        if i not in next_wall_down[c]:
            return i
        else:
            next_wall_down[c][i] = find_next_wall_down(c, next_wall_down[c][i])
            return next_wall_down[c][i]

    def find_next_wall_left(r, j):
        if j <= 0:
            return 0
        if j not in next_wall_left[r]:
            return j
        else:
            next_wall_left[r][j] = find_next_wall_left(r, next_wall_left[r][j])
            return next_wall_left[r][j]

    def find_next_wall_right(r, j):
        if j > W:
            return W + 1
        if j not in next_wall_right[r]:
            return j
        else:
            next_wall_right[r][j] = find_next_wall_right(r, next_wall_right[r][j])
            return next_wall_right[r][j]

    for _ in range(Q):
        R_q, C_q = map(int, sys.stdin.readline().split())
        # Check if wall exists at (R_q, C_q)
        # For columns
        p_col = find_next_wall_up(C_q, R_q)
        if p_col != R_q:
            # No wall at (R_q, C_q)
            # Attempt to destroy walls in four directions
            # Up
            up = find_next_wall_up(C_q, R_q - 1)
            if up > 0:
                # Check if path is clear between up and R_q
                if up == R_q - 1:
                    # Destroy wall at up
                    total_walls -= 1
                    next_wall_up[C_q][up] = find_next_wall_up(C_q, up -1)
                # Else, walls in between, cannot destroy
            # Down
            down = find_next_wall_down(C_q, R_q +1)
            if down <= H:
                if down == R_q +1:
                    total_walls -=1
                    next_wall_down[C_q][down] = find_next_wall_down(C_q, down +1)
            # Left
            left = find_next_wall_left(R_q, C_q -1)
            if left > 0:
                if left == C_q -1:
                    total_walls -=1
                    next_wall_left[R_q][left] = find_next_wall_left(R_q, left -1)
            # Right
            right = find_next_wall_right(R_q, C_q +1)
            if right <= W:
                if right == C_q +1:
                    total_walls -=1
                    next_wall_right[R_q][right] = find_next_wall_right(R_q, right +1)
        else:
            # Wall exists at (R_q, C_q), destroy it
            total_walls -=1
            # Update next_wall_up and next_wall_down for column C_q
            next_wall_up[C_q][R_q] = find_next_wall_up(C_q, R_q -1)
            next_wall_down[C_q][R_q] = find_next_wall_down(C_q, R_q +1)
            # Update next_wall_left and next_wall_right for row R_q
            next_wall_left[R_q][C_q] = find_next_wall_left(R_q, C_q -1)
            next_wall_right[R_q][C_q] = find_next_wall_right(R_q, C_q +1)

    print(total_walls)

threading.Thread(target=main).start()
