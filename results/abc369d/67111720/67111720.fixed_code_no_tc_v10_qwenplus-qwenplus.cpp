#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // dp_even: max sum ending at i with even number of elements
    // dp_odd: max sum ending at i with odd number of elements
    ll dp_even = 0, dp_odd = -1, temp;

    rep(i, n)
    {
        temp = dp_even;
        dp_even = max(dp_even, dp_odd + 2 * a[i]); // Add current element as even index (2nd, 4th, etc.)
        dp_odd = max(dp_odd, temp + a[i]);         // Add current element as odd index (1st, 3rd, etc.)
    }

    cout << max(dp_even, dp_odd) << endl;
}