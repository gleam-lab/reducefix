#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

ll exp(int i = 0, bool parity = true) { // Change to 'true' instead of '1'

    if (i == n)
        return 0;

    if (dp[i][parity] != -1) // Check if dp value is already computed
        return dp[i][parity];

    ll take = exp(i + 1, !parity) + (parity ? v[i] : 2 * v[i]); // Correct the ternary operator
    ll leave = exp(i + 1, parity);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    cin >> n;
    v.resize(n); // Resize vector to n elements
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << exp() << "\n"; // Print result with newline
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--)
        solve();
    return 0;
}