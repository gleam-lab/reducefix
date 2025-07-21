initialize grid with wall counts
for each query
    if bomb on wall
        decrement wall count
    else
        destroy walls in all directions
    update Segment Tree or Sparse Table
end for
compute remaining walls in the grid
print the result