from typing import Dict

def main() -> None:
    H, W, Q = map(int, input().split())

    # Initialize the grid with walls
    grid: List[List[bool]] = [[True for _ in range(W)] for _ in range(H)]

    # Function to find the next wall above or to the left of a position
    def find_next_wall(grid: List[List[bool]], pos: tuple, direction: str) -> tuple:
        h, w = pos
        dh, dw = (-1, 0) if direction == 'up' else (1, 0) if direction == 'down' else (0, -1) if direction == 'left' else (0, 1)
        while True:
            h += dh
            w += dw
            if not (0 <= h < H and 0 <= w < W) or not grid[h][w]:
                break
        return h, w

    for _ in range(Q):
        R_q, C_q = map(int, input().split())
        R_q -= 1
        C_q -= 1

        if grid[R_q][C_q]:
            # If there is a wall at (R_q, C_q), destroy it
            grid[R_q][C_q] = False
        else:
            # If there is no wall at (R_q, C_q), destroy the first walls that appear when looking up, down, left, and right from (R_q, C_q)
            for direction in ['up', 'down', 'left', 'right']:
                h, w = find_next_wall(grid, (R_q, C_q), direction)
                if grid[h][w]:
                    grid[h][w] = False

    # Count the remaining walls
    remaining_walls = sum(sum(row) for row in grid)
    print(remaining_walls)


if __name__ == "__main__":
    main()