#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        K -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> C(n, -1);
    for (ll i = 0; i < n; ++i) {
        ll votes_needed = -1;
        if (i + m < n) {
            ll lower_bound = a[n - m - 1] + 1;
            if (lower_bound > a[i]) {
                votes_needed = lower_bound - a[i] - 1;
            }
        }
        C[i] = max(C[i], votes_needed);
    }

    for (ll i = 0; i < n; ++i) {
        if (C[i] != -1 && a[i] + C[i] >= a[n - m] + 1) {
            C[i] = 0;
        }
    }

    for (ll i = 0; i < n; ++i) {
        if (C[i] == -1 && a[i] >= a[n - m] + 1) {
            C[i] = 0;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}