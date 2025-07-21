#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+5;
ll a[N], b[N];
int main() {
    ll n, maxToy = 0, minBoxSize = LLONG_MAX;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        maxToy = max(maxToy, a[i]);
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
        minBoxSize = min(minBoxSize, b[i]);
    }
    
    if (maxToy >= minBoxSize) {
        cout << -1 << endl; // No need for an extra box if the largest toy fits the smallest box
    } else {
        cout << minBoxSize << endl; // The minimum box size needed to fit the largest toy that cannot fit in the smallest existing box
    }
    return 0;
}