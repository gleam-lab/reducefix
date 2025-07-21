#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// F - Avoid Queen Attack
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    for (ll i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    set<ll> row, col;
    set<ll> diag1, diag2;

    for (auto [i, j] : q) {
        row.insert(i);
        col.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    // Total squares under attack from rows and columns
    ll attacked_by_row_or_col = (ll)row.size() * n + (ll)col.size() * n - (ll)row.size() * (ll)col.size();

    // Now subtract overlaps with diagonals
    ll attacked_by_diag1 = 0;
    map<ll, set<pll>> diag1_intersections;

    for (ll d : diag1) {
        // Count how many squares on this diagonal intersect with attacked rows or cols
        set<pll> intersections;
        for (ll r : row) {
            pll p = {r, r - d};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (ll c : col) {
            pll p = {c + d, c};
            if (inBounds(p, n)) intersections.insert(p);
        }
        diag1_intersections[d] = intersections;
    }

    ll total_diag1 = 0;
    for (ll d : diag1) {
        ll cnt = n - abs(d);
        total_diag1 += cnt;
    }

    ll overlap_diag1 = 0;
    for (auto &[d, pts] : diag1_intersections) {
        overlap_diag1 += pts.size();
    }

    ll attacked_by_diag2 = 0;
    map<ll, set<pll>> diag2_intersections;

    for (ll d : diag2) {
        set<pll> intersections;
        for (ll r : row) {
            pll p = {r, d - r};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (ll c : col) {
            pll p = {d - c, c};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (ll od : diag1) {
            if ((d + od) % 2 == 1) continue;
            pll p = {(d + od) / 2, (d - od) / 2};
            if (inBounds(p, n)) intersections.insert(p);
        }
        diag2_intersections[d] = intersections;
    }

    ll total_diag2 = 0;
    for (ll d : diag2) {
        if (d <= n)
            total_diag2 += d - 1;
        else
            total_diag2 += 2 * n - d + 1;
    }

    ll overlap_diag2 = 0;
    for (auto &[d, pts] : diag2_intersections) {
        overlap_diag2 += pts.size();
    }

    ll ans = n * n;
    ans -= attacked_by_row_or_col;
    ans -= total_diag1 + total_diag2;
    ans += overlap_diag1 + overlap_diag2;

    // Also subtract pieces that are already occupied
    for (auto [i, j] : q) {
        set<pll> blocked;
        blocked.insert({i, j});
        if (row.count(i) || col.count(j) || diag1.count(i - j) || diag2.count(i + j)) {
            ans -= 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}