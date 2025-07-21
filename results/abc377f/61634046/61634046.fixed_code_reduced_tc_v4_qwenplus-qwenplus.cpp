#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<pii> occupied;
    set<ll> rows, cols;
    set<ll> diag1, diag2; // x + y and x - y

    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        occupied.emplace(x, y);
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll totalAttacked = 0;

    // Count attacked cells
    // Rows
    totalAttacked += (ll)rows.size() * N;
    // Cols
    totalAttacked += (ll)cols.size() * N;
    // Diag1 (x + y)
    for (ll d : diag1) {
        ll cnt;
        if (d < 2 || d > 2 * N) continue;
        if (d <= N + 1)
            cnt = d - 1;
        else
            cnt = 2 * N + 1 - d;
        totalAttacked += cnt;
    }
    // Diag2 (x - y)
    for (ll d : diag2) {
        ll cnt;
        if (d < -(N - 1) || d > N - 1) continue;
        if (d < 0)
            cnt = N + d;
        else
            cnt = N - d;
        totalAttacked += cnt;
    }

    // Subtract overlaps
    // Row-Column intersections (occupied cells)
    for (auto [x, y] : occupied)
        --totalAttacked;

    // Row-Diag1 overlaps
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N)
                --totalAttacked;
        }
    }

    // Row-Diag2 overlaps
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N)
                --totalAttacked;
        }
    }

    // Col-Diag1 overlaps
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N)
                --totalAttacked;
        }
    }

    // Col-Diag2 overlaps
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d + c;
            if (1 <= r && r <= N)
                --totalAttacked;
        }
    }

    // Diag1-Diag2 overlaps
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N)
                --totalAttacked;
        }
    }

    // Add back triple overlaps (we subtracted them 3 times but should have only subtracted once)
    // Row-Col-Diag1 overlaps
    for (auto [r, c] : occupied) {
        ll d1 = r + c;
        for (ll d : diag1) {
            if (d == d1)
                ++totalAttacked;
        }
    }

    // Row-Col-Diag2 overlaps
    for (auto [r, c] : occupied) {
        ll d2 = r - c;
        for (ll d : diag2) {
            if (d == d2)
                ++totalAttacked;
        }
    }

    // Row-Diag1-Diag2 overlaps
    for (ll r : rows) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll c1 = d1 - r;
                ll c2 = r - d2;
                if (c1 == c2 && 1 <= c1 && c1 <= N)
                    ++totalAttacked;
            }
        }
    }

    // Col-Diag1-Diag2 overlaps
    for (ll c : cols) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll r1 = d1 - c;
                ll r2 = d2 + c;
                if (r1 == r2 && 1 <= r1 && r1 <= N)
                    ++totalAttacked;
            }
        }
    }

    // Subtract quadruple overlaps (we added them back too many times)
    for (auto [r, c] : occupied) {
        ll d1 = r + c;
        ll d2 = r - c;
        bool inDiag1 = diag1.find(d1) != diag1.end();
        bool inDiag2 = diag2.find(d2) != diag2.end();
        if (inDiag1 && inDiag2)
            --totalAttacked;
    }

    ll totalEmpty = N * N - M;
    ll answer = totalEmpty - totalAttacked;
    cout << answer << endl;

    return 0;
}