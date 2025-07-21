#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    
    // Read toy sizes
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read box sizes
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    // Sort toy sizes and box sizes in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    ll min_x = LLONG_MAX;
    bool can_store_all = true;
    
    // Try to place each toy in the smallest possible box
    for (int i = 0; i < N; ++i) {
        if (i < N - 1 && A[i] <= B[i]) {
            // If the toy can fit in the existing largest box
            min_x = min(min_x, B[i]);
        } else {
            // Otherwise, we need to buy a new box of size at least A[i]
            min_x = min(min_x, A[i]);
        }
    }
    
    // If we found a valid box size, print it; otherwise, print -1
    cout << (can_store_all ? min_x : -1) << '\n';
    
    return 0;
}