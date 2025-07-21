#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    int ans = 0;
    set<pair<long long, long long>> c;
    
    // Mark all squares that cannot be placed due to the presence of a piece
    rep(i, m) {
        cin >> a >> b;
        --a, --b; // Convert 1-based index to 0-based index
        c.insert({a, b});
        
        // Check all possible positions a piece can attack from this position
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto& dir : directions) {
            int x = a + dir.first, y = b + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                c.insert({x, y});
            }
        }
    }

    // Calculate the number of empty squares available for placing a new piece
    ans = n * n - c.size();
    cout << ans << endl;

    return 0;
}