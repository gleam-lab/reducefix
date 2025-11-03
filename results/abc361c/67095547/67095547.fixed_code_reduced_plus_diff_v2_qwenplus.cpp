#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second 
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define rev(v) reverse(v.begin(),v.end())
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    sort(all(a));
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // First window: [0, keep-1]
    
    // Try all possible windows of size 'keep' in the sorted array
    for(int i = 1; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, a[j] - a[i]);
    }
    
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}