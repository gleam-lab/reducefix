#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize dp arrays to handle even and odd indices separately
    vector<ll> dp_e(n), dp_o(n);

    // Base case: first element can only be included if it's at an even index
    dp_e[0] = 0;
    dp_o[0] = a[0];

    rep(i, n)
    {
        // Update dp arrays based on whether we include the current element or not
        if (i % 2 == 0)
        {
            dp_e[i] = max(dp_o[i-1] + 2 * a[i], dp_e[i-1]);
            dp_o[i] = dp_o[i-1];
        }
        else
        {
            dp_o[i] = max(dp_e[i-1] + a[i], dp_o[i-1]);
            dp_e[i] = dp_e[i-1];
        }
    }

    // The result is the maximum of the last elements of both dp arrays
    cout << max(dp_e[n-1], dp_o[n-1]) << endl;
}