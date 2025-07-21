#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll total = N * N;
    ll forbidden = 0;

    // Calculate forbidden squares due to rows and columns
    forbidden += rows.size() * N;
    forbidden += cols.size() * (N - rows.size());

    // Calculate forbidden squares due to diagonals (i+j)
    for (auto d : diag1) {
        ll min_i = max(1LL, d - N);
        ll max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        ll count = max_i - min_i + 1;
        forbidden += count;
        // Subtract overlaps with rows and columns
        for (ll i = min_i; i <= max_i; ++i) {
            ll j = d - i;
            if (rows.count(i) || cols.count(j)) {
                forbidden--;
            }
        }
    }

    // Calculate forbidden squares due to diagonals (i-j)
    for (auto d : diag2) {
        ll min_i = max(1LL, 1 + d);
        ll max_i = min(N, N + d);
        if (min_i > max_i) continue;
        ll count = max_i - min_i + 1;
        forbidden += count;
        // Subtract overlaps with rows, columns, and other diagonals
        for (ll i = min_i; i <= max_i; ++i) {
            ll j = i - d;
            if (rows.count(i) || cols.count(j) || diag1.count(i + j)) {
                forbidden--;
            }
        }
    }

    // The safe squares are total minus forbidden, plus any overlaps subtracted twice
    // But since overlaps are already subtracted, forbidden is the correct count
    ll safe = total - forbidden;
    cout << safe << endl;
    return 0;
}