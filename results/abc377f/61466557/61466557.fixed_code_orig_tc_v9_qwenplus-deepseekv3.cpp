#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll attacked_rows = rows.size() * N;
    ll attacked_cols = cols.size() * N;
    ll attacked_diag1 = 0;
    for (auto d : diag1) {
        ll r = max(1LL, 1 + d);
        ll c = max(1LL, 1 - d);
        ll cnt = min(N - r + 1, N - c + 1);
        if (d <= 0) {
            cnt = min(N - (1 - d), N - (1 + d));
        }
        cnt = N - abs(d);
        attacked_diag1 += cnt;
    }
    ll attacked_diag2 = 0;
    for (auto d : diag2) {
        ll cnt;
        if (d <= N) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d - 1;
        }
        cnt = min(d - 1, 2 * N - d - 1) + 1;
        attacked_diag2 += cnt;
    }

    ll intersection_rows_cols = rows.size() * cols.size();
    ll intersection_rows_diag1 = 0;
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                intersection_rows_diag1++;
            }
        }
    }
    ll intersection_cols_diag1 = 0;
    for (auto d : diag1) {
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                intersection_cols_diag1++;
            }
        }
    }
    ll intersection_rows_diag2 = 0;
    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                intersection_rows_diag2++;
            }
        }
    }
    ll intersection_cols_diag2 = 0;
    for (auto d : diag2) {
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                intersection_cols_diag2++;
            }
        }
    }
    ll intersection_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                intersection_diag1_diag2++;
            }
        }
    }

    ll safe = total 
              - attacked_rows 
              - attacked_cols 
              - attacked_diag1 
              - attacked_diag2 
              + intersection_rows_cols 
              + intersection_rows_diag1 
              + intersection_cols_diag1 
              + intersection_rows_diag2 
              + intersection_cols_diag2 
              - intersection_diag1_diag2;

    set<pair<ll, ll>> queen_set(queens.begin(), queens.end());
    ll queen_count = queen_set.size();
    safe += queen_count; // since queens were subtracted multiple times

    cout << max(0LL, safe) << endl;
    return 0;
}