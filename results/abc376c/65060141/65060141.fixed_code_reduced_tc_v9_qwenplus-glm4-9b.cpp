#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n, ans = -1;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    // Initialize the minimum size of the box needed as infinity
    ll min_box_size = LLONG_MAX;
    
    // Iterate over all boxes
    for(int i = 0; i < n - 1; i++) {
        // Iterate over all toys
        for(int j = 0; j < n; j++) {
            // Check if the current toy can fit in the current box
            if(b[i] >= a[j]) {
                // Check if this box can be the minimum box size so far
                min_box_size = min(min_box_size, b[i]);
            } else {
                // If the current toy cannot fit in this box, it needs to be placed in a larger box
                // or in the newly bought box. Update the answer to be the maximum of the current answer
                // or the size of the toy plus one (since the toy needs at least one more box size).
                ans = max(ans, a[j] + 1);
                break; // No need to check larger toys for this box since they will only be larger
            }
        }
    }
    
    // Iterate over all toys to check the last box
    for(ll i = 0; i < n; i++) {
        if(a[i] <= min_box_size) {
            ans = max(ans, min_box_size);
        } else {
            ans = max(ans, a[i] + 1);
        }
    }
    
    // If no valid answer was found, set it to -1
    if(ans == LLONG_MAX) {
        ans = -1;
    }
    
    cout << ans;
    return 0;
}