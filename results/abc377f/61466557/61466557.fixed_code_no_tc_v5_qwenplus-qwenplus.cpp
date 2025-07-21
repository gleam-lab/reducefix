#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    vector<pll> pieces(m);
    for (auto &[x, y] : pieces) {
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    ll total = n * n;
    ll attacked = 0;

    // Rows and columns
    attacked += (ll)rows.size() * n;
    attacked += (ll)cols.size() * n;
    // Subtract overlap of rows and columns
    attacked -= (ll)rows.size() * (ll)cols.size();

    // Diagonal 1: i-j
    for (ll d : diag1) {
        ll count;
        if (n >= abs(d)) {
            count = n - abs(d);
        } else {
            count = 0;
        }
        attacked += count;
    }

    // Diagonal 2: i+j
    for (ll d : diag2) {
        ll count;
        if (d < 2 || d > 2 * n) {
            count = 0;
        } else if (d <= n + 1) {
            count = d - 1;
        } else {
            count = 2 * n - d + 1;
        }
        attacked += count;
    }

    // Remove overlaps between row/col with both diagonals
    set<pll> overlap;

    // Overlap between rows and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            pll p(r, r - d);
            if (inBounds(p, n)) overlap.insert(p);
        }
    }

    // Overlap between cols and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            pll p(c + d, c);
            if (inBounds(p, n)) overlap.insert(p);
        }
    }

    // Overlap between rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            pll p(r, d - r);
            if (inBounds(p, n)) overlap.insert(p);
        }
    }

    // Overlap between cols and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            pll p(d - c, c);
            if (inBounds(p, n)) overlap.insert(p);
        }
    }

    // Overlap between diag1 and diag2 (intersection points)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve:
            // i - j = d1
            // i + j = d2
            // => i = (d1 + d2)/2, j = (d2 - d1)/2
            if ((d1 + d2) % 2 == 0) {
                pll p((d1 + d2) / 2, (d2 - d1) / 2);
                if (inBounds(p, n)) overlap.insert(p);
            }
        }
    }

    // Adjust for overlaps
    attacked -= overlap.size();

    // The final number of safe positions
    ll result = n * n - attacked;

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}