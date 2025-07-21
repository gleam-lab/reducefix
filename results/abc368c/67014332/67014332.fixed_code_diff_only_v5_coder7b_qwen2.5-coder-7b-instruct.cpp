#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0, tri = 1;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        // Each health can be reduced by either 1 or 3 depending on whether T is a multiple of 3 or not.
        // We calculate the minimum number of operations needed to reduce the health to 0 or below.
        ans += ceil((double)h / 3);
    }
    cout << ans;
}