#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    ll x = -1;
    ll count_unmatched = 0;
    ll i = 0, j = 0;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = A[i];
                count_unmatched++;
                i++;
            } else {
                count_unmatched++;
                i++;
            }
        }
    }
    
    while (i < n) {
        if (x == -1) {
            x = A[i];
            count_unmatched++;
        } else {
            count_unmatched++;
        }
        i++;
    }
    
    if (count_unmatched > 1) {
        cout << -1 << endl;
    } else {
        if (x == -1) {
            // All toys fit in the existing boxes; x can be any value >= 0, but the problem requires x to be positive.
            // But since no toy is left, the smallest x is 1 (as x must be positive).
            cout << 1 << endl;
        } else {
            cout << x << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}