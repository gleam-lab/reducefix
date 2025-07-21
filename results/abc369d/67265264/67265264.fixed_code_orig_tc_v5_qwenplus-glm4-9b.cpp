#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;
int n;
vector<ll>v;
ll dp[N][2];

ll exp(int i = 0, bool parity = 1) {

    if (i == n)
        return 0;  // Base case: if we've processed all elements, return 0

    if (~dp[i][parity])  // Check if the result is already computed
        return dp[i][parity];

    ll take = exp(i + 1, !parity) + (parity ? v[i] : 2 * v[i]);  // Choose the current element
    ll leave = exp(i + 1, parity);  // Do not choose the current element

    return dp[i][parity] = max(take, leave);  // Store and return the maximum of taking or not taking
}

void solve() {
    cin>>n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);  // Initialize dp array with -1 for memoization
    cout << exp(0, 1) << endl;  // Call exp with initial parameters
}

int main() {
    Youssef
    int q = 1;
    //cin>>q;
    while (q--)
        solve();
    return 0;
}