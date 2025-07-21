#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    vector<ll> B(N - 1);
    
    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Use a multiset to efficiently remove matched boxes
    multiset<ll> boxSizes;
    for (ll b : B) boxSizes.insert(b);

    ll maxUnmatchedToy = -1;

    ll j = 0; // pointer for B
    for (ll i = 0; i < N; ++i) {
        // Try to place A[i] into the smallest available box >= A[i]
        auto it = boxSizes.lower_bound(A[i]);
        if (it != boxSizes.end()) {
            boxSizes.erase(it); // use this box
        } else {
            // Cannot place in existing boxes: this toy must go into the new box
            maxUnmatchedToy = max(maxUnmatchedToy, A[i]);
        }
    }

    if (maxUnmatchedToy == -1) {
        cout << -1 << endl;
    } else {
        cout << maxUnmatchedToy << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}