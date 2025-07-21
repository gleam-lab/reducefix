#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    // We need to find the minimum possible size of the new box
    // to be able to place all toys in existing and one new box.
    // This is equivalent to finding the smallest box size x such that
    // all toys can fit in boxes of size <= x.
    
    // First, let's find the maximum size required by any toy.
    ll maxToySize = *max_element(a.begin(), a.end());
    
    // Since a[i] can be larger than all b[j], we need to consider
    // the possibility that we might need an extra box larger than any b[j].
    // We can use the binary search to find the minimum x.
    ll low = 1;
    ll high = maxToySize + 1;
    
    while (low < high) {
        ll mid = (low + high) / 2;
        bool possible = true;
        
        // Check if we can place all toys in boxes of size <= mid.
        for (ll i = 0; i < n; i++) {
            bool placed = false;
            for (ll j = 0; j < n - 1; j++) {
                if (b[j] >= a[i]) {
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                // If toy i cannot be placed in any of the existing boxes,
                // we need to check the size mid.
                if (mid < a[i]) {
                    possible = false;
                    break;
                }
            }
        }
        
        // Adjust binary search bounds
        if (possible) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    // low should now be the smallest possible size of the new box required.
    cout << (low > maxToySize ? low : -1) << endl;
}

int main()
{
    solve();
    return 0;
}