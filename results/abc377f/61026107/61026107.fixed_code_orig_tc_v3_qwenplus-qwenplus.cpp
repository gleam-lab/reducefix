#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    ll attacked = 0;

    // Count row attacks
    attacked += rows.size() * N;

    // Count column attacks
    attacked += cols.size() * N;

    // Count diagonal 1 attacks (x - y)
    for (auto d : diag1) {
        ll count = N - abs(d);
        if (count > 0) attacked += count;
    }

    // Count diagonal 2 attacks (x + y)
    for (auto d : diag2) {
        ll count = N - abs(N - d);
        if (count > 0) attacked += count;
    }

    // Inclusion-Exclusion Principle

    // Subtract intersections of row & col
    for (auto r : rows) {
        for (auto c : cols) {
            if ((r >= 1 && r <= N) && (c >= 1 && c <= N)) {
                if (diag1.count(r - c) || diag2.count(r + c)) {
                    attacked--;
                }
            }
        }
    }

    // Subtract intersections of row & diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }

    // Subtract intersections of row & diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }

    // Subtract intersections of col & diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }

    // Subtract intersections of col & diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }

    // Subtract intersections of diag1 & diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = d2 - r;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                attacked--;
            }
        }
    }

    // Add back intersections of row & col & diag1
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            if (diag1.count(d1)) {
                attacked++;
            }
        }
    }

    // Add back intersections of row & col & diag2
    for (auto r : rows) {
        for (auto c : cols) {
            ll d2 = r + c;
            if (diag2.count(d2)) {
                attacked++;
            }
        }
    }

    // Add back intersections of row & diag1 & diag2
    for (auto r : rows) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll c1 = r - d1;
                if (c1 >= 1 && c1 <= N && d2 == r + c1) {
                    attacked++;
                }
            }
        }
    }

    // Add back intersections of col & diag1 & diag2
    for (auto c : cols) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll r1 = d1 + c;
                if (r1 >= 1 && r1 <= N && d2 == r1 + c) {
                    attacked++;
                }
            }
        }
    }

    // Subtract intersections of row & col & diag1 & diag2
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            ll d2 = r + c;
            if (diag1.count(d1) && diag2.count(d2)) {
                attacked--;
            }
        }
    }

    ll totalEmpty = N * N - attacked;
    cout << totalEmpty << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}