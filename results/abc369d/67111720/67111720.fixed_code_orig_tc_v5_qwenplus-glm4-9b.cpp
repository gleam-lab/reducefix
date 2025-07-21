#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < n; i++) // Fix the loop increment
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp[2] = {0, -1}; // We don't need two separate variables, we can use an array
    rep(i, n) {
        ll current = (i % 2); // Determine whether the current index is even or odd
        dp[current] = max(dp[current], dp[1 - current] + 2 * a[i]); // Update the dp value for the current index
        dp[1 - current] = max(dp[current], dp[1 - current] + a[i]); // Update the dp value for the previous index
    }

    cout << max(dp[0], dp[1]) << endl; // Final result is the maximum of the last two calculated dp values
}