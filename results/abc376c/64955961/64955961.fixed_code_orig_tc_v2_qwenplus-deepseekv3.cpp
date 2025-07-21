#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> candidates;
    for (ll k = 0; k < 2; k++) {
        bool possible = true;
        ll x = -1;
        ll i = n - 1;
        ll j = n - 2;
        ll unmatched = 0;
        while (i >= 0 && j >= 0) {
            if (a[i] <= b[j]) {
                i--;
                j--;
            } else {
                if (x == -1) {
                    x = a[i];
                    i--;
                    unmatched++;
                } else {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            while (i >= 0) {
                if (x == -1) {
                    x = a[i];
                    i--;
                    unmatched++;
                } else {
                    possible = false;
                    break;
                }
            }
            if (possible && unmatched <= 1) {
                candidates.push_back(x);
            }
        }
        // Swap the roles of a and b (rotate the problem)
        swap(a, b);
        a.resize(n);
        b.resize(n - 1);
    }
    
    if (!candidates.empty()) {
        ll min_x = *min_element(candidates.begin(), candidates.end());
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}