function calculateSafeSquares(N, M, pieces):
    vulnerable_rows = set()
    vulnerable_columns = set()
    vulnerable_squares = set()

    for each piece in pieces:
        (a, b) = piece
        # Identify vulnerable rows and columns
        vulnerable_rows.add(a)
        vulnerable_columns.add(b)

        # Identify vulnerable squares based on capturing conditions
        # For horizontal lines
        if a + b is in vulnerable_rows:
            vulnerable_squares.add((a, b))
        if a - b is in vulnerable_columns:
            vulnerable_squares.add((a, b))

    # Calculate the total number of squares
    total_squares = N * N

    # Calculate vulnerable rows, columns, and squares
    vulnerable_rows_count = len(vulnerable_rows)
    vulnerable_columns_count = len(vulnerable_columns)
    vulnerable_squares_count = len(vulnerable_squares)

    # Calculate the number of safe squares
    safe_squares = total_squares - vulnerable_rows_count - vulnerable_columns_count - vulnerable_squares_count

    return safe_squares