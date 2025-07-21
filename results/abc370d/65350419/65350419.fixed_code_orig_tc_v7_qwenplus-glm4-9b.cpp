segment_tree tate[H]; // Segment tree for rows
segment_tree yoko[W]; // Segment tree for columns

for each (r, c) in queries:
    if wall exists at (r, c):
        destroy the wall
        update tate and yoko accordingly
    else:
        find and destroy walls around (r, c)
        update tate and yoko accordingly

remaining_walls = sum of remaining walls in tate and yoko