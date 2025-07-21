function solve():
    n, m = read_input()
    # Initialize capture tracking structures
    rowCapture = initializeCaptureStructure(n)
    colCapture = initializeCaptureStructure(n)
    diagCapture = initializeCaptureStructure(2 * n - 1)
    antiDiagCapture = initializeCaptureStructure(2 * n - 1)
    
    # Read pieces and mark the capture areas
    for _ in range(m):
        a, b = read_piece()
        markCapture(rowCapture, a, b)
        markCapture(colCapture, a, b)
        markCapture(diagCapture, a, b)
        markCapture(antiDiagCapture, a, b)
    
    # Count the number of safe squares
    safeSquares = countSafeSquares(n, rowCapture, colCapture, diagCapture, antiDiagCapture)
    return safeSquares

function main():
    answer = solve()
    print(answer)