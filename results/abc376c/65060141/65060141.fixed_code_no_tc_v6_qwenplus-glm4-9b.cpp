#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, x;
    cin >> n;
    vector<ll> a(n), b(n-1);
    
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    // Sort the toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // We need to find the minimum size x for the new box
    // such that it can accommodate all toys that cannot be placed in the existing boxes
    vector<ll> remainingToys;
    
    for(ll j = 0; j < n; j++) {
        bool placed = false;
        // Try to place toy j in any of the existing boxes
        for(ll i = 0; i < n - 1; i++) {
            if(b[i] >= a[j]) {
                // If toy j can be placed in box i, move to the next toy
                placed = true;
                break;
            }
        }
        if(!placed) {
            // If toy j cannot be placed in any existing box, it must go in the new box
            remainingToys.push_back(a[j]);
        }
    }
    
    // The size of the new box must be the maximum size needed for the remaining toys
    if(remainingToys.size() == 0) {
        // If all toys are already placed, the new box size is 0 (no new box needed)
        cout << 0;
    } else {
        cout << *max_element(remainingToys.begin(), remainingToys.end());
    }
    
    return 0;
}