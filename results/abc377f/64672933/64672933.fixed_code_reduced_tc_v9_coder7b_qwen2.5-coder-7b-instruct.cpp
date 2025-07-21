#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> A, B, C, D;
    unordered_set<ll> unique_A, unique_B, unique_C, unique_D;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        C.push_back(a + b);
        D.push_back(a - b);
        
        unique_A.insert(a);
        unique_B.insert(b);
        unique_C.insert(a + b);
        unique_D.insert(a - b);
    }

    ll total_squares = N * N;
    ll capturable_squares = 0;

    // Rows
    for (ll i = 1; i <= N; ++i) {
        if (!unique_A.count(i)) {
            capturable_squares++;
        }
    }

    // Columns
    for (ll i = 1; i <= N; ++i) {
        if (!unique_B.count(i)) {
            capturable_squares++;
        }
    }

    // Diagonals: i + j = constant
    for (ll sum = 2; sum <= 2 * N - 1; ++sum) {
        if (!unique_C.count(sum)) {
            capturable_squares++;
        }
    }

    // Diagonals: i - j = constant
    for (ll diff = -(N - 1); diff <= N - 1; ++diff) {
        if (!unique_D.count(diff)) {
            capturable_squares++;
        }
    }

    // Double-counted corners
    capturable_squares--;

    cout << total_squares - capturable_squares << endl;

    return 0;
}