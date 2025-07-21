#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=2e5+5;

ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }

    // First, pair each toy with the smallest possible box that can contain it
    for (ll i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            cout << -1 << endl;
            return 0; // This is an error condition because toy doesn't fit in the given boxes
        }
    }

    // We need to find the smallest box size that can accommodate all toys
    // We start by considering the size of the largest toy
    ll min_required_box_size = a[n - 1];

    // We need to ensure that there is at least one box that can hold the largest toy
    // Let's check if there's a box that can hold the largest toy in the given boxes
    ll found = 0;
    for (ll i = 0; i < n - 1; i++) {
        if (b[i] >= a[n - 1]) {
            found = 1;
            break;
        }
    }

    if (!found) {
        // If no box can hold the largest toy, we need to buy a new box of that size
        cout << a[n - 1] << endl;
    } else {
        // If there is a box that can hold the largest toy, we have found our minimum required box size
        cout << min_required_box_size << endl;
    }

    return 0;
}