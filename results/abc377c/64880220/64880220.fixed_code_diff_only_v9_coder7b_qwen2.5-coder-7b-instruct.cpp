#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;
    long long ans = n * n - m; // Initially all squares minus the occupied ones

    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p = make_pair(a, b);

        for (int d = 0; d < 8; d++) {
            long long x = a + dx[d], y = b + dy[d];
            if (x > 0 && x <= n && y > 0 && y <= n) {
                pair<long long, long long> np = make_pair(x, y);
                if (!ex.count(np)) {
                    ex.insert(np);
                    ans--;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}