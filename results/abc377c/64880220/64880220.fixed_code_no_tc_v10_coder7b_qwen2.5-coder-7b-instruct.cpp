#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n; // Start with all squares as available

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<int, int> p;
        p = make_pair(a - 1, b - 1); // Adjust indices to 0-based

        if (!ex.count(p)) {
            ex[p] = 1;
        }

        // Check all possible capture positions
        vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
        for (int i = 0; i < 8; i++) {
            long long x, y;
            x = a + dx[i];
            y = b + dy[i];
            pair<int, int> q;
            q = make_pair(x - 1, y - 1); // Adjust indices to 0-based

            if (x > 0 && x <= n && y > 0 && y <= n) {
                if (!ex.count(q)) {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}