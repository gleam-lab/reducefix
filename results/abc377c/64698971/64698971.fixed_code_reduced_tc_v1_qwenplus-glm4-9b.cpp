#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct AttackRange {
    int row, col;
};

const vector<AttackRange> attack_directions = {
    {0, 0}, {2, 1}, {1, 2}, {-1, 2},
    {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> occupied;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});
    }
    
    long long total_cells = N * N;
    long long attackable_cells = 0;
    
    // For each occupied cell, calculate how many cells it can attack
    for (const auto& cell : occupied) {
        int r = cell.first;
        int c = cell.second;
        
        // For each attack direction
        for (const auto& dir : attack_directions) {
            int nr = r + dir.row;
            int nc = c + dir.col;
            
            // Check if the cell within the grid bounds
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                // Check if the new cell is not occupied
                if (occupied.find({nr, nc}) == occupied.end()) {
                    int step = abs(dir.row);
                    while (nr - step >= 0 && nr + step < N && nc - dir.col >= 0 && nc + dir.col < N) {
                        attackable_cells++;
                        nr += (dir.row > 0) ? 2 : -2;
                        nc += (dir.col > 0) ? 2 : -2;
                        step++;
                    }
                }
            }
        }
    }
    
    // Subtract the number of attackable cells from the total cells to get the number of safe cells
    cout << total_cells - attackable_cells << endl;
    
    return 0;
}