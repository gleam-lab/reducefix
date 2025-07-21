#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a, b, k;
vector<ll> ans;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n + 1); b.resize(q + 1); k.resize(q + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 1; i <= q; i++) {
        cin >> b[i] >> k[i];
    }
    for(int i = 1; i <= q; i++) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int idx = it - a.begin();
        if(idx == n) ans.push_back(abs(b[i] - a[n - 1]));
        else if(idx == 0) ans.push_back(abs(b[i] - a[0]));
        else ans.push_back(min(abs(b[i] - a[idx]), abs(b[i] - a[idx - 1])));
    }
    for(auto &x : ans) cout << x << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}