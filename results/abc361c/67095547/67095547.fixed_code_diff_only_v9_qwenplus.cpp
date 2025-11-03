#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second 
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The optimal way is to remove some prefix and suffix elements.
    // Try all possible splits: remove i from left and (k-i) from right.
    int ans = inf;
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        int j = n - 1 - right_removed;
        if (j >= left_removed) {
            ans = min(ans, a[j] - a[left_removed]);
        }
    }
    
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}