initialize union-find structure with path compression and union by rank
for each query:
    if query is of type 1:
        union the sets of u and v
        update the segment tree for the new connected component
    else:
        query the k-th largest element from the segment tree of the connected component of v