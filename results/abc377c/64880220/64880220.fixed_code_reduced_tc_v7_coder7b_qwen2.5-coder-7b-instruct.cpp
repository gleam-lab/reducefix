#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    // Store positions of all existing pieces
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<int, int> p;
        p = make_pair(a, b);
        if (!ex.count(p)) {
            ex[p] = 1;
        }
    }

    // Check each cell to see if it can be occupied
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            bool canPlace = true;
            for (int d = 0; d < 8; d++) {
                long long x = i + dx[d], y = j + dy[d];
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    if (ex.count(make_pair(x, y))) {
                        canPlace = false;
                        break;
                    }
                }
            }
            if (canPlace) {
                ans++;
            }
        }
    }

    cout << n * n - ans << endl;
}