#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize dp arrays to store maximum sums ending at even and odd indices respectively
    vector<ll> dp_e(n, 0), dp_o(n, -1);

    rep(i,n)
    {
        if (i % 2 == 0) { // Current index is even
            dp_e[i] = max(dp_o[i-1] + 2 * a[i], dp_e[i-1]);
            dp_o[i] = dp_o[i-1];
        } else { // Current index is odd
            dp_o[i] = max(dp_e[i-1] + a[i], dp_o[i-1]);
            dp_e[i] = dp_e[i-1];
        }
    }

    // The answer will be the maximum value between the last elements of dp_e and dp_o arrays
    cout << max(dp_e[n-1], dp_o[n-1]) << endl;
}