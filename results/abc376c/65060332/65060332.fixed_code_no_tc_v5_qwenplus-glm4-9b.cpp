#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+5;
ll a[N], b[N];

int main() {
    ll n, cnt = 0, mx = 0;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }
    
    // Sort both arrays to facilitate the matching process
    sort(a, a + n);
    sort(b, b + n);
    
    // Two pointers to traverse the arrays
    for (ll i = 0, j = 0; i < n && j < n - 1; ) {
        // If the current toy size can fit in the current box size
        if (a[i] <= b[j]) {
            i++; // Move to the next toy
        } else {
            // If not, check the next box size
            j++;
            // If no box can fit the current toy, increment the counter for the largest box used
            if (j == n - 1) {
                cnt++;
                j = 0; // Restart checking from the first box
            }
        }
    }
    
    // If more than one additional box is needed, return -1
    if (cnt > 1) {
        cout << -1;
    } else {
        // Otherwise, return the size of the largest box needed
        cout << mx;
    }
    
    return 0;
}