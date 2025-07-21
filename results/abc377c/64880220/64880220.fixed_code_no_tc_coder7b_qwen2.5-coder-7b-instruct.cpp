#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<int, int>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        if (!ex.count(p)) {
            ex[p] = 1;
            ans++;
        }
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            pair<int, int> np = make_pair(x, y);
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                if (!ex.count(np)) {
                    ex[np] = 1;
                    ans++;
                }
            }
        }
    }
    cout << n * n - ans << endl;
    return 0;
}