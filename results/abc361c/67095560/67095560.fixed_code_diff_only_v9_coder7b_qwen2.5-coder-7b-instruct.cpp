#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define vi vector<int>

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = INT_MAX;
    for(int i = 0; i <= k; ++i){
        int j = n - (k - i) - 1;
        ans = min(ans, a[j] - a[i]);
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}