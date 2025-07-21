#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Using a set to store the positions of the existing pieces for efficient lookup
    unordered_set<long long> ex;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        // Convert 2D position to a 1D value for easy storage in the set
        long long pos = ((long long)a - 1) * n + b;
        ex.insert(pos);
    }

    // Directions for capturing pieces
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long pos = ((long long)i - 1) * n + j;
            bool canPlace = true;
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                long long newPos = ((long long)x - 1) * n + y;
                if (x >= 1 && x <= n && y >= 1 && y <= n && ex.count(newPos)) {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}