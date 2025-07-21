#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N + 1), B(N);
    for (ll i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (ll i = 1; i < N; ++i) {
        cin >> B[i];
    }
    
    // Sort the toy sizes in descending order and the box sizes in ascending order
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    
    // The minimum box size required is at least as large as the largest toy size
    ll min_box_size = A[1];
    ll possible_box_size = min_box_size;
    
    // Check if we can fit each toy in a box without exceeding the box size
    for (ll i = 1; i < N; ++i) {
        if (A[i] > B[i - 1]) {
            // If the current toy cannot fit in the previous box, we need a larger box
            possible_box_size = max(possible_box_size, A[i]);
        }
    }
    
    // Output the minimum box size that can fit all toys
    if (possible_box_size <= B[N - 2] || possible_box_size == A[1]) {
        cout << possible_box_size << endl;
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