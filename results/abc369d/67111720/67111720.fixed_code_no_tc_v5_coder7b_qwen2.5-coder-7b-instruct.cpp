#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i < (n); i++)
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp[2][2] = {{0, -1}, {0, -1}}; // Initialize DP array for even and odd indexed monsters
    ll temp;

    rep(i,n)
    {
        temp = dp[(i & 1)][0]; // Store previous state of current index parity
        dp[(i & 1)][0] = max(dp[(i ^ 1)][1] + 2 * a[i], dp[(i & 1)][0]); // Update for even-indexed monsters
        dp[(i & 1)][1] = max(temp + a[i], dp[(i & 1)][1]); // Update for odd-indexed monsters
    }

    cout << max(dp[(n-1) & 1][0], dp[(n-1) & 1][1]) << endl; // Output maximum experience points
}