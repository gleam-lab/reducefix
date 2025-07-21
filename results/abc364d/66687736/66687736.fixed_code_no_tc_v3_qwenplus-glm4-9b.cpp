#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>

ll mod = 1000000007;

ll add_mod(ll x, ll y) {
    return (x + y) % mod;
}

ll mul_mod(ll x, ll y) {
    return (x * y) % mod;
}

ll pow_mod(ll x, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = mul_mod(res, x);
        x = mul_mod(x, x);
        k >>= 1;
    }
    return res;
}

ll ncr_mod(ll n, ll r) {
    if (r > n) return 0;
    ll numerator = 1;
    ll denominator = 1;
    for (ll i = 0; i < r; ++i) {
        numerator = mul_mod(numerator, n - i);
        denominator = mul_mod(denominator, i + 1);
    }
    return mul_mod(numerator, pow_mod(denominator, mod - 2));
}

ll find_distance(ll x, ll b) {
    // Using binary search to find the k-th closest distance
    ll low = -1e10, high = 1e10;
    while (high - low > 1) {
        ll mid = low + (high - low) / 2;
        if (abs(x - b) == mid) return mid;
        else if (abs(x - b) > mid) high = mid;
        else low = mid;
    }
    return abs(x - b);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vl a(n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());

    for (ll i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        ll answer = LLONG_MAX;
        for (ll j = 0; j < n; ++j) {
            ll distance = find_distance(a[j], b);
            if (distance <= k) {
                answer = min(answer, distance);
            } else {
                // If the distance is greater than k, no need to check further points
                break;
            }
        }
        cout << answer << endl;
    }
    return 0;
}