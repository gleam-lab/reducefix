#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    bool operator<(const Point& rhs) const {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols;
    set<ll> diag1, diag2;

    vector<Point> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Total squares = N^2
    ll total = n * n;

    // Subtract all squares under attack by any of the four directions
    ll attacked = 0;

    attacked += (ll)rows.size() * n;
    attacked += (ll)cols.size() * n;

    for (auto d : diag1) {
        // For diagonal x - y = d, number of points is N - abs(d)
        attacked += n - abs(d);
    }

    for (auto d : diag2) {
        // For diagonal x + y = d, number of points is N - abs(n - d)
        attacked += n - abs(n - d);
    }

    // Inclusion-Exclusion: subtract overcounts where two or more attack patterns overlap

    set<pair<ll, ll>> rc_pairs;
    for (auto r : rows) {
        for (auto c : cols) {
            rc_pairs.emplace(r, c);
        }
    }

    set<tuple<ll, ll, ll>> rcd1_triples;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c >= 1 && c <= n) {
                rcd1_triples.emplace(r, c, d1);
            }
        }
    }

    set<tuple<ll, ll, ll>> rcd2_triples;
    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c >= 1 && c <= n) {
                rcd2_triples.emplace(r, c, d2);
            }
        }
    }

    set<tuple<ll, ll, ll>> cld1_triples;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = d1 + c;
            if (r >= 1 && r <= n) {
                cld1_triples.emplace(r, c, d1);
            }
        }
    }

    set<tuple<ll, ll, ll>> cld2_triples;
    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r >= 1 && r <= n) {
                cld2_triples.emplace(r, c, d2);
            }
        }
    }

    set<tuple<ll, ll, ll>> d1d2_pairs;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = d2 - r;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                d1d2_pairs.emplace(r, c, d1);
            }
        }
    }

    // Add back double-counted intersections
    attacked -= rc_pairs.size();

    attacked -= rcd1_triples.size();
    attacked -= rcd2_triples.size();
    attacked -= cld1_triples.size();
    attacked -= cld2_triples.size();
    attacked -= d1d2_pairs.size();

    // Subtract triple overlaps
    set<tuple<ll, ll, ll>> triple_overlap;
    for (auto [r, c, d1] : rcd1_triples) {
        if (diag2.count(r + c)) {
            triple_overlap.emplace(r, c, d1);
        }
    }

    for (auto [r, c, d2] : rcd2_triples) {
        if (diag1.count(r - c)) {
            triple_overlap.emplace(r, c, r - c);
        }
    }

    for (auto [r, c, d1] : cld1_triples) {
        if (diag2.count(r + c)) {
            triple_overlap.emplace(r, c, r - c);
        }
    }

    for (auto [r, c, d2] : cld2_triples) {
        if (diag1.count(r - c)) {
            triple_overlap.emplace(r, c, r - c);
        }
    }

    for (auto [r, c, d1] : d1d2_pairs) {
        if (rows.count(r) || cols.count(c)) {
            triple_overlap.emplace(r, c, d1);
        }
    }

    attacked += triple_overlap.size();

    // Add back over-subtracted quadruple overlaps
    set<Point> quad_overlap;
    for (auto [r, c, _] : triple_overlap) {
        if (rows.count(r) && cols.count(c) && diag1.count(r - c) && diag2.count(r + c)) {
            quad_overlap.insert({r, c});
        }
    }

    attacked -= quad_overlap.size();

    // Now subtract occupied positions
    for (auto [x, y] : pieces) {
        if (!(rows.count(x) || cols.count(y) || diag1.count(x - y) || diag2.count(x + y))) {
            attacked -= 1; // If this square was not already counted in attacked
        }
    }

    // Finally, subtract occupied squares from available empty ones
    ll result = n * n - attacked - m;

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while (NT--) solve();
    return 0;
}