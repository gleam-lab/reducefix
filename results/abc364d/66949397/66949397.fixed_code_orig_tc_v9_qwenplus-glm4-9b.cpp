#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<pair<ll, ll>> distances;

    // Calculate distances and store them as pairs (distance, index)
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < q; ++j) {
            ll b, k;
            cin >> b >> k;
            distances.emplace_back(abs(a[i] - b), i);
        }
    }

    // Sort distances by the first element of the pair, which is the distance
    sort(distances.begin(), distances.end());

    for (ll j = 0; j < q; ++j) {
        // We need to find the k_j-th closest to B_j, which is the k_j-th element in the sorted distances
        // We need to find the (k_j-1)-th element in the sorted distances because arrays are 0-indexed
        cout << distances[k(j, q)].second << "\n";
    }

    return 0;
}

// Function to compute k_j as 0-indexed for 1-indexed input
ll k(ll j, ll q) {
    return j - 1;
}