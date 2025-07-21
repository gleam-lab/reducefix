#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    unordered_set<long long> ex;
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        long long key = ((a - 1) * n + b - 1);
        if (!ex.count(key)) {
            ex.insert(key);
            ans++;
        }
        for (int dx = -2; dx <= 2; dx += 1) {
            for (int dy = -2; dy <= 2; dy += 1) {
                if (abs(dx) == abs(dy)) continue;
                long long x = a + dx, y = b + dy;
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    long long newKey = ((x - 1) * n + y - 1);
                    if (!ex.count(newKey)) {
                        ex.insert(newKey);
                        ans++;
                    }
                }
            }
        }
    }
    cout << n * n - ans << endl;
    return 0;
}