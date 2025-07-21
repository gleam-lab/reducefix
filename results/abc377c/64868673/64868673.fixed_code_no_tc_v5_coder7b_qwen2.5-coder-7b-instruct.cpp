#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n; // Start with total number of cells

    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p;
        p = make_pair(a, b);

        if (!ex.count(p)) {
            ex[p] = 1;
            for (long long j = 0; j < 8; j++) {
                long long x, y;
                x = a + dx[j];
                y = b + dy[j];
                pair<long long, long long> q;
                q = make_pair(x, y);
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    if (!ex.count(q)) {
                        ans--; // Decrement count since this cell can't be placed upon
                    }
                }
            }
        }
    }

    cout << ans << endl;
}