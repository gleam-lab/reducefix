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
    
    // Sort the array to easily find min and max after removals
    sort(all(a));
    
    // We need to remove exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int ans = inf;
    
    // Try all possible contiguous segments of length 'keep'
    // We can only take contiguous elements in sorted order to minimize the range
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, a[j] - a[i]);
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