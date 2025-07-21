#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int N, M;
set<pair<int, int>> occupied;

bool can_capture(int r, int c) {
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (auto move : moves) {
        int nr = r + move.first;
        int nc = c + move.second;
        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (occupied.count({nr, nc})) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    
    occupied.clear();
    
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        occupied.insert({r - 1, c - 1});
    }
    
    // Calculate the number of empty squares
    long long empty_squares = N * N - occupied.size();
    
    // Subtract the squares that are captured by existing pieces
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!occupied.count({i, j}) && !can_capture(i, j)) {
                empty_squares--;
            }
        }
    }
    
    cout << empty_squares << endl;
    return 0;
}