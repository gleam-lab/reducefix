#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=2e5+5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a, a + n); // Sort the toy sizes
    ll l = 0, r = n - 1; // Use zero-based indexing
    ll min_size = LLONG_MAX; // To store the minimum box size needed
    
    // Try to fit toys into the existing boxes
    while(l < r) {
        if(b[r] >= a[l]) {
            r--;
        } else {
            min_size = min(min_size, a[l] - 1); // Calculate the minimum box size
            l++;
        }
    }
    
    // If min_size was updated, it means we found a minimum box size needed
    if(min_size == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_size + 1 << endl; // Output the minimum size of the box + 1
    }
    
    return 0;
}