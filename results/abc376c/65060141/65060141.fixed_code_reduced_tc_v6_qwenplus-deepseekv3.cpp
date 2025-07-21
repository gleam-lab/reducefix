#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];
int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    ll j = 0;
    ll cnt = 0;
    ll mx_unplaced = 0;
    for (ll i = 0; i < n; i++) {
        if (j < n - 1 && b[j] >= a[i]) {
            j++;
        } else {
            cnt++;
            mx_unplaced = max(mx_unplaced, a[i]);
        }
    }
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << mx_unplaced << endl;
    }
    return 0;
}