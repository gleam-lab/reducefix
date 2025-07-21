#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // dp_even: maximum sum ending at i with even number of elements
    // dp_odd:  maximum sum ending at i with odd number of elements
    ll dp_even = 0, dp_odd = 0;
    ll max_even = 0, max_odd = 0;

    rep(i, n)
    {
        // If current element is the end of a subsequence
        // For odd length: previous was even + current
        dp_odd = max(dp_odd, dp_even + a[i]);
        // For even length: previous was odd + current
        dp_even = max(dp_even, dp_odd + a[i]);

        // Update global max values
        max_even = max(max_even, dp_even);
        max_odd = max(max_odd, dp_odd);
    }

    cout << max(max_even, max_odd) << endl;
}