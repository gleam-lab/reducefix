#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_N 1000000000

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces;
    pieces.reserve(M);
    
    // Read positions of all existing pieces
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.push_back({x, y});
    }
    
    // Create a set of all cells that can be threatened by any piece
    set<pair<int, int>> threatened;
    for (const auto& piece : pieces) {
        int x = piece.first, y = piece.second;
        // Check all the reachable cells
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the piece's own cell
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > N || ny < 1 || ny > N) continue; // Skip out-of-bounds cells
                threatened.insert({nx, ny});
            }
        }
    }
    
    // Calculate the number of non-threatened cells
    long long total_cells = N * N;
    long long threatened_cells = threatened.size();
    long long safe_cells = total_cells - threatened_cells;
    
    cout << safe_cells << endl;
    
    return 0;
}