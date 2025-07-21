#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        long long pos = (a - 1) * n + (b - 1);
        if (!ex.count(pos)) {
            ex.insert(pos);
            for (int j = 0; j < 8; ++j) {
                long long x = a + dx[j], y = b + dy[j];
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    long long nextPos = (x - 1) * n + (y - 1);
                    if (!ex.count(nextPos)) {
                        --ans;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}