#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
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
    } else if (unmatched.size() == 1) {
        cout << unmatched.back() << endl;
    } else {
        // All toys are matched, but we need to buy a box for the last toy
        // Actually, if all are matched, then N toys are matched to N-1 boxes, which is impossible.
        // So this case shouldn't occur unless input is invalid, but problem states N >= 2.
        // So, this means all N-1 toys are matched, and one remains, which is a[n-1]
        cout << a.back() << endl;
    }
}

int main() {
    solve();
    return 0;
}