#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<long long> ex;
    long long ans = 0;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        long long key = ((long long)a << 32) | b;
        if (!ex.count(key)) {
            ex.insert(key);
            ++ans;
        }
        for (int j = 0; j < 8; ++j) {
            int x = a + dx[j], y = b + dy[j];
            long long nextKey = ((long long)x << 32) | y;
            if (x >= 1 && x <= n && y >= 1 && y <= n && !ex.count(nextKey)) {
                ex.insert(nextKey);
                ++ans;
            }
        }
    }

    cout << n * n - ans << endl;
    return 0;
}