#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    // Calculate the number of empty squares initially
    long long totalSquares = N * N;
    long long occupiedSquares = M;
    long long emptySquares = totalSquares - occupiedSquares;
    
    // Subtract the capture range of each piece
    set<int> rows, cols, diag1, diag2;
    for (const auto &p : pieces) {
        int a = p.first, b = p.second;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    // Calculate the number of squares captured by rows and columns
    long long capturedByRows = rows.size() - 1; // Subtract the row where the piece is placed
    long long capturedByCols = cols.size() - 1; // Subtract the column where the piece is placed
    
    // Calculate the number of squares captured by diagonals
    long long capturedByDiag1 = diag1.size() - 1; // Subtract the diagonal where the piece is placed
    long long capturedByDiag2 = diag2.size() - 1; // Subtract the diagonal where the piece is placed
    
    // Calculate the overlapping capture ranges
    set<int> allLines;
    allLines.insert(rows.begin(), rows.end());
    allLines.insert(cols.begin(), cols.end());
    allLines.insert(diag1.begin(), diag1.end());
    allLines.insert(diag2.begin(), diag2.end());
    
    // Subtract the overlapping capture ranges
    long long totalCaptureRange = capturedByRows + capturedByCols + capturedByDiag1 + capturedByDiag2 - allLines.size();
    
    // Output the final number of empty squares
    cout << emptySquares - totalCaptureRange << endl;
    
    return 0;
}