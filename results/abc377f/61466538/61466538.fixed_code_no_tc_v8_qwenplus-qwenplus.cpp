#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ins insert
#define pb push_back

bool inBounds(const pll &p, ll n) {
    return 1 <= p.first && p.first <= n && 1 <= p.second && p.second <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pii> pieces(M);
    set<ll> rows, cols;
    set<ll> diag1, diag2; // i-j and i+j
    set<pll> occupied;

    FOR(i, 0, M) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.ins(a);
        cols.ins(b);
        diag1.ins(a - b);
        diag2.ins(a + b);
        occupied.ins({a, b});
    }

    ll total = N * N - M;

    // Subtract squares attacked by existing pieces via row or column
    total -= (ll)rows.size() * (N - cols.size());
    total -= (ll)cols.size() * (N - rows.size());

    // Now subtract squares attacked via diagonals that are not already covered

    // Handle diagonal i-j
    set<pll> attackedByDiag1;
    for (ll d : diag1) {
        // Number of points on this diagonal
        ll cnt;
        if (d >= -(N - 1) && d <= N - 1) {
            if (abs(d) <= N - 1) {
                cnt = N - abs(d);
            } else {
                cnt = 2 * N - 1 - abs(d);
            }
        } else {
            cnt = 0;
        }

        // Subtract all squares on this diagonal
        total -= cnt;

        // Add back those already counted due to row/col
        // Check intersections with rows and columns
        set<pll> intersection;
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersection.ins({r, c});
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersection.ins({r, c});
            }
        }
        total += intersection.size();
    }

    // Handle diagonal i+j
    set<pll> attackedByDiag2;
    for (ll s : diag2) {
        // Number of points on this diagonal
        ll cnt;
        if (s >= 2 && s <= 2 * N) {
            if (s <= N + 1)
                cnt = s - 1;
            else
                cnt = 2 * N + 1 - s;
        } else {
            cnt = 0;
        }

        // Subtract all squares on this diagonal
        total -= cnt;

        // Add back those already counted due to row/col
        set<pll> intersection;
        for (ll r : rows) {
            ll c = s - r;
            if (1 <= c && c <= N) {
                intersection.ins({r, c});
            }
        }
        for (ll c : cols) {
            ll r = s - c;
            if (1 <= r && r <= N) {
                intersection.ins({r, c});
            }
        }

        // Also consider intersections with the other diagonal
        for (ll od : diag1) {
            // Solve:
            // i + j = s
            // i - j = od
            // => i = (s + od)/2
            // => j = (s - od)/2
            if ((s + od) % 2 == 0) {
                ll i = (s + od) / 2;
                ll j = (s - od) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    intersection.insert({i, j});
                }
            }
        }

        total += intersection.size();
    }

    cout << total << "\n";
    return 0;
}