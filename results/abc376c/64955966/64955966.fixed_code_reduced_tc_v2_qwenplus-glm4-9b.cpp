#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N-1; i++) {
        cin >> B[i];
    }
    
    // Find the maximum size in B that contains all toys up to index i
    vector<ll> maxB(N);
    ll maxBSize = 0;
    for (ll i = 0; i < N-1; i++) {
        maxBSize = max(maxBSize, B[i]);
    }
    maxB[N-1] = maxBSize;

    // Find the minimum box size x that can contain all toys
    ll minBoxSize = 0;
    for (ll i = 0; i < N; i++) {
        minBoxSize = max(minBoxSize, A[i]);
        minBoxSize = max(minBoxSize, maxB[i]);
    }
    
    // Output the result
    if (minBoxSize != 0) {
        cout << minBoxSize << endl;
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