#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    unordered_set<ll> rows, cols, sums, diffs;
    vector<pair<ll, ll>> pieces(M);
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        sums.insert(a + b);
        diffs.insert(a - b);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N + cols.size() * N - rows.size() * cols.size();

    // Sum and difference diagonals
    for (ll s : sums) {
        ll start_i = max(1LL, s - N);
        ll end_i = min(N, s - 1);
        if (start_i > end_i) continue;
        unsafe += end_i - start_i + 1;
    }

    for (ll d : diffs) {
        ll start_i = max(1LL, 1 - d);
        ll end_i = min(N, N - d);
        if (start_i > end_i) continue;
        unsafe += end_i - start_i + 1;
    }

    // Overlap between sum and difference diagonals
    for (ll s : sums) {
        for (ll d : diffs) {
            if ((s + d) % 2 != 0) continue;
            ll i = (s + d) / 2;
            ll j = (s - d) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between rows and sum/difference diagonals
    for (ll a : rows) {
        for (ll s : sums) {
            ll b = s - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
        for (ll d : diffs) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between columns and sum/difference diagonals
    for (ll b : cols) {
        for (ll s : sums) {
            ll a = s - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
        for (ll d : diffs) {
            ll a = b + d;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between rows, columns, and diagonals
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && sums.count(a + b) && diffs.count(a - b)) {
            unsafe += 3;
        } else if (rows.count(a) && cols.count(b) && (sums.count(a + b) || diffs.count(a - b))) {
            unsafe += 1;
        }
    }

    ll total = N * N;
    ll safe = total - unsafe;

    cout << safe << endl;

    return 0;
}