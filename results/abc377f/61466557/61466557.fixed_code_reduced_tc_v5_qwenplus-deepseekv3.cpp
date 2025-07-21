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
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        diag1.insert(queens[i].first - queens[i].second);
        diag2.insert(queens[i].first + queens[i].second);
    }

    ll total = N * N;
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll row_col_intersect = rows.size() * cols.size();

    ll diag1_attacks = 0;
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        diag1_attacks += cnt;
    }

    ll diag2_attacks = 0;
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        diag2_attacks += cnt;
    }

    total -= row_attacks;
    total -= col_attacks;
    total += row_col_intersect;

    set<pll> attacked_by_diag1;
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                attacked_by_diag1.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                attacked_by_diag1.insert({r, c});
            }
        }
    }

    total -= diag1_attacks;
    total += attacked_by_diag1.size();

    set<pll> attacked_by_diag2;
    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                attacked_by_diag2.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                attacked_by_diag2.insert({r, c});
            }
        }
        for (auto d1 : diag1) {
            ll r = (d + d1) / 2;
            ll c = (d - d1) / 2;
            if ((d + d1) % 2 == 0 && (d - d1) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                attacked_by_diag2.insert({r, c});
            }
        }
    }

    total -= diag2_attacks;
    total += attacked_by_diag2.size();

    set<pll> all_queens(queens.begin(), queens.end());
    total += all_queens.size();

    cout << total << endl;

    return 0;
}