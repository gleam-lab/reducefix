#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, maxExtraSpace = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
        ll spaceNeededForToy = a[i] - b[i];
        maxExtraSpace = max(maxExtraSpace, spaceNeededForToy);
    }
    cout << maxExtraSpace;
    return 0;
}