#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N - 1);
    
    // Reading the sizes of toys and boxes
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    // Sort the toy sizes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    // Sort the box sizes in descending order
    sort(B.begin(), B.end(), greater<ll>());
    
    // Initialize the minimum box size to -1
    ll min_box_size = -1;
    
    // Iterate over each toy and find the smallest box that can fit it
    for (ll i = 0; i < N; i++) {
        // Since the list of box sizes is sorted, use binary search to find the minimum box size
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        // If the iterator points to the end, it means no box can fit this toy
        if (it == B.end()) {
            cout << -1 << endl;
            return;
        }
        // Update the minimum box size if it's not already set
        if (min_box_size == -1 || *it < min_box_size) {
            min_box_size = *it;
        }
    }
    
    // If we found at least one box that can fit all toys
    if (min_box_size != -1) {
        cout << min_box_size << endl;
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