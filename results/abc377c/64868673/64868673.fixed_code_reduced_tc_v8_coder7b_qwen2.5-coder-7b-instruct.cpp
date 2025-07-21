#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    unordered_set<long long> ex;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        long long idx = (a - 1) * n + b;
        if (!ex.count(idx)) {
            ex.insert(idx);
            for (int j = 0; j < 8; ++j) {
                long long x = a + dx[j], y = b + dy[j];
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    long long new_idx = (x - 1) * n + y;
                    ex.insert(new_idx);
                }
            }
        }
    }

    cout << n * n - ex.size() << endl;
    return 0;
}