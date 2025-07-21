#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> b_set(B.begin(), B.end());

    ll required = -1;

    // Try to assign toys greedily
    for (ll i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            b_set.erase(it); // Use this box
        } else {
            // We will need to cover this toy with the new box
            required = A[i];
        }
    }

    if (required == -1) {
        // All toys fit in existing boxes, so x can be 0
        cout << 0 << endl;
    } else {
        // The smallest x such that x >= required and not present in B
        cout << required << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}