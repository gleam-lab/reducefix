#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n; // Initialize ans with total number of squares
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p;
        p = make_pair(a, b);

        if (!ex.count(p)) {
            ex[p] = 1;
            ans--; // Subtract one as this position is not available now

            for (long long i = 0; i < 8; i++) {
                long long x, y;
                x = a + dx[i];
                y = b + dy[i];
                p = make_pair(x, y);

                if (x > 0 && x <= n && y > 0 && y <= n) {
                    if (!ex.count(p)) {
                        ex[p] = 1;
                        ans--; // Subtract one as this position is also not available now
                    }
                }
            }
        }
    }

    cout << ans << endl;
}