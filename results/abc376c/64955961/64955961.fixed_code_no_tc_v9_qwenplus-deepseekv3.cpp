#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n-1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> unmatched;
    ll i = 0, j = 0;
    while (i < n && j < n-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            unmatched.push_back(a[i]);
            i++;
        }
    }
    while (i < n) {
        unmatched.push_back(a[i]);
        i++;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else if (unmatched.empty()) {
        // All toys can be placed in existing boxes; x can be any value, but the smallest possible is 1
        cout << 1 << endl;
    } else {
        cout << unmatched[0] << endl;
    }
}

int main() {
    solve();
    return 0;
}