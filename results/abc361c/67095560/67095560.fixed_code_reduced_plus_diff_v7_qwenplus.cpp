#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second 
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    sort(all(a));
    
    // We need to remove exactly K elements
    // The remaining sequence has length = n - k
    // We want to minimize (max - min) of the remaining subsequence
    // Since array is sorted, we can only take contiguous elements from original array
    // So we try all possible contiguous segments of length (n-k)
    
    int len = n - k;
    int ans = a[len-1] - a[0]; // first window
    
    for(int i = 1; i + len - 1 < n; i++) {
        ans = min(ans, a[i + len - 1] - a[i]);
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