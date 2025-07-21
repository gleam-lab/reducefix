#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define vi vector<int>
#define vl vector<ll>

ll get(vl &a, ll b, ll e, ll x) {
    while (b <= e) {
        ll mid = (b + e) / 2;
        if (a[mid] <= x) b = mid + 1;
        else e = mid - 1;
    }
    return b;
}

int main() {
    ll n, q; cin >> n >> q;
    vl a(n), b(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> b[i][0] >> b[i][1];

    // Prepare the sorted array of points A
    sort(a.begin(), a.end());

    // Process each query
    for (ll i = 0; i < q; i++) {
        ll b_j = b[i][0];
        ll k_j = b[i][1];

        // Find the k-th closest point A_i to B_j
        ll pos = get(a, 0, n - 1, b_j - a[0]);
        cout << abs(a[pos] - b_j) << endl;
    }
}