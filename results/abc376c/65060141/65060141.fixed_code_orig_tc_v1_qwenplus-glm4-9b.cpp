#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, maxToy = 0, minBoxSize = LLONG_MAX, smallestX = -1;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        maxToy = max(maxToy, a[i]);
    }
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
        minBoxSize = min(minBoxSize, b[i]);
    }

    // After buying a new box of size `x`, the size of the box should be `minBoxSize + 1`
    smallestX = minBoxSize + 1;
    
    // Check if we can fit all toys into the existing boxes and the new box
    bool possible = true;
    for (ll i = 1; i <= n; ++i) {
        if (a[i] > b[i - 1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << smallestX << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}