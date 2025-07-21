function main() {
    h, w, q = read_input()
    segment_tree = initialize_segment_tree(h, w)
    
    for i in range(q):
        r, c = read_next_query()
        segment_tree.destroy_walls(r, c)
        remaining_walls = segment_tree.count_remaining_walls()
        print(remaining_walls)
    
    return 0
}

function initialize_segment_tree(h, w) {
    // Implement a segment tree that supports range updates and queries
}

function destroy_walls(segment_tree, r, c) {
    // Implement the logic to destroy walls based on the given rules
}

function count_remaining_walls(segment_tree) {
    // Traverse the segment tree to count the remaining walls
}