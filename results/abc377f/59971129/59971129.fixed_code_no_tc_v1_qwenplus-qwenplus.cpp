#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2;  // diag1: i-j, diag2: i+j

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total empty squares not in any attacked row or column
    ll ans = (N - rows.size()) * (N - cols.size());

    // Now we need to subtract the number of cells that are on some diagonal and also not already blocked by row/col
    set<pair<ll, ll>> attacked_cells;

    // Process diag1: i - j = c
    for (ll c : diag1) {
        // Equation: i - j = c => i = j + c
        ll low_j = max(1LL, 1LL - c);
        ll high_j = min(N, N - c);
        if (low_j <= high_j) {
            ll cnt = high_j - low_j + 1;
            ans -= cnt;
        }
    }

    // Process diag2: i + j = d
    for (ll d : diag2) {
        // Equation: i + j = d => i = d - j
        ll low_j = max(1LL, d - N);
        ll high_j = min(N, d - 1);
        if (low_j <= high_j) {
            ll cnt = high_j - low_j + 1;
            ans -= cnt;
        }
    }

    // Now add back the intersections (inclusion-Exclusion Principle)
    // Cells that were counted twice because they lie on both a forbidden diagonal from diag1 and diag2

    // For each pair of diagonals from diag1 and diag2
    for (ll c : diag1) {
        for (ll d : diag2) {
            // Solve:
            // i - j = c
            // i + j = d
            // => 2i = c + d => i = (c + d)/2
            // => 2j = d - c => j = (d - c)/2
            ll i = c + d;
            ll j = d - c;
            if (i % 2 == 0 && j % 2 == 0) {
                i /= 2;
                j /= 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    // This cell is intersection of two diagonals
                    // If it was already subtracted above, add it back once
                    if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                        ans += 1;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}