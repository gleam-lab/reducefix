#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const int MAX_M = 2000;

ll N, M;

set<ll> rows, cols;
set<ll> diag1, diag2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<pll> pieces(M);
    for (auto &[a, b] : pieces) {
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of squares attacked by existing pieces
    ll total_attacked = 0;

    // Count unique rows and columns used
    ll nr = rows.size();
    ll nc = cols.size();
    ll nd1 = diag1.size();
    ll nd2 = diag2.size();

    // Each row covers N cells, each column covers N cells
    total_attacked += nr * N + nc * N;
    // Each diagonal covers varying number of cells:
    // diag1: a - b = const => varies from -(N-1) to N-1
    // diag2: a + b = const => varies from 2 to 2N
    // But we'll just estimate it as N^2 for each since they span up to N^2
    // For this problem, we use inclusion-exclusion instead of precise count

    // Subtract overcounted intersections
    // Row & Column intersections (i.e. occupied cells)
    total_attacked -= M;

    // Row & Diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll b = r - d; // because diag1 = a - b = r - b = d => b = r - d
            if (1 <= b && b <= N)
                total_attacked++;
        }
    }

    // Row & Diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll b = d - r; // diag2 = a + b = r + b = d => b = d - r
            if (1 <= b && b <= N)
                total_attacked++;
        }
    }

    // Column & Diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll a = d + c; // diag1 = a - c = d => a = d + c
            if (1 <= a && a <= N)
                total_attacked++;
        }
    }

    // Column & Diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll a = d - c; // diag2 = a + c = d => a = d - c
            if (1 <= a && a <= N)
                total_attacked++;
        }
    }

    // Diag1 & Diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve:
            // a - b = d1
            // a + b = d2
            // => 2a = d1 + d2 => a = (d1 + d2)/2
            // => 2b = d2 - d1 => b = (d2 - d1)/2
            if ((d1 + d2) % 2 == 0) {
                ll a = (d1 + d2) / 2;
                ll b = (d2 - d1) / 2;
                if (1 <= a && a <= N && 1 <= b && b <= N)
                    total_attacked++;
            }
        }
    }

    // Add back triple overlaps (Row & Col & Diag1), etc.
    // Row & Col & Diag1
    for (auto [a, b] : pieces) {
        if (diag1.count(a - b))
            total_attacked++;
    }

    // Row & Col & Diag2
    for (auto [a, b] : pieces) {
        if (diag2.count(a + b))
            total_attacked++;
    }

    // Row & Diag1 & Diag2
    for (auto r : rows) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                if ((d1 + d2) % 2 == 0) {
                    ll a = (d1 + d2) / 2;
                    ll b = (d2 - d1) / 2;
                    if (a == r && 1 <= a && a <= N && 1 <= b && b <= N)
                        total_attacked++;
                }
            }
        }
    }

    // Col & Diag1 & Diag2
    for (auto c : cols) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                if ((d1 + d2) % 2 == 0) {
                    ll a = (d1 + d2) / 2;
                    ll b = (d2 - d1) / 2;
                    if (b == c && 1 <= a && a <= N && 1 <= b && b <= N)
                        total_attacked++;
                }
            }
        }
    }

    // Subtract quadruple overlaps
    // Row & Col & Diag1 & Diag2
    for (auto [a, b] : pieces) {
        if (diag1.count(a - b) && diag2.count(a + b))
            total_attacked++;
    }

    // Total available positions
    ll total_empty = N * N - M;

    // The answer is total empty squares minus those that are attacked
    ll ans = total_empty - total_attacked;

    cout << ans << endl;

    return 0;
}