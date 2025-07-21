#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for (ll i = 0; i < N; i++) cin >> a[i];
    for (ll i = 0; i < N-1; i++) cin >> b[i];
    
    // Find the largest box size among b array
    ll max_b = *max_element(b.begin(), b.end());
    
    // Find the largest toy size
    ll max_a = *max_element(a.begin(), a.end());
    
    // If the largest toy size is greater than the largest box, we need a box of at least size `max_a + 1`
    if (max_a > max_b) {
        cout << max_a + 1 << endl;
    } else {
        // Otherwise, we need to check if all toys can be placed in the existing boxes
        sort(b.begin(), b.end());
        sort(a.begin(), a.end(), greater<ll>());
        bool canPlace = true;
        for (ll i = 0; i < N; i++) {
            if (a[i] > b[i]) {
                canPlace = false;
                break;
            }
        }
        if (canPlace) {
            cout << -1 << endl; // All toys can be placed in existing boxes
        } else {
            cout << max_a + 1 << endl; // We need a box of at least size `max_a + 1`
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}