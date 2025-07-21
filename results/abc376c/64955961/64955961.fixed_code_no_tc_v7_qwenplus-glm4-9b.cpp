#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    // Sort the toy sizes and the box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // Initialize the smallest x and its count
    ll min_x = INT_MAX, min_x_count = 0;
    // Iterate to find the minimum x
    for (ll i = 0; i < n; ++i) {
        ll current = a[i];
        ll j = 0;
        bool found = false;
        // Check if current toy can fit in any of the existing boxes
        while (j < n - 1 && current <= b[j]) {
            if (current == b[j]) {
                found = true;
                break;
            }
            j++;
        }
        // If the toy can fit in any of the existing boxes, update x
        if (!found) {
            if (current < min_x) {
                min_x = current;
                min_x_count = 1;
            } else if (current == min_x) {
                min_x_count++;
            }
        }
    }
    // Output the result
    if (min_x_count == 0) {
        cout << -1 << endl;
    } else {
        cout << min_x << endl;
    }
}

int main() {
    solve();
}