#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MAX_M 1000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // x + y and x - y

    vector<pii> pieces(M);
    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};

        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total squares - occupied squares
    ll total_empty = N * N - M;

    // Count how many squares are attacked
    ll attacked_squares = 0;

    // Row attack
    attacked_squares += (ll)rows.size() * N;
    // Column attack
    attacked_squares += (ll)cols.size() * N;

    // Diagonal attacks: x+y = c
    attacked_squares += (ll)diag1.size() * N;
    // Anti-diagonal attacks: x-y = c
    attacked_squares += (ll)diag2.size() * N;

    // Subtract overlaps

    // Row-Column overlap (occupied squares)
    for (auto x : rows) {
        for (auto y : cols) {
            attacked_squares--;
        }
    }

    // Row-Diag1 overlap
    for (auto x : rows) {
        for (auto d : diag1) {
            ll y = d - x;
            if (1 <= y && y <= N) {
                attacked_squares--;
            }
        }
    }

    // Row-Diag2 overlap
    for (auto x : rows) {
        for (auto d : diag2) {
            ll y = x - d;
            if (1 <= y && y <= N) {
                attacked_squares--;
            }
        }
    }

    // Col-Diag1 overlap
    for (auto y : cols) {
        for (auto d : diag1) {
            ll x = d - y;
            if (1 <= x && x <= N) {
                attacked_squares--;
            }
        }
    }

    // Col-Diag2 overlap
    for (auto y : cols) {
        for (auto d : diag2) {
            ll x = d + y;
            if (1 <= x && x <= N) {
                attacked_squares--;
            }
        }
    }

    // Diag1-Diag2 overlap
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = d1 - x;
            if (x >= 1 && x <= N && y >= 1 && y <= N && (x + y == d1) && (x - y == d2)) {
                attacked_squares--;
            }
        }
    }

    // Add back triple overlaps
    for (auto x : rows) {
        for (auto y : cols) {
            ll d1 = x + y;
            ll d2 = x - y;
            if (diag1.count(d1) && diag2.count(d2)) {
                attacked_squares++;
            }
        }
    }

    // Final count of safe empty squares
    ll answer = total_empty - attacked_squares;
    cout << answer << endl;

    return 0;
}