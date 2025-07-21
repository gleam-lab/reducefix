#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll mismatches = 0;
    ll required_x = 0;
    ll i = n - 1, j = n - 2;
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            i--;
            j--;
        } else {
            mismatches++;
            required_x = a[i];
            i--;
        }
    }
    while (i >= 0) {
        mismatches++;
        required_x = a[i];
        i--;
    }
    
    if (mismatches > 1) {
        cout << -1 << endl;
    } else {
        if (mismatches == 0) {
            // All toys fit into existing boxes; the new box can be any size >= the smallest toy not covered
            // But since all toys are covered, the new box must be at least the smallest A_i not covered, but all are covered.
            // So the smallest possible x is 1 (but must be >= the remaining toy if any).
            // However, since all N toys are placed into N boxes (N-1 existing + 1 new), but all N-1 boxes are used.
            // So one toy must go into the new box. Hence the new box's size must be >= that toy's size.
            // But in this case, after sorting, if all a[i] <= b[j], then one toy is left to be placed in new box.
            required_x = a[0]; // The smallest toy, but actually, the remaining toy could be any.
            // But in the case where mismatches is 0, after pairing, there's one toy left.
            // So the new box must be at least that toy's size.
            if (n == 1) {
                required_x = a[0];
            } else {
                // After pairing (n-1) toys, the last toy is a[0], and the new box must be >= a[0].
                required_x = a[0];
            }
        }
        cout << required_x << endl;
    }
}

int main() {
    solve();
    return 0;
}