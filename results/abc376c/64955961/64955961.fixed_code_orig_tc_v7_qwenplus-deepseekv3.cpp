#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> possible_x;
    
    // Try to match a[0..n-2] with b[0..n-2]
    bool possible = true;
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(a.back());
    }
    
    // Try to match a[1..n-1] with b[0..n-2]
    possible = true;
    for (ll i = 1; i < n; ++i) {
        if (a[i] > b[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(a[0]);
    }
    
    // Try to match all except one a[i] in b, and the remaining in x
    ll count = 0;
    ll candidate = -1;
    ll j = 0;
    for (ll i = 0; i < n && j < n - 1; ) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            candidate = a[i];
            count++;
            i++;
        }
    }
    if (count == 1) {
        possible_x.push_back(candidate);
    } else if (count == 0) {
        possible_x.push_back(a.back());
    }
    
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        ll min_x = *min_element(possible_x.begin(), possible_x.end());
        cout << min_x << endl;
    }
}

int main() {
    solve();
    return 0;
}