#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, x = LLONG_MAX;
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Sort the toy sizes and box sizes
    sort(a, a + n);
    sort(b, b + n - 1);

    // Find the smallest box size that can be used for the largest toys
    for(ll i = n - 1; i >= 0; --i) {
        if (a[i] <= b[i]) {
            x = min(x, b[i]);
        } else {
            break;
        }
    }

    // If x is still LLONG_MAX, it means no box can be used for the largest toy
    if (x == LLONG_MAX) {
        cout << -1;
    } else {
        cout << x;
    }
    return 0;
}