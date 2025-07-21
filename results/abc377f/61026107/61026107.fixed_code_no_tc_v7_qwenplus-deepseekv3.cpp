#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include<debug.h>
#else
#define dump(...)
#endif

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: x - y, diag2: x + y
    for (int i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll unsafe = 0;

    // Rows and columns: each covers N positions; overlaps subtracted later
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;

    // Diagonals: each covers N - |k| positions for x-y=k, or N - |k - (N+1)| for x+y=k
    for (auto k : diag1) {
        ll cnt;
        if (k >= 0) {
            cnt = n - k;
        } else {
            cnt = n + k;
        }
        unsafe += cnt;
    }
    for (auto k : diag2) {
        ll cnt;
        if (k <= n + 1) {
            cnt = k - 1;
        } else {
            cnt = 2 * n - k + 1;
        }
        unsafe += cnt;
    }

    // Overlaps between rows and columns: each intersection is (a, b)
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b) && diag2.count(a + b)) {
                unsafe -= 2; // counted in rows, cols, diag1, diag2 => 4 times, but actual is 1
            } else if (diag1.count(a - b) || diag2.count(a + b)) {
                unsafe -= 1; // counted in rows/cols and one diagonal => 2 times, actual is 1
            }
        }
    }

    // Overlaps between rows and diag1: (a, b) where b = a - k
    for (auto a : rows) {
        for (auto k : diag1) {
            ll b = a - k;
            if (b >= 1 && b <= n) {
                if (cols.count(b) && diag2.count(a + b)) {
                    unsafe -= 0; // already handled in row-col intersection
                } else if (cols.count(b)) {
                    unsafe -= 1;
                } else if (diag2.count(a + b)) {
                    unsafe -= 1;
                }
            }
        }
    }

    // Overlaps between rows and diag2: (a, b) where b = k - a
    for (auto a : rows) {
        for (auto k : diag2) {
            ll b = k - a;
            if (b >= 1 && b <= n) {
                if (cols.count(b) && diag1.count(a - b)) {
                    unsafe -= 0; // already handled in row-col intersection
                } else if (cols.count(b)) {
                    unsafe -= 1;
                } else if (diag1.count(a - b)) {
                    unsafe -= 1;
                }
            }
        }
    }

    // Overlaps between columns and diag1: (a, b) where a = b + k
    for (auto b : cols) {
        for (auto k : diag1) {
            ll a = b + k;
            if (a >= 1 && a <= n) {
                if (rows.count(a) && diag2.count(a + b)) {
                    unsafe -= 0; // already handled in row-col intersection
                } else if (rows.count(a)) {
                    unsafe -= 1;
                } else if (diag2.count(a + b)) {
                    unsafe -= 1;
                }
            }
        }
    }

    // Overlaps between columns and diag2: (a, b) where a = k - b
    for (auto b : cols) {
        for (auto k : diag2) {
            ll a = k - b;
            if (a >= 1 && a <= n) {
                if (rows.count(a) && diag1.count(a - b)) {
                    unsafe -= 0; // already handled in row-col intersection
                } else if (rows.count(a)) {
                    unsafe -= 1;
                } else if (diag1.count(a - b)) {
                    unsafe -= 1;
                }
            }
        }
    }

    // Overlaps between diag1 and diag2: (a, b) where a = (k1 + k2)/2, b = (k2 - k1)/2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 != 0) continue;
            ll a = (k1 + k2) / 2;
            ll b = (k2 - k1) / 2;
            if (a >= 1 && a <= n && b >= 1 && b <= n) {
                if (rows.count(a) && cols.count(b)) {
                    unsafe -= 0; // already handled in row-col intersection
                } else if (rows.count(a)) {
                    unsafe -= 1;
                } else if (cols.count(b)) {
                    unsafe -= 1;
                }
            }
        }
    }

    ll total = n * n;
    ll safe = total - unsafe;
    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}