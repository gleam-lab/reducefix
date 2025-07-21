#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
    }

    // To keep track of the toys that cannot be placed in the existing boxes
    vector<ll> cannotPlace(n);
    ll countCannotPlace = 0;
    for (ll i = 1; i <= n; ++i) {
        bool placed = false;
        for (ll j = 0; j < countCannotPlace; ++j) {
            if (b[b[j]] >= a[i]) {
                b[b[j]] = 0; // Mark as placed
                placed = true;
                break;
            }
        }
        if (!placed) {
            cannotPlace[countCannotPlace++] = i;
            b[countCannotPlace] = a[i]; // Place the toy in a new box with the same size
        }
    }

    // If there are multiple toys that cannot be placed in any box, output -1
    if (countCannotPlace > 1) {
        cout << -1 << endl;
        return 0;
    }

    // The minimum x is the size of the box that the last unplaceable toy (if any) would need
    if (countCannotPlace == 1 && cannotPlace[0] != -1) {
        cout << a[cannotPlace[0]] << endl;
    } else {
        // Find the minimum size of a box that the largest unplaceable toy would need
        ll minX = LLONG_MAX;
        for (ll i = 1; i <= n; ++i) {
            if (b[i] > minX) {
                minX = b[i];
            }
        }
        cout << minX << endl;
    }

    return 0;
}