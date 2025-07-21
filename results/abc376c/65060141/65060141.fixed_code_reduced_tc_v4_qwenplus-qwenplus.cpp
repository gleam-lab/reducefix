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

    ll required = -1;
    ll b_ptr = 0;

    for (ll i = 0; i < n; ++i) {
        if (b_ptr < n - 1 && b[b_ptr] >= a[i]) {
            b_ptr++;
        } else {
            // This toy needs to go into the new box
            if (required == -1) {
                required = a[i];
            } else {
                // More than one toy can't fit in existing boxes
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if (required == -1) {
        // All toys fit in existing boxes, but we still need to buy one extra box
        // So we can choose a very small box that doesn't matter
        // Since all toys are placed in other boxes, x can be minimal positive integer
        cout << "1\n";
    } else {
        cout << required << '\n';
    }

    return 0;
}