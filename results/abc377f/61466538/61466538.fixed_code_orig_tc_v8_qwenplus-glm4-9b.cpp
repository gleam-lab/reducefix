int totalSquares = N * N;

for each piece (i, j) in existing pieces:
    totalSquares -= 1;  // Exclude the current piece's square

for each row i:
    count pieces on row i
    totalSquares -= count;  // Exclude all squares in this row

for each column j:
    count pieces on column j
    totalSquares -= count;  // Exclude all squares in this column

for each diagonal (i + j) and anti-diagonal (i - j):
    count pieces on this diagonal
    totalSquares -= count;  // Exclude all squares on this diagonal

// Adjust for overlaps
for each pair of pieces (i1, j1) and (i2, j2):
    calculate sizes of overlapping capture zones
    adjust totalSquares by adding the sizes of these zones

print totalSquares