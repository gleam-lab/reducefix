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
ll dp[N][3];

ll exp(int i = 0, int state = 0) {
    if (i == n)
        return 0;

    if (~dp[i][state])
        return dp[i][state];

    ll res = exp(i + 1, 0) + v[i];
    if (state == 0) {
        res = max(res, exp(i + 1, 1) + 2 * v[i]);
    }
    if (state == 1) {
        res = max(res, exp(i + 1, 2) + v[i]);
    }
    return dp[i][state] = res;
}

void solve() {
    cin>>n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<exp();
}

int main() {
    Youssef
    int q = 1;
    //cin>>q;
    while (q--)
        solve();
    return 0;
}