#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Directions a piece can capture in the order (dx, dy)
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // Set to store occupied cells
    set<pair<long long, long long>> occupied;
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }
    
    // Set to store cells that cannot be used to place new pieces
    set<pair<long long, long long>> blocked;
    
    for (const auto& occupiedCell : occupied) {
        for (const auto& dir : directions) {
            long long x = occupiedCell.first;
            long long y = occupiedCell.second;
            for (int k = 1; k <= 2; ++k) {
                x += dir.first;
                y += dir.second;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    blocked.insert({x, y});
                }
            }
        }
    }
    
    // Calculate the number of cells that can be used to place new pieces
    long long freeCells = n * n;
    for (const auto& blockedCell : blocked) {
        freeCells--;
    }
    
    cout << freeCells << endl;
    
    return 0;
}