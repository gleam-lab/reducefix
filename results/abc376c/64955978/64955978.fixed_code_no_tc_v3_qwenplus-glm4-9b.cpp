#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    
    // Reading input for toy sizes (A) and box sizes (B)
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N-1; i++) {
        cin >> B[i];
    }
    
    // Sort toy sizes in descending order and box sizes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    // Initialize the maximum toy size that cannot be placed in any of the given boxes
    ll maxToyNotFitted = 0;
    
    // Iterate over all boxes and fill the toy sizes
    for (ll i = 0; i < N - 1; i++) {
        if (A[i] <= B[i]) {
            // If the current toy can be placed in the current box, move to the next toy and box
            continue;
        } else {
            // Check if the next toy can be placed in the current box
            if (i + 1 < N && A[i + 1] <= B[i]) {
                i++; // Move to the next toy
                continue;
            } else {
                // If neither this toy nor the next toy can be placed in this box
                // Then this box size is too small to fit any toy, and we need to buy a new box
                maxToyNotFitted = A[i];
                break;
            }
        }
    }
    
    // The size of the new box to be bought
    ll newBoxSize = maxToyNotFitted + 1;
    
    // Check if we can place the last remaining toy in any of the previous boxes
    // or in the newly bought box
    for (ll i = 0; i < N - 1; i++) {
        if (A[N - 1] <= B[i]) {
            newBoxSize = min(newBoxSize, B[i]);
            break;
        }
    }
    
    // If newBoxSize is still equal to the original value, it means we cannot place the last toy
    if (newBoxSize == maxToyNotFitted + 1) {
        cout << -1 << endl;
    } else {
        cout << newBoxSize << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}