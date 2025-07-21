#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

ll exp(int i, bool parity) {
    if (i == n) return 0; // Base case: no more elements to consider
    if (dp[i][parity] != -1) return dp[i][parity]; // Return if already computed

    ll take, leave;

    // Calculate the maximum of taking or not taking the current element
    take = parity ? v[i] : 2 * v[i] + exp(i + 1, !parity);
    leave = exp(i + 1, parity);

    dp[i][parity] = max(take, leave); // Memoize the result
    return dp[i][parity];
}

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp); // Initialize dp array with -1
    cout << exp(0, true) << '\n'; // Start the recursion with the first element and parity true
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}