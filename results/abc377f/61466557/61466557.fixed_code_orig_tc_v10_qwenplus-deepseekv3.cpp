#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pieces(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diag1.insert(pieces[i].first - pieces[i].second);
        diag2.insert(pieces[i].first + pieces[i].second);
    }

    ll total = N * N;
    
    // Subtract rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    total -= row_count * N;
    total -= col_count * N;
    total += row_count * col_count;

    // Subtract diagonals i-j (d1)
    for (ll d : diag1) {
        // Number of squares on diagonal i - j = d
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total -= cnt;

        // Add back intersections with rows and columns
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                total++;
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                total++;
            }
        }

        // Subtract the intersections added twice (if any)
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N && cols.count(c)) {
                total--;
            }
        }
    }

    // Subtract diagonals i+j (d2)
    for (ll d : diag2) {
        // Number of squares on diagonal i + j = d
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total -= cnt;

        // Add back intersections with rows and columns
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                total++;
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                total++;
            }
        }

        // Subtract the intersections added twice (if any)
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N && cols.count(c)) {
                total--;
            }
        }
    }

    // Add intersections between d1 and d2 diagonals that were subtracted twice
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d2 + d1) % 2 != 0) continue;
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                total++;
            }
        }
    }

    // Subtract the squares occupied by existing pieces if they were not already subtracted
    total -= M;

    cout << total << endl;

    return 0;
}