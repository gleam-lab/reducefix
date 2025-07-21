#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<long long> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<long long> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p = make_pair(a, b);
        if (!ex.count(p)) {
            ex[p] = 1;
            ans++;
            for (long long j = 0; j < 8; j++) {
                long long x = a + dx[j];
                long long y = b + dy[j];
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    pair<long long, long long> np = make_pair(x, y);
                    if (!ex.count(np)) {
                        ex[np] = 1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << n * n - ans << endl;
}