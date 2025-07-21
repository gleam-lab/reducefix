#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    ll required = 0;
    ll j = 0;

    for (ll i = 0; i < n; ++i) {
        if (j < n - 1 && b[j] >= a[i]) {
            ++j;
        } else {
            // This toy needs our purchased box
            if (required == 0) {
                required = a[i];
            } else {
                // More than one toy can't be placed in the available boxes
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    if (required == 0) {
        // All toys fit in existing boxes, so we can purchase any box (minimum x = 1)
        cout << 1 << "\n";
    } else {
        cout << required << "\n";
    }

    return 0;
}