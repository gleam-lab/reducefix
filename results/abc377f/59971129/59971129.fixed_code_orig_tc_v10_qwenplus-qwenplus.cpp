#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2; // diag1: i-j, diag2: i+j

    for (ll i = 0; i < M; ++i) {
        ll r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);
        diag2.insert(r + c);
    }

    ll ans = N * N;
    ans -= (ll)rows.size() * N;
    ans -= (ll)cols.size() * N;
    ans += (ll)rows.size() * (ll)cols.size(); // subtract overlap

    // For each diagonal line (r - c = d)
    for (ll d : diag1) {
        ll len = N - abs(d);
        if (len <= 0) continue;
        ans -= len;
        // subtract overlaps with rows and cols
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) ans += 1;
        }
    }

    // For each anti-diagonal line (r + c = d)
    for (ll d : diag2) {
        ll len = N - abs(d - (N + 1));
        if (len <= 0) continue;
        ans -= len;
        // subtract overlaps with rows and cols
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) ans += 1;
        }
    }

    cout << max(0LL, ans) << endl;
}