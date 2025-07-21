#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 2e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Initialize bottom-up DP
    dp[n][0] = dp[n][1] = 0;
    
    for (int i = n-1; i >= 0; i--) {
        // Take the current element with current parity
        dp[i][0] = max(dp[i+1][0], dp[i+1][1] + v[i]);
        dp[i][1] = max(dp[i+1][1], dp[i+1][0] + 2 * v[i]);
    }
    
    cout << max(dp[0][0], dp[0][1]) << endl;
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--)
        solve();
    return 0;
}