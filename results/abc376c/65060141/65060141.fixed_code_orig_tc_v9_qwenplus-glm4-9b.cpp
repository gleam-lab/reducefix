#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    set<ll> possible_sizes;
    
    ll a[n], b[n-1];

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        // For each toy size, consider all possible box sizes up to that toy size
        for (ll size = 1; size <= a[i]; ++size) {
            possible_sizes.insert(size);
        }
    }

    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
        possible_sizes.insert(b[i]);
    }

    // Output the smallest possible box size that can accommodate the smallest toy
    for (ll size : possible_sizes) {
        cout << size << endl;
        return 0;
    }

    // If no such box size exists, return -1
    cout << -1 << endl;
    return 0;
}