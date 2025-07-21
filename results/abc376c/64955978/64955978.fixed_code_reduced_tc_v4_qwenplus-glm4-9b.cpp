#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "-1\n"
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    ll min_x = LLONG_MAX; // Initialize with maximum possible value
    ll i = 0, j = 0;
    
    // Find the minimum x by iterating through the sorted toy sizes and box sizes
    while (i < N && j < N - 1) {
        // Try to place the current toy in the current box
        if (A[i] <= B[j]) {
            min_x = min(min_x, B[j]); // This box size can be the new minimum x
            j++; // Move to the next box
        } else {
            i++; // Move to the next toy
        }
    }
    
    if (i == N) {
        // If we have processed all toys, then we need to check the last box
        if (min_x == LLONG_MAX) {
            // If no box can accommodate the last toy, print -1
            no;
        } else {
            // Otherwise, print the minimum x found
            cout << min_x << endl;
        }
    } else {
        // If we have not processed all toys, then it's impossible to place all toys
        no;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}