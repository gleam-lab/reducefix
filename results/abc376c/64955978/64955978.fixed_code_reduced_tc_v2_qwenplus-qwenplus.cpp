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

    ll res = -1;

    for (ll i = 0; i < N; ++i) {
        auto it = bSet.lower_bound(A[i]);
        if (it != bSet.end()) {
            // We can use this box for toy A[i]
            bSet.erase(it);
        } else {
            // Cannot place this toy, we need to buy a new box of at least A[i]
            if (res == -1)
                res = A[i];
            else
                res = min(res, A[i]);
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}