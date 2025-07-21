#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;

    // Directions for capturing moves
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    set<pair<long long, long long>> unsafeSquares;

    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based index

        for (int d = 0; d < 8; ++d) {
            long long x = a + dx[d], y = b + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                unsafeSquares.insert({x, y});
            }
        }
    }

    ans -= unsafeSquares.size();
    cout << ans << endl;

    return 0;
}