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
    for (auto &q : queens) {
        cin >> q.first >> q.second;
    }

    set<ll> rows, cols, diag1, diag2;
    for (auto &q : queens) {
        rows.insert(q.first);
        cols.insert(q.second);
        diag1.insert(q.first - q.second);
        diag2.insert(q.first + q.second);
    }

    ll total = N * N;
    ll row_cnt = rows.size();
    ll col_cnt = cols.size();
    ll diag1_cnt = diag1.size();
    ll diag2_cnt = diag2.size();

    // Subtract rows and columns
    total -= row_cnt * N;
    total -= col_cnt * N;
    total += row_cnt * col_cnt;

    // Subtract diagonals (i - j = d)
    for (auto d : diag1) {
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        total -= cnt;
        // Add intersections with rows and columns
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                total++;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                total++;
            }
        }
        // Subtract double-counted intersections
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N && cols.count(c)) {
                total--;
            }
        }
    }

    // Subtract diagonals (i + j = d)
    for (auto d : diag2) {
        ll i_min = max(1LL, d - N);
        ll i_max = min(N, d - 1);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        total -= cnt;
        // Add intersections with rows and columns
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                total++;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                total++;
            }
        }
        // Subtract double-counted intersections
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N && cols.count(c)) {
                total--;
            }
        }
        // Add intersections with other diagonals (i - j = d2)
        for (auto d1 : diag1) {
            ll i = (d + d1) / 2;
            ll j = (d - d1) / 2;
            if (i + j == d && i - j == d1 && 1 <= i && i <= N && 1 <= j && j <= N) {
                total++;
            }
        }
    }

    // Subtract the queens themselves (they are already occupied)
    total += M;

    cout << total << endl;

    return 0;
}