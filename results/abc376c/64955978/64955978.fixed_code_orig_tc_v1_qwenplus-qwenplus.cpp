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
    ll idx = 0;
    for (ll i = 0; i < N - 1; ++i) {
        while (idx < N && A[idx] <= B[i]) {
            bSet.insert(B[i]);
            idx++;
            if (idx >= N) break;
        }
        auto it = bSet.lower_bound(A[i]);
        if (it == bSet.end()) {
            cout << -1 << endl;
            return;
        }
        bSet.erase(it);
    }

    if (!bSet.empty()) {
        cout << *bSet.begin() << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}