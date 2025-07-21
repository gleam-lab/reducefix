#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Set the maximum box size that can be used to the size of the smallest toy
    ll minToySize = *min_element(a, a + n);
    ll maxBoxSize = *max_element(b, b + n - 1);

    // If the smallest toy is larger than the largest box Takahashi already has, print -1
    if (minToySize > maxBoxSize) {
        cout << -1 << endl;
        return 0;
    }

    // Find the minimum box size x that is at least as large as the smallest toy
    ll x = minToySize;
    for (ll i = 0; i < n - 1; i++) {
        if (b[i] >= x) {
            x = b[i];
        } else {
            break;
        }
    }

    cout << x << endl;
    return 0;
}