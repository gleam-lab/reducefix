class SegmentTree {
    // Implementation for segment tree with range queries and updates
};

using my_tree = SegmentTree;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    my_tree row_trees[w], col_trees[h];
    // Initialize the trees with wall counts

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;

        // Check if there is a wall at the given cell
        if (!row_trees[c].get(r) || !col_trees[r].get(c)) {
            // No wall at the cell, remove walls in all four directions
            remove_walls(row_trees, r, w);
            remove_walls(col_trees, c, h);
        }

        // Update the segment tree with the new wall counts after the query
    }

    // Count the remaining walls
    int remaining_walls = count_remaining_walls(row_trees, col_trees);

    cout << remaining_walls << endl;
}