#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll forbidden = 0;
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        forbidden += cnt;
    }
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        forbidden += cnt;
    }

    // Now subtract the overlaps counted multiple times
    set<pair<ll, ll>> intersections;
    for (auto r : rows) {
        for (auto c : cols) {
            intersections.insert({r, c});
        }
    }
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    forbidden -= intersections.size();

    ll total_squares = N * N;
    ll safe_squares = total_squares - forbidden;
    cout << safe_squares << "\n";
    return 0;
}