#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, sum_diag, diff_diag;
    set<pair<ll, ll>> occupied;

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        sum_diag.insert(x + y);
        diff_diag.insert(x - y);
        occupied.insert({x, y});
    }

    // Step 1: Total cells
    ll total = N * N;

    // Step 2: Cells attacked due to rows and columns
    ll attacked_by_rows = rows.size() * N;
    ll attacked_by_cols = cols.size() * N;

    // Step 3: Cells attacked due to diagonals
    auto diag_len = [&](ll d, bool is_sum) {
        if (is_sum) return min(d, 2 * N - d);
        else return min(N + d, N - d);
    };

    ll attacked_by_sum = 0;
    for (ll s : sum_diag) {
        attacked_by_sum += min(s, 2 * N - s);
    }

    ll attacked_by_diff = 0;
    for (ll d : diff_diag) {
        attacked_by_diff += min(N + d, N - d);
    }

    ll attacked = attacked_by_rows + attacked_by_cols + attacked_by_sum + attacked_by_diff;

    // Step 4: Subtract overlaps (Inclusion-Exclusion Principle)
    set<pair<ll, ll>> seen_intersection;

    // Row × Column
    for (ll r : rows) {
        for (ll c : cols) {
            seen_intersection.insert({r, c});
        }
    }

    // Row × Sum Diag
    for (ll r : rows) {
        for (ll s : sum_diag) {
            ll c = s - r;
            if (c >= 1 && c <= N) {
                seen_intersection.insert({r, c});
            }
        }
    }

    // Row × Diff Diag
    for (ll r : rows) {
        for (ll d : diff_diag) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                seen_intersection.insert({r, c});
            }
        }
    }

    // Col × Sum Diag
    for (ll c : cols) {
        for (ll s : sum_diag) {
            ll r = s - c;
            if (r >= 1 && r <= N) {
                seen_intersection.insert({r, c});
            }
        }
    }

    // Col × Diff Diag
    for (ll c : cols) {
        for (ll d : diff_diag) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                seen_intersection.insert({r, c});
            }
        }
    }

    // Sum × Diff Diag
    for (ll s : sum_diag) {
        for (ll d : diff_diag) {
            if ((s + d) % 2 != 0) continue;
            ll r = (s + d) / 2;
            ll c = s - r;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                seen_intersection.insert({r, c});
            }
        }
    }

    // Remove overlaps
    ll overlap = seen_intersection.size();

    // Step 5: Now compute final result
    ll ans = total - attacked + overlap;

    // Remove already occupied cells
    for (auto p : occupied) {
        ll x = p.first, y = p.second;
        if (seen_intersection.count(p)) {
            ans++; // Because it was already removed
        }
    }

    cout << max(0LL, ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}