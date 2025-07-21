// Initialize a bitmask of size N^2 with all bits set to 0 (all squares are initially empty)
Bitmask captured;

// For each piece
for each piece (a, b):
    // Check if the piece can capture square (a, b)
    if can_capture(a, b):
        // Mark all squares in the capture range as captured in the bitmask
        mark_captured_squares(a, b, captured);

// Calculate the number of empty squares
num_empty_squares = N * N - count_bits_set(captured);

// Output the result
cout << num_empty_squares;