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
    
    // We need to find the minimum box size x such that all toys can be placed in boxes of size <= x.
    ll min_x = 0;
    for (ll i = 0; i < N; i++) {
        // We need to find the maximum box size that can contain the i-th toy and is less than or equal to any existing box size.
        ll max_box_size = 0;
        for (ll j = 0; j < N-1; j++) {
            if (A[i] <= B[j]) {
                max_box_size = max(max_box_size, B[j]);
            }
        }
        // If there is no box of an appropriate size, we need to increase x.
        if (max_box_size == 0) {
            min_x = A[i];
            break;
        }
    }
    
    // We also need to consider the possibility that the smallest box size might be larger than the smallest toy size.
    for (ll i = 0; i < N; i++) {
        if (A[i] > min_x) {
            min_x = A[i];
        }
    }
    
    // Finally, we take the maximum of all these to ensure all toys can be placed.
    min_x = max(min_x, *max_element(B.begin(), B.end()));
    
    cout << min_x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}