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

    multiset<ll> bSet;
    for (ll i = 0; i < N - 1; ++i) {
        bSet.insert(B[i]);
    }

    for (ll i = 0; i < N; ++i) {
        auto it = bSet.lower_bound(A[i]);
        if (it != bSet.end()) {
            bSet.erase(it);
        } else {
            // Cannot fit this toy, so this is the smallest box needed
            cout << A[i] << endl;
            return;
        }
    }

    // All toys can be placed in existing boxes
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}