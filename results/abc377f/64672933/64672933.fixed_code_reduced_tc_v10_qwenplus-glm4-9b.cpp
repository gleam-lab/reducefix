#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i][0] >> pieces[i][1];
    }

    // Calculate the number of squares that cannot be captured directly
    i64 totalCaptured = 0;
    for (i64 i = 1; i <= N; ++i) {
        totalCaptured += 2; // all squares in row i and column i
    }
    for (i64 i = 1; i <= N / 2; ++i) {
        totalCaptured += N * 2 - 8 * i; // diagonals
    }
    
    // Calculate the number of squares captured by each piece
    map<i64, i64> rowCapture, colCapture, diag1Capture, diag2Capture;
    for (const auto& piece : pieces) {
        rowCapture[piece[0]]++;
        colCapture[piece[1]]++;
        diag1Capture[piece[0] + piece[1]]++;
        diag2Capture[piece[0] - piece[1]]++;
    }
    
    // Calculate the number of captured squares based on captures
    i64 capturedSquares = totalCaptured;
    for (auto& entry : rowCapture) {
        capturedSquares -= N * entry.second - (entry.first == 1) - (entry.first == N);
    }
    for (auto& entry : colCapture) {
        capturedSquares -= N * entry.second - (entry.first == 1) - (entry.first == N);
    }
    for (auto& entry : diag1Capture) {
        capturedSquares -= (entry.first <= N && entry.first >= 1) ? N * entry.second - 2 * (entry.first == 1) : 0;
    }
    for (auto& entry : diag2Capture) {
        capturedSquares -= (entry.first <= N && entry.first >= 1) ? N * entry.second - 2 * (entry.first == 1) : 0;
    }
    
    // Calculate the number of squares where the piece can be placed
    i64 totalSquares = N * N;
    i64 freeSquares = totalSquares - capturedSquares;
    
    // Output the result
    cout << freeSquares << endl;
    
    return 0;
}