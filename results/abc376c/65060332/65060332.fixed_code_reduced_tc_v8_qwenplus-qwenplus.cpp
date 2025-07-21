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

    ll required_toys = 0;
    ll j = 0; // pointer for boxes

    for (ll i = 0; i < n; ++i) {
        if (j < n - 1 && b[j] >= a[i]) {
            j++;
        } else {
            required_toys++;
        }
    }

    if (required_toys > 1) {
        cout << -1 << endl;
        return 0;
    }

    // If no toy needs the new box
    if (required_toys == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Find the smallest toy that couldn't fit in any box
    j = 0;
    ll min_x = -1;
    for (ll i = 0; i < n; ++i) {
        if (j < n - 1 && b[j] >= a[i]) {
            j++;
        } else {
            min_x = a[i];
            break;
        }
    }

    cout << min_x << endl;
    return 0;
}