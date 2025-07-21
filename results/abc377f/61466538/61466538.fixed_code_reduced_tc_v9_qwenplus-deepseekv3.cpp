#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (const auto& queen : queens) {
        ll i = queen.first;
        ll j = queen.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size();

    // Diagonals (i - j = d)
    for (ll d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }

    // Anti-diagonals (i + j = d)
    for (ll d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Subtract overlaps between diagonals and rows/columns
    for (ll d : diag1) {
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }

    for (ll d : diag2) {
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }

    // Subtract overlaps between diagonals (i-j=d1) and anti-diagonals (i+j=d2)
    unordered_set<pll> intersections;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    intersections.insert({i, j});
                }
            }
        }
    }
    attacked -= intersections.size();

    // Add back the squares that were subtracted multiple times (queens themselves)
    attacked += M;

    ll safe = total - attacked;
    cout << safe << endl;

    return 0;
}