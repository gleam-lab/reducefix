#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
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
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);
    
    ll min_x = LLONG_MAX;
    bool all_placed = true;
    for (ll i = 1; i <= n; i++) {
        if (a[i] > b[i - 1]) {
            min_x = min(min_x, a[i]);
        } else {
            all_placed = false;
            break;
        }
    }
    
    if (all_placed) {
        cout << min_x;
    } else {
        cout << -1;
    }
    
    return 0;
}