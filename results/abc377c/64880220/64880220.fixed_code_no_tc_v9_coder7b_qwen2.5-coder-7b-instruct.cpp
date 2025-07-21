#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        long long key = (a - 1) * n + b;
        if (!ex.count(key)) {
            ex.insert(key);
            ans--;
        }

        for (int d = 0; d < 8; d++) {
            long long x = a + dx[d];
            long long y = b + dy[d];
            long long newKey = (x - 1) * n + y;
            if (x > 0 && x <= n && y > 0 && y <= n && !ex.count(newKey)) {
                ex.insert(newKey);
                ans--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}