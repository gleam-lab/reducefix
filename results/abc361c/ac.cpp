#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int n,k;
vector<int> a;

void solve() {
    cin >> n >> k;
    a.resize(n); rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 1e9;
    rep(i,k+1) {
        ans = min(ans, a[n-k+i-1]-a[i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
