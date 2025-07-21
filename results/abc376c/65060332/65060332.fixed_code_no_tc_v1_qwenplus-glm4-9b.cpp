#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[200005], b[200004];

int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];

    // Sort both arrays, but b must be sorted in descending order to simulate the process of filling boxes from the largest available
    sort(a, a + n);
    sort(b, b + n - 1, greater<ll>());

    ll i = 0, j = 0;
    // We need to find the smallest box size x that can accommodate all toys
    while (i < n && j < n - 1) {
        // If the current toy can fit in the current box, move to the next toy
        if (b[j] >= a[i]) {
            j++;
        } else {
            // Otherwise, move to the next box
            i++;
            // Since the boxes are sorted in descending order, the next box's size is guaranteed to be larger
            // and will be at least the size of the toy that couldn't fit in the previous box
            if (i == j) {
                cout << a[i];
                return 0;
            }
        }
    }
    // If we have still not found a box that can accommodate all toys, output -1
    cout << -1;
    return 0;
}