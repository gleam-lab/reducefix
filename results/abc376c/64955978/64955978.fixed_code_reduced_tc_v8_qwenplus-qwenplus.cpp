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

    multiset<ll> bSet(B.begin(), B.end());

    for (ll i = 0; i < N; ++i) {
        auto it = bSet.lower_bound(A[i]);
        if (it != bSet.end()) {
            bSet.erase(it);
        } else {
            // This toy can only go to the new box
            if (i == N - 1) {
                // Only one toy left, must fit in new box
                cout << A[i] << '\n';
                return;
            } else {
                // Not possible since another toy will be left afterward
                cout << "-1\n";
                return;
            }
        }
    }

    // All toys fit into existing boxes => no need for new box (should not happen)
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}