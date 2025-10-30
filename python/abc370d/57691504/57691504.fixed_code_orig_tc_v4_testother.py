H, W, Q = map(int, input().split())
total_walls = H * W

# Use union-find (disjoint set) for each row and column to track next existing wall
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n + 2))  # 0 to n+1 as boundaries
        self.n = n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != py:
            self.parent[px] = py

# For each row, maintain left and right neighbors
row_left = [UnionFind(W) for _ in range(H + 1)]
row_right = [UnionFind(W) for _ in range(H + 1)]

# For each column, maintain up and down neighbors
col_up = [UnionFind(H) for _ in range(W + 1)]
col_down = [UnionFind(H) for _ in range(W + 1)]

# Initially all walls exist, so no unions yet
# When a wall is destroyed, we union its position with neighbors

for _ in range(Q):
    R, C = map(int, input().split())
    
    # Check if wall at (R,C) exists
    # In our DSU, if the cell hasn't been destroyed, it points to itself
    # After destruction, it gets unioned with neighbors
    if col_up[C].find(R) == R and col_down[C].find(R) == R:
        # Wall exists at (R,C), destroy it
        total_walls -= 1
        
        # Union with adjacent cells in both directions
        if R > 1:
            col_up[C].union(R, R - 1)
        if R < H:
            col_down[C].union(R, R + 1)
        if C > 1:
            row_left[R].union(C, C - 1)
        if C < W:
            row_right[R].union(C, C + 1)
    else:
        # No wall at (R,C), destroy first wall in each direction
        directions = [
            # up: find the next wall above R in column C
            (lambda: col_up[C].find(R - 1) if R > 1 else None, 
             lambda r: col_up[C].union(r, r - 1) if r > 1 else None),
            # down: find the next wall below R in column C  
            (lambda: col_down[C].find(R + 1) if R < H else None,
             lambda r: col_down[C].union(r, r + 1) if r < H else None),
            # left: find the next wall to the left of C in row R
            (lambda: row_left[R].find(C - 1) if C > 1 else None,
             lambda c: row_left[R].union(c, c - 1) if c > 1 else None),
            # right: find the next wall to the right of C in row R
            (lambda: row_right[R].find(C + 1) if C < W else None,
             lambda c: row_right[R].union(c, c + 1) if c < W else None)
        ]
        
        destroyed = set()
        for get_pos, union_next in directions:
            pos = get_pos()
            if pos is not None and pos != 0 and pos <= (H if isinstance(pos, int) and pos <= H else W):
                # We found a wall in this direction
                actual_pos = pos
                if actual_pos >= 1:  # valid position
                    if actual_pos not in destroyed:
                        destroyed.add(actual_pos)
                        total_walls -= 1
                        union_next(actual_pos)

print(total_walls)