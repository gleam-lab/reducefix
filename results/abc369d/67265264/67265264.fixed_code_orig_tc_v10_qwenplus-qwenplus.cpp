#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 200005; // Slightly more than 2e5 to avoid issues
int n;
vector<ll> v;
ll dp[N][2];

// Memoization-based DP with correct parity handling and value computation
ll solve(int i, bool even_parity) {
    if (i == n) return 0;

    ll &res = dp[i][even_parity];
    if (res != -1) return res;

    ll take, not_take;

    if (even_parity) {
        // Current index is part of an even position in the chosen subsequence
        take = v[i] + solve(i + 1, false);
    } else {
        // Current index is odd in the selected subsequence: double the value
        take = 2 * v[i] + solve(i + 1, true);
    }

    not_take = solve(i + 1, even_parity);

    return res = max(take, not_take);
}

void run_case() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof dp);
    // Start by considering both options:
    // Either start taking at index 0 with even parity (odd index in 1-based)
    // or skip it. We want maximum result starting from index 0.
    cout << solve(0, true) << "\n";
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--) {
        run_case();
    }
    return 0;
}