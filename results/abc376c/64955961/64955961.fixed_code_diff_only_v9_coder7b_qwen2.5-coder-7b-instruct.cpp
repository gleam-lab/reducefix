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

    // Sort the arrays to facilitate the matching process
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    ll min_box_size = 0;
    bool possible = true;

    // Iterate through the toys and try to place them in boxes
    for (ll i = 0; i < n; ++i) {
        if (i < n - 1 && a[i] <= b[i]) {
            // If the toy fits in the current box, move to the next toy
            continue;
        } else {
            // If the toy does not fit in the current box, we need a new box
            if (min_box_size == 0 || a[i] > min_box_size) {
                min_box_size = a[i];
            } else {
                possible = false;
                break;
            }
        }
    }

    // Output the result
    if (possible) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    solve();
}