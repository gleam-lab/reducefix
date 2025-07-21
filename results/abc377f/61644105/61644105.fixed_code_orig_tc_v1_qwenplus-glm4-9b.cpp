#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long N, M;
vector<pair<int, int>> pieces;

// Directions for rows and columns
const vector<pair<int, int>> directions = {
    {0, 1}, {1, 0}, {1, 1}, {1, -1}
};

// Function to calculate the total number of safe squares
long long calculateSafeSquares() {
    long long totalSquares = N * N;
    vector<vector<bool>> captured(N + 1, vector<bool>(N + 1, false));
    
    // Mark captured squares for each piece
    for (auto p : pieces) {
        int x = p.first, y = p.second;
        for (auto dir : directions) {
            int nx = x + dir.first * (N + 1), ny = y + dir.second * (N + 1);
            captured[nx][ny] = true;
        }
    }
    
    // Calculate the number of safe squares
    long long safeSquares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!captured[i][j]) {
                safeSquares++;
            }
        }
    }
    
    return safeSquares;
}

int main() {
    cin >> N >> M;
    pieces.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    cout << calculateSafeSquares() << endl;
    return 0;
}