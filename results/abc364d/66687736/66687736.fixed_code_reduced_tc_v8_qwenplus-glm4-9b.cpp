#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    for (ll i = 0; i < q; ++i) {
        ll b, k; cin >> b >> k;
        // Find the k-th closest A to B
        // This is done by sorting the distances and picking the k-th element
        vector<pair<ll, ll>> distances;
        for (ll j = 0; j < n; ++j) {
            distances.emplace_back(abs(a[j] - b), j);
        }
        sort(distances.begin(), distances.end());
        
        // Output the distance of the k-th closest point
        cout << abs(a[distances[k-1].second] - b) << endl;
    }

    return 0;
}