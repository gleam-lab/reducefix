#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
    
    vector<ll> unmatched;
    ll i = n - 1, j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            i--;
            j--;
        } else {
            unmatched.push_back(a[i]);
            i--;
        }
    }
    
    while (i >= 0) {
        unmatched.push_back(a[i]);
        i--;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << '\n';
    } else if (unmatched.empty()) {
        cout << 1 << '\n'; // Any x >= 1 would work, but minimal x is 1 (since B_i >= 1)
    } else {
        cout << unmatched[0] << '\n';
    }
    
    return 0;
}