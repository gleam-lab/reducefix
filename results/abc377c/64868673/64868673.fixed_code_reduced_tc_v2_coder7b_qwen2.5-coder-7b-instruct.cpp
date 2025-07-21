#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;

    // Directions for capturing
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p = make_pair(a, b);

        // Mark the square itself as captured
        ex[p] = 1;

        // Mark all squares it can capture
        for (int dir = 0; dir < 8; ++dir) {
            long long x = a + dx[dir];
            long long y = b + dy[dir];
            while (x >= 1 && x <= n && y >= 1 && y <= n) {
                pair<long long, long long> np = make_pair(x, y);
                if (!ex.count(np)) {
                    ex[np] = 1;
                } else {
                    break; // No need to continue if already captured
                }
                x += dx[dir];
                y += dy[dir];
            }
        }

        // Decrease the count since this square was counted multiple times
        --ans;
    }

    cout << ans << endl;
}