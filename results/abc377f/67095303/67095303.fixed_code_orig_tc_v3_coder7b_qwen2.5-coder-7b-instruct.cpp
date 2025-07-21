#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;

    set<long long> horizontal, vertical, diag1, diag2;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting indices to zero-based for easier calculations
        horizontal.insert(a);
        vertical.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    long long ans = (n - horizontal.size()) * (n - vertical.size());

    for (auto d : diag1) {
        set<long long> s;
        for (auto x : horizontal) {
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }
        for (auto y : vertical) {
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }
        long long len = 0;
        if (d <= n + 1) {
            len = d - 1;
        } else {
            len = n - (d - n) + 1;
        }
        ans -= (len - s.size());
    }

    for (auto d : diag2) {
        set<long long> s;
        for (auto x : horizontal) {
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }
        for (auto y : vertical) {
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }
        for (auto e : diag1) {
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                long long si = (e + d) / 2, sj = (e - d) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }
        long long len = 0;
        if (d <= 0) {
            len = n - (1 - d) + 1;
        } else {
            len = n - d;
        }
        ans -= (len - s.size());
    }

    cout << ans << '\n';

    return 0;
}