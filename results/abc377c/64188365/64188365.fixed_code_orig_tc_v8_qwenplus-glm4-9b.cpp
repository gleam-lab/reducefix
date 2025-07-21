#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<int>> capture(ranges::iota(0, 2 * n - 1));
    
    set<pair<int, int>> occupied;
    set<pair<int, int>> pieces;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
        pieces.emplace(a, b);
        
        // Mark the capture range of the piece
        auto mark = [&](int x, int y) {
            int dx = 0, dy = 2;
            while (true) {
                if (x + dx >= 1 && x + dx <= n && y + dy >= 1 && y + dy <= n) {
                    capture[x + dx][y + dy] = 1;
                } else {
                    break;
                }
                dx += 2;
                dy -= 2;
            }
        };
        
        mark(a, b);
        mark(a, n - b + 1);
        mark(n - a + 1, b);
        mark(n - a + 1, n - b + 1);
    }
    
    long long safe_cells = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (find(occupied.begin(), occupied.end(), {i, j}) == occupied.end()) {
                bool is_captured = false;
                for (int k = -1; k <= 1; ++k) {
                    for (int l = -1; l <= 1; ++l) {
                        if (capture[i + k][j + l] == 1) {
                            is_captured = true;
                            break;
                        }
                    }
                    if (is_captured) break;
                }
                if (!is_captured) safe_cells++;
            }
        }
    }
    
    cout << safe_cells << endl;
    return 0;
}